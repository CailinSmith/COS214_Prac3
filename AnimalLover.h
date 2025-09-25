
/**
 * @file AnimalLover.h
 * @brief Decorator for users who love animals, adds blue tag to user name.
 * @author Jordan Naidoo
 * @date 2025-09-25
 */

#ifndef ANIMALLOVER_H
#define ANIMALLOVER_H
#include "Decorator.h"

/**
 * @class AnimalLover
 * @brief Decorator that adds a blue "Animal Lover" tag to the user's name and customizes message output.
 */
class AnimalLover : public Decorator {
public:
	/**
	 * @brief Constructs an AnimalLover decorator for the given user.
	 * @param user Pointer to the AbstractUser to decorate.
	 */
	AnimalLover(AbstractUser* user);

	/**
	 * @brief Destructor.
	 */
	virtual ~AnimalLover(){};

	/**
	 * @brief Returns the user's name with the Animal Lover tag.
	 * @return Decorated user name string.
	 */
	string print();

	/**
	 * @brief Delegates sending a message to the wrapped user.
	 * @param message Message to send.
	 * @param room Target chat room.
	 */
	void send(string message, ChatRoom* room) override;

	/**
	 * @brief Delegates broadcasting a message to the wrapped user.
	 * @param message Message to broadcast.
	 */
	void broadcast(string message) override;

	/**
	 * @brief Customizes message reception output for AnimalLover users.
	 * @param message Message received.
	 * @param fromUser Sender of the message.
	 * @param room Chat room where message was received.
	 */
	void receive(string message, AbstractUser* fromUser, ChatRoom* room) override;
};

#endif
