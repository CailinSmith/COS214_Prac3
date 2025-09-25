#ifndef ABSTRACTUSER_H
#define ABSTRACTUSER_H

#include "AbstractUser.h"
#include "ChatRoom.h"
#include "Command.h"
#include "SendMessageCommand.h"
#include "LogMessageCommand.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class AbstractUser {


public:
	virtual void send(string message, ChatRoom room) = 0;

	virtual void receive(string message, AbstractUser* fromUser, ChatRoom* room) = 0;

	virtual void addCommand(Command* command) = 0;

	virtual void executeAll() = 0;

	virtual string print() = 0;
};

#endif
