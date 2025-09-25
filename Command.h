#ifndef COMMAND_H
#define COMMAND_H

#include <string>
using namespace std;

class ChatRoom;
class AbstractUser;

class Command {

protected:
	ChatRoom* room;
	string message;
	AbstractUser* fromUser;

public:
	Command(AbstractUser* fromUser, string message, ChatRoom* room) {
		this->fromUser = fromUser;
		this->message = message;
		this->room = room;
	}
	
	virtual ~Command() = default; 
	
	virtual void execute() = 0;
};

#endif
