#include "ChatRoom.h"

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
	chatHistory.push_back(new string(message)); //check if the message already contains users name
}


Iterator<AbstractUser *> *ChatRoom::createUserIterator()
{
    return new VectorIterator<AbstractUser*>(users);
}

Iterator<string*>* ChatRoom::createMessageIterator() {
    return new VectorIterator<string*>(chatHistory);
}

bool ChatRoom::isEmpty() {
	// TODO - implement ChatRoom::isEmpty
	//could check if both users and chatHistory are empty?
	throw "Not yet implemented";
}
