#include "User.h"

User::~User() {
	for (Command* command : commandQueue) {
		delete command;
	}
	commandQueue.clear();
}

void User::send(string message, ChatRoom* room) {
	// string name = print();
	// message = name + ": " + message;

	Command* sendCommand = new SendMessageCommand(this, message, room);
	Command* logCommand = new LogMessageCommand(this, message, room);
	addCommand(sendCommand);
	addCommand(logCommand);
}

void User::broadcast(string message) {
	Command* broadcastCommand = new BroadcastCommand(this, message);
	addCommand(broadcastCommand);
}

void User::receive(string message, AbstractUser* fromUser, ChatRoom* room) {
	string fromName = fromUser->print();
	cout << this->print() << " reports: Message from " << fromName << " in room " << room->print() << ": \n" << message << endl;
}

void User::addCommand(Command* command) {
	commandQueue.push_back(command);
}

void User::executeAll() {
	for (Command* command : commandQueue) {
		command->execute();
		delete command;
	}
	commandQueue.clear(); 
}

void User::addChatRoom(ChatRoom *room)
{
	chatRooms.push_back(room);
	room->registerUser(this);
}

void User::removeChatRoom(ChatRoom *room)
{//maybe use iterator here?
	for (auto it = chatRooms.begin(); it != chatRooms.end(); ++it) {
		if (*it == room) {
			chatRooms.erase(it);
			break;
		}
	}
	room->removeUser(this);
}

string User::print() {
	return name; //temporary
}
