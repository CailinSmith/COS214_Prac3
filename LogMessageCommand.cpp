#include "LogMessageCommand.h"

void LogMessageCommand::execute() {
	room->saveMessage(message, fromUser);
}
