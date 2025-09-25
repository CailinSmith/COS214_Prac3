#ifndef COMMAND_H
#define COMMAND_H

#include "ChatRoom.h"
#include "AbstractUser.h"
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
	virtual void execute() = 0;
};

#endif
