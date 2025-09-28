/**
 * @file DogWhisperer.h
 * @brief Concrete decorator that adds dog whisperer role to users with green tag
 * @author Cailin Smith
 * @date 2025-09-28
 */

#ifndef DOGWHISPERER_H
#define DOGWHISPERER_H

#include "Decorator.h"
#include <string>

using namespace std;

/**
 * @class DogWhisperer
 * @brief Concrete decorator that adds a green "Dog Whisperer" tag to user names
 * 
 * This decorator extends user functionality by adding a green-colored role tag
 * that appears when the user's name is displayed. Inspired by Discord-style roles.
 *
 * Responsibilities:
 *   - Adds green "(Dog Whisperer)" tag to user names
 *   - Maintains all AbstractUser functionality through delegation
 *   - Provides custom message receiving behavior with role display
 */
class DogWhisperer : public Decorator
{
public:
	/**
	 * @brief Constructs a DogWhisperer decorator wrapping the given user
	 * @param user Pointer to the AbstractUser to decorate with dog whisperer role
	 */
	DogWhisperer(AbstractUser* user);

	/**
	 * @brief Destructor.
	 */
	virtual ~DogWhisperer(){};

	/**
	 * @brief Returns the user's name with green dog whisperer tag
	 * @return String containing the decorated user name with green "(Dog Whisperer)" tag
	 */
	virtual string print() override;

	/**
	 * @brief Delegates message sending to the base decorator
	 * @param message Message content to send
	 * @param room Target chat room for the message
	 */
	virtual void send(string message, ChatRoom* room) override;

	/**
	 * @brief Delegates message broadcasting to the base decorator  
	 * @param message Message content to broadcast to all rooms
	 */
	virtual void broadcast(string message) override;

	/**
	 * @brief Handles message reception with dog whisperer role display
	 * @param message Message content received
	 * @param fromUser Sender of the message
	 * @param room Chat room where message was received
	 */
	virtual void receive(string message, AbstractUser* fromUser, ChatRoom* room) override;
};

#endif