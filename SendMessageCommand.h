/**
 * @file SendMessageCommand.h
 * @brief Command implementation for sending messages through the chat room mediator
 * @author Cailin Smith
 * @date 2025-09-25
 */

#ifndef SENDMESSAGECOMMAND_H
#define SENDMESSAGECOMMAND_H

#include "Command.h"
#include "AbstractUser.h"
#include "ChatRoom.h"
#include <string>
using namespace std;

/**
 * @class SendMessageCommand
 * @brief Concrete command that sends messages to other users via the chat room mediator
 * 
 * This class implements the Command pattern for message sending functionality.
 * When executed, it uses the ChatRoom mediator to deliver the message to
 * all other users in the specified chat room.
 *
 * Responsibilities:
 *   - Stores message and sender information for transmission
 *   - Executes message sending by calling ChatRoom's sendMessage method
 *   - Enables deferred message delivery through command queuing
 *   - Maintains mediator pattern by routing messages through ChatRoom
 */
class SendMessageCommand : public Command {

public:
	/**
	 * @brief Constructor for SendMessageCommand
	 * @param fromUser Pointer to the user sending the message
	 * @param message The message content to be sent
	 * @param room Pointer to the chat room where the message should be sent
	 */
	SendMessageCommand(AbstractUser* fromUser, string message, ChatRoom* room) : Command(fromUser, message, room) {}
	
	/**
	 * @brief Implementation of execute that sends message via chat room mediator
	 * 
	 * Calls the ChatRoom's sendMessage method to deliver the message
	 * to all other users in the room, following the mediator pattern.
	 */
	void execute();
};

#endif
