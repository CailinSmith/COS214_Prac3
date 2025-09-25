#include "SendMessageCommand.h"

void SendMessageCommand::execute() {
	room->sendMessage(message, fromUser);
}
