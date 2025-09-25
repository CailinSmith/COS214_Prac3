#ifndef SENDMESSAGECOMMAND_H
#define SENDMESSAGECOMMAND_H

#include "Command.h"
#include "AbstractUser.h"
#include "ChatRoom.h"
#include <string>
using namespace std;

class SendMessageCommand : public Command {

public:
	SendMessageCommand(AbstractUser* fromUser, string message, ChatRoom* room) : Command(fromUser, message, room) {}
	void execute();

};

#endif
