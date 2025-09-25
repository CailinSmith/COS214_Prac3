#ifndef LOGMESSAGECOMMAND_H
#define LOGMESSAGECOMMAND_H

#include "Command.h"
#include "AbstractUser.h"
#include "ChatRoom.h"
#include <string>
using namespace std;

class LogMessageCommand : public Command {

public:
	LogMessageCommand(AbstractUser* fromUser, string message, ChatRoom* room) : Command(fromUser, message, room) {}
	void execute();
};

#endif
