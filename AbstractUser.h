#ifndef ABSTRACTUSER_H
#define ABSTRACTUSER_H

#include <string>
using namespace std;

class ChatRoom;
class Command;

class AbstractUser {

public:
	virtual ~AbstractUser() {}; 

	virtual void send(string message, ChatRoom* room) = 0;
	virtual void broadcast(string message) = 0;

	virtual void receive(string message, AbstractUser* fromUser, ChatRoom* room) = 0;

	virtual void addCommand(Command* command) = 0;

	virtual void executeAll() = 0;

	virtual void addChatRoom(ChatRoom* room) = 0;
	virtual void removeChatRoom(ChatRoom* room) = 0;

	virtual string print() = 0;
};

#endif

