#ifndef CHATROOM_H
#define CHATROOM_H

#include "AbstractUser.h"
#include "Collection.h"
#include "Iterator.h"
#include "VectorIterator.h"
#include <vector>
#include <string>
using namespace std;

class ChatRoom : public Collection {

private:
	vector<AbstractUser*> users;
	vector<string*> chatHistory;

public:
	virtual void registerUser(AbstractUser* user);

	virtual void sendMessage(string message, AbstractUser* fromUser);

	virtual void saveMessage(string message, AbstractUser* fromUser);

	virtual void removeUser(AbstractUser* user);

	Iterator<AbstractUser*>* createUserIterator() override;

	Iterator<string*>* createMessageIterator() override;

	bool isEmpty() override;
};


#endif
