#include "ChatRoom.h"
#include "AbstractUser.h"
#include <iostream>

ChatRoom::~ChatRoom() {
	for (string* message : chatHistory) {
		delete message;
	}
	chatHistory.clear();
}

void ChatRoom::registerUser(AbstractUser *user)
{
	users.push_back(user);
	std::cout << user->print() << " has been registered to " << this->print() << " room." << std::endl;
}

void ChatRoom::sendMessage(string message, AbstractUser *fromUser)
{
	for (AbstractUser* user : users) {
		if (user != fromUser) { 
			user->receive(message, fromUser, this);
		}
	}
}

void ChatRoom::saveMessage(string message, AbstractUser *fromUser)
{
	chatHistory.push_back(new string(fromUser->print() + ": " + message));
}

void ChatRoom::removeUser(AbstractUser *user)
{
	for (auto it = users.begin(); it != users.end(); ++it) {
		if (*it == user) {
			users.erase(it);
			break;
		}
	}
	std::cout << user->print() << " has been removed from " << this->print() << " room." << std::endl;
}

Iterator<AbstractUser*> *ChatRoom::createUserIterator()
{
    return new VectorIterator<AbstractUser*>(users);
}

Iterator<string*>* ChatRoom::createMessageIterator() {
    return new VectorIterator<string*>(chatHistory);
}

bool ChatRoom::isEmpty() {
	return users.empty() && chatHistory.empty();
}
