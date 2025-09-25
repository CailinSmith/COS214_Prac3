#include "ChatRoom.h"

Iterator<AbstractUser*>* ChatRoom::createUserIterator() {
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
