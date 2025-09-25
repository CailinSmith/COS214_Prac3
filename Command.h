/**
 * @file Command.h
 * @brief Abstract base class for the Command pattern implementation in chat system
 * @author Cailin Smith
 * @date 2025-09-25
 */

#ifndef COMMAND_H
#define COMMAND_H

#include <string>
using namespace std;

class ChatRoom;
class AbstractUser;

/**
 * @class Command
 * @brief Abstract base class implementing the Command pattern for deferred execution
 * 
 * This class serves as the Command interface in the Command pattern, allowing
 * for encapsulation of messaging operations that can be queued and executed later.
 * All concrete command implementations inherit from this class.
 *
 * Attributes:
 *   - room: Pointer to the chat room where the command should be executed
 *   - message: The message content associated with the command
 *   - fromUser: Pointer to the user who initiated the command
 *
 * Responsibilities:
 *   - Stores command parameters for deferred execution
 *   - Defines interface for command execution
 *   - Provides base functionality for concrete command implementations
 *   - Enables undo/redo functionality and command queuing
 */
class Command {

protected:
	ChatRoom* room;
	string message;
	AbstractUser* fromUser;

public:
	/**
	 * @brief Constructor that initializes command with required parameters
	 * @param fromUser Pointer to the user who initiated the command
	 * @param message The message content associated with the command
	 * @param room Pointer to the chat room where command should be executed
	 */
	Command(AbstractUser* fromUser, string message, ChatRoom* room) {
		this->fromUser = fromUser;
		this->message = message;
		this->room = room;
	}
	
	/**
	 * @brief Virtual destructor for proper polymorphic cleanup
	 */
	virtual ~Command() = default; 
	
	/**
	 * @brief Execute the command's specific functionality
	 * @note Pure virtual function - must be implemented in subclasses
	 */
	virtual void execute() = 0;
};

#endif
