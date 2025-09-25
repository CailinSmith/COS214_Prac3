#ifndef USER_H
#define USER_H

#include "AbstractUser.h"
#include "ChatRoom.h"
#include "Command.h"
#include "SendMessageCommand.h"
#include "LogMessageCommand.h"
#include "BroadcastCommand.h"
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
	void broadcast(string message);

	void receive(string message, AbstractUser* fromUser, ChatRoom* room);

	void addCommand(Command* command);

	void executeAll();

	void addChatRoom(ChatRoom* room);
	void removeChatRoom(ChatRoom* room);

	const vector<ChatRoom*>& getChatRooms() const { return chatRooms; }

	string print();
	AbstractUser *removeDecorator() { return this;}
	
};

class Alice : public User {
public:
Alice() { name = "Alice"; }
string print() { return name; }
};

class Bob : public User {
public:
Bob() { name = "Bob"; }
string print() { return name; }
};

class Charlie : public User {
public:
Charlie() { name = "Charlie"; }
string print() { return name; }
};


#endif
