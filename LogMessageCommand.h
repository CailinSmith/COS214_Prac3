/**
 * @file LogMessageCommand.h
 * @brief Command implementation for logging messages to chat room history
 * @author Cailin Smith
 * @date 2025-09-25
 */

#ifndef LOGMESSAGECOMMAND_H
#define LOGMESSAGECOMMAND_H

#include "Command.h"
#include "AbstractUser.h"
#include "ChatRoom.h"
#include <string>
using namespace std;

/**
 * @class LogMessageCommand
 * @brief Concrete command that logs messages to chat room's persistent history
 * 
 * This class implements the Command pattern for message logging functionality.
 * When executed, it saves the message to the chat room's history for
 * persistent storage and future reference.
 *
 * Responsibilities:
 *   - Stores message and sender information for logging
 *   - Executes logging by calling ChatRoom's saveMessage method
 *   - Enables deferred message persistence through command queuing
 */
class LogMessageCommand : public Command {

public:
	/**
	 * @brief Constructor for LogMessageCommand
	 * @param fromUser Pointer to the user who sent the message to be logged
	 * @param message The message content to be saved to history
	 * @param room Pointer to the chat room where the message should be logged
	 */
	LogMessageCommand(AbstractUser* fromUser, string message, ChatRoom* room) : Command(fromUser, message, room) {}
	
	/**
	 * @brief Implementation of execute that saves message to chat room history
	 * 
	 * Calls the ChatRoom's saveMessage method to persist the message
	 * in the room's chat history for future reference.
	 */
	void execute();
};

#endif
