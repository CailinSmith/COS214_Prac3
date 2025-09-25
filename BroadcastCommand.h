#ifndef BROADCASTCOMMAND_H
#define BROADCASTCOMMAND_H

#include "Command.h"
#include "AbstractUser.h"
#include "ChatRoom.h"
#include <string>
using namespace std;

class BroadcastCommand : public Command {

public:
	BroadcastCommand(AbstractUser* fromUser, string message) : Command(fromUser, message, nullptr) {}
	void execute();

};

#endif