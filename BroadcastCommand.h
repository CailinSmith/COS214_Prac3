/**
 * @file BroadcastCommand.h
 * @brief Command implementation for broadcasting messages to all chat rooms a user belongs to
 * @author Cailin Smith
 * @date 2025-09-25
 */

#ifndef BROADCASTCOMMAND_H
#define BROADCASTCOMMAND_H

#include "Command.h"
#include "AbstractUser.h"
#include "ChatRoom.h"
#include <string>
using namespace std;

/**
 * @class BroadcastCommand
 * @brief Concrete command that broadcasts a message to all chat rooms the user is a member of
 * 
 * This class implements the Command pattern for broadcasting functionality.
 * When executed, it sends the same message to every chat room that the user
 * has joined, allowing for efficient multi-room communication.
 *
 * Responsibilities:
 *   - Stores broadcast message and sender information
 *   - Executes broadcast by sending message to all user's chat rooms
 *   - Works with User class to access chat room memberships
 */
class BroadcastCommand : public Command {

public:
	/**
	 * @brief Constructor for BroadcastCommand
	 * @param fromUser Pointer to the user who wants to broadcast the message
	 * @param message The message content to broadcast to all rooms
	 * @note Sets room parameter to nullptr since broadcast targets multiple rooms
	 */
	BroadcastCommand(AbstractUser* fromUser, string message) : Command(fromUser, message, nullptr) {}
	
	/**
	 * @brief Implementation of execute that broadcasts message to all user's chat rooms
	 * 
	 * Casts the AbstractUser to User to access chat room memberships,
	 * then iterates through all rooms and sends the message to each one
	 * via the ChatRoom's sendMessage method.
	 */
	void execute();

};

#endif