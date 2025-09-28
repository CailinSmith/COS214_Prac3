/**
 * @file VIPUser.h
 * @brief Concrete decorator that adds VIP privileges to users with priority messaging
 * @author Cailin Smith
 * @date 2025-09-28
 */

#ifndef VIPUSER_H
#define VIPUSER_H

#include "Decorator.h"
#include <string>

using namespace std;

/**
 * @class VIPUser
 * @brief Concrete decorator that adds VIP status and priority messaging to users
 * 
 * This decorator extends user functionality by adding a gold-colored VIP tag
 * and provides priority messaging behavior. VIP users get special treatment
 * when sending messages with a priority announcement.
 *
 * Responsibilities:
 *   - Adds gold "(VIP)" tag to user names
 *   - Provides priority message sending with special announcement
 *   - Maintains all other AbstractUser functionality through delegation
 */
class VIPUser : public Decorator
{
public:
	/**
	 * @brief Constructs a VIPUser decorator wrapping the given user
	 * @param user Pointer to the AbstractUser to decorate with VIP privileges
	 */
	VIPUser(AbstractUser* user);

	/**
	 * @brief Returns the user's name with gold VIP tag
	 * @return String containing the decorated user name with gold "(VIP)" tag
	 */
	virtual string print() override;

	/**
	 * @brief Sends message with VIP priority announcement
	 * @param message Message content to send with VIP priority
	 * @param room Target chat room for the priority message
	 */
	virtual void send(string message, ChatRoom* room) override;

	/**
	 * @brief Delegates message broadcasting to the base decorator  
	 * @param message Message content to broadcast to all rooms
	 */
	virtual void broadcast(string message) override;

	/**
	 * @brief Handles message reception with VIP role display
	 * @param message Message content received
	 * @param fromUser Sender of the message
	 * @param room Chat room where message was received
	 */
	virtual void receive(string message, AbstractUser* fromUser, ChatRoom* room) override;
};

#endif