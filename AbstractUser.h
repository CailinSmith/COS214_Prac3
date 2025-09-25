
/**
 * @file AbstractUser.h
 * @brief Abstract base class for users and decorators
 * @author Jordan Naidoo
 * @date 2025-09-25
 */

#ifndef ABSTRACTUSER_H
#define ABSTRACTUSER_H

#include <string>
using namespace std;

class ChatRoom;
class Command;

/**
 * @class AbstractUser
 * @brief Abstract base for users and decorators to allow them to be treated the same
 *
 * Responsibilities:
 *   - Defines the interface for user actions and decorator extension.
 */
class AbstractUser {
public:
	/**
	 * @brief Virtual destructor.
	 */
	virtual ~AbstractUser() {};

	/**
	 * @brief Sends a message to a chat room.
	 * @param message Message to send.
	 * @param room Target chat room.
	 */
	virtual void send(string message, ChatRoom* room) = 0;

	/**
	 * @brief Broadcasts a message to all chat rooms.
	 * @param message Message to broadcast.
	 */
	virtual void broadcast(string message) = 0;

	/**
	 * @brief Receives a message from another user in a chat room.
	 * @param message Message received.
	 * @param fromUser Sender of the message.
	 * @param room Chat room where message was received.
	 */
	virtual void receive(string message, AbstractUser* fromUser, ChatRoom* room) = 0;

	/**
	 * @brief Adds a command to the user's command queue.
	 * @param command Command to add.
	 */
	virtual void addCommand(Command* command) = 0;

	/**
	 * @brief Executes all commands in the user's command queue.
	 */
	virtual void executeAll() = 0;

	/**
	 * @brief Registers the user in a chat room.
	 * @param room Chat room to register in.
	 */
	virtual void addChatRoom(ChatRoom* room) = 0;

	/**
	 * @brief Removes the user from a chat room.
	 * @param room Chat room to remove from.
	 */
	virtual void removeChatRoom(ChatRoom* room) = 0;

	/**
	 * @brief Removes a decorator, returning the wrapped user (or self if not decorated).
	 * @return Pointer to the underlying AbstractUser.
	 */
	virtual AbstractUser *removeDecorator() = 0;

	/**
	 * @brief Returns the user's name or decorated tag.
	 * @return User name/tag string.
	 */
	virtual string print() = 0;
};

#endif

