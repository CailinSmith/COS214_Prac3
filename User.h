#ifndef USER_H
#define USER_H

#include "AbstractUser.h"
#include "ChatRoom.h"
#include "Command.h"
#include "SendMessageCommand.h"
#include "LogMessageCommand.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class User : public AbstractUser {

protected:
	vector<ChatRoom*> chatRooms;
	string name;
	vector<Command*> commandQueue;

public:
	~User(); 
	void send(string message, ChatRoom* room);

	void receive(string message, AbstractUser* fromUser, ChatRoom* room);

	void addCommand(Command* command);

	void executeAll();

	void addChatRoom(ChatRoom* room);
	void removeChatRoom(ChatRoom* room);

	string print();
};

class Name1 : public User {
public:
	Name1() { name = "Name1"; }
	string print() { return name; }
};

class Name2 : public User {
public:
	Name2() { name = "Name2"; }
	string print() { return name; }
};

class Name3 : public User {
public:
	Name3() { name = "Name3"; }
	string print() { return name; }
};

#endif
