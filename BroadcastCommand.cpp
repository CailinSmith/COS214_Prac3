#include "BroadcastCommand.h"
#include "User.h"

void BroadcastCommand::execute() {
	User* user = dynamic_cast<User*>(fromUser);
	if (user != nullptr) {
		for (ChatRoom* room : user->getChatRooms()) {
			room->sendMessage(message, fromUser);
		}
	}
}