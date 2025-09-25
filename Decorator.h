
/**
 * @file Decorator.h
 * @brief Abstract decorator class for extending AbstractUser functionality at runtime.
 * @author Jordan Naidoo
 * @date 2025-09-25
 */

#ifndef DECORATOR_H
#define DECORATOR_H
#include "AbstractUser.h"

/**
 * @class Decorator
 * @brief Base decorator for dynamically adding responsibilities to AbstractUser objects.
 *
 * Attributes:
 *   - user: Pointer to the wrapped AbstractUser.
 *   - ownsUser: Indicates ownership for memory management.
 *
 * Responsibilities:
 *   - Delegates all AbstractUser methods to the wrapped user.
 *   - Allows runtime extension of user behavior via derived decorators.
 */
class Decorator : public AbstractUser
{
private:
	AbstractUser *user; /**< Wrapped AbstractUser object. */
	bool ownsUser;      /**< Ownership flag for memory management. */

public:
	/**
	 * @brief Constructs a Decorator wrapping the given AbstractUser.
	 * @param user Pointer to the AbstractUser to wrap.
	 */
	Decorator(AbstractUser *user);

	/**
	 * @brief Removes the decorator, returning the wrapped user.
	 * @return Pointer to the wrapped AbstractUser.
	 */
	AbstractUser *removeDecorator();

	/**
	 * @brief Destructor. Deletes wrapped user if owned.
	 */
	virtual ~Decorator();

	/**
	 * @brief Returns the decorated user's name/tag.
	 * @return Decorated user name/tag string.
	 */
	virtual string print();

	/**
	 * @brief Delegates sending a message to the wrapped user.
	 * @param message Message to send.
	 * @param room Target chat room.
	 */
	virtual void send(string message, ChatRoom* room) override;

	/**
	 * @brief Delegates broadcasting a message to the wrapped user.
	 * @param message Message to broadcast.
	 */
	virtual void broadcast(string message) override;

	/**
	 * @brief Delegates receiving a message to the wrapped user.
	 * @param message Message received.
	 * @param fromUser Sender of the message.
	 * @param room Chat room where message was received.
	 */
	virtual void receive(string message, AbstractUser* fromUser, ChatRoom* room) override;

	/**
	 * @brief Delegates adding a command to the wrapped user.
	 * @param command Command to add.
	 */
	virtual void addCommand(Command* command) override;

	/**
	 * @brief Delegates executing all commands to the wrapped user.
	 */
	virtual void executeAll() override;

	/**
	 * @brief Registers the decorator in the given chat room.
	 * @param room Chat room to register in.
	 */
	virtual void addChatRoom(ChatRoom* room) override;

	/**
	 * @brief Delegates chat room removal to the wrapped user.
	 * @param room Chat room to remove.
	 */
	virtual void removeChatRoom(ChatRoom* room) override;
};

#endif
