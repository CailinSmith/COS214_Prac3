/**
 * @file ChatRoom.h
 * @brief Abstract mediator class for managing user interactions in chat rooms
 * @author Cailin Smith
 * @date 2025-09-25
 */

#ifndef CHATROOM_H
#define CHATROOM_H

#include "Collection.h"
#include "Iterator.h"
#include "VectorIterator.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class AbstractUser;

/**
 * @class ChatRoom
 * @brief Abstract mediator class that coordinates communication between users
 * 
 * This class serves as the Mediator in the Mediator pattern, managing
 * all interactions between users in a chat room. It inherits from Collection
 * to provide iterator functionality for users and chat history.
 *
 * Attributes:
 *   - users: Vector of users currently in the chat room
 *   - chatHistory: Vector of message strings representing conversation history
 *
 * Responsibilities:
 *   - Manages user registration and removal from chat room
 *   - Coordinates message sending between users
 *   - Maintains persistent chat history
 *   - Provides iterator access to users and messages
 *   - Serves as central communication hub (Mediator pattern)
 */
class ChatRoom : public Collection {

private:
	vector<AbstractUser*> users;
	vector<string*> chatHistory;

public:
	/**
	 * @brief Virtual destructor that cleans up chat history
	 */
	virtual ~ChatRoom(); 

	/**
	 * @brief Register a user with the chat room
	 * @param user Pointer to the user to register
	 * @note Pure virtual function - must be overridden in subclasses
	 */
	virtual void registerUser(AbstractUser* user);

	/**
	 * @brief Send a message from one user to all other users in the room
	 * @param message The message content to send
	 * @param fromUser Pointer to the user sending the message
	 * @note Pure virtual function - must be overridden in subclasses
	 */
	virtual void sendMessage(string message, AbstractUser* fromUser);

	/**
	 * @brief Save a message to the chat room's persistent history
	 * @param message The message content to save
	 * @param fromUser Pointer to the user who sent the message
	 * @note Pure virtual function - must be overridden in subclasses
	 */
	virtual void saveMessage(string message, AbstractUser* fromUser);

	/**
	 * @brief Remove a user from the chat room
	 * @param user Pointer to the user to remove
	 * @note Pure virtual function - must be overridden in subclasses
	 */
	virtual void removeUser(AbstractUser* user);

	/**
	 * @brief Create an iterator for traversing users in the chat room
	 * @return Pointer to iterator for AbstractUser* elements
	 */
	Iterator<AbstractUser*>* createUserIterator();

	/**
	 * @brief Create an iterator for traversing chat message history
	 * @return Pointer to iterator for string* elements
	 */
	Iterator<string*>* createMessageIterator();

	/**
	 * @brief Check if the chat room is empty (no users)
	 * @return True if no users are in the room, false otherwise
	 */
	bool isEmpty();
	
	/**
	 * @brief Get string representation of the chat room
	 * @return String "ChatRoom" (overridden in subclasses for specific room types)
	 */
	virtual string print() { return "ChatRoom"; }
};


#endif
