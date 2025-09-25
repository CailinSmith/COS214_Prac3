#include "User.h"


void User::send(string message, ChatRoom* room) {
	string name = print();
	message = name + ": " + message;

	Command* sendCommand = new SendMessageCommand(this, message, room);
	Command* logCommand = new LogMessageCommand(this, message, room);
	addCommand(sendCommand);
	addCommand(logCommand);
}

void User::receive(string message, AbstractUser* fromUser, ChatRoom* room) {
	string fromName = fromUser->print();
	cout << "Message in room " << room->print() << " room" << ": " << message << endl;
}

void User::addCommand(Command* command) {
	commandQueue.push_back(command);
}

void User::executeAll() {
	for (Command* command : commandQueue) {
		command->execute();
	}

}

}

string User::print() {
	// TODO - implement User::print
	throw "Not yet implemented";
}
