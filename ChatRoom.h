#ifndef CHATROOM_H
#define CHATROOM_H

#include "Collection.h"
#include "Iterator.h"
#include "VectorIterator.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class AbstractUser;

class ChatRoom : public Collection {

private:
	vector<AbstractUser*> users;
	vector<string*> chatHistory;

public:
	virtual ~ChatRoom(); 


	virtual void registerUser(AbstractUser* user);

	virtual void sendMessage(string message, AbstractUser* fromUser);

	virtual void saveMessage(string message, AbstractUser* fromUser);

	virtual void removeUser(AbstractUser* user);

	Iterator<AbstractUser*>* createUserIterator();

	Iterator<string*>* createMessageIterator();

	bool isEmpty();
	virtual string print() { return "ChatRoom"; }
};


#endif
