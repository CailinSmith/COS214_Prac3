#ifndef SENDMESSAGECOMMAND_H
#define SENDMESSAGECOMMAND_H

#include "Command.h"

class SendMessageCommand : public Command {

public:
	SendMessageCommand(AbstractUser* fromUser, string message, ChatRoom* room) : Command(fromUser, message, room) {}
	void execute();

};

#endif
