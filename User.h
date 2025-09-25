#ifndef USER_H
#define USER_H

#include "AbstractUser.h"

class User : AbstractUser {

protected:
	vector<ChatRoom*> chatRooms;
	string name;
	vector<Command*> commandQueue;

public:
	void send(string message, ChatRoom* room);

	void receive(string message, AbstractUser* fromUser, ChatRoom* room);

	void addCommand(Command* command);

	void executeAll();

	void addChatRoom(ChatRoom* room);
	void removeChatRoom(ChatRoom* room);

	string print();
};

class Name1 : public User {
};

class Name2 : public User {
};

class Name3 : public User {
};

#endif
