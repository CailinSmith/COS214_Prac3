/**
 * @file User.h
 * @brief Concrete implementation of AbstractUser with command pattern integration
 * @author Cailin Smith
 * @date 2025-09-25
 */

#ifndef USER_H
#define USER_H

#include "AbstractUser.h"
#include "ChatRoom.h"
#include "Command.h"
#include "SendMessageCommand.h"
#include "LogMessageCommand.h"
#include "BroadcastCommand.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

/**
 * @class User
 * @brief Concrete implementation of AbstractUser that manages chat room memberships and command execution
 * 
 * This class serves as the Concrete Colleague in the Mediator pattern.
 * It implements all abstract methods from AbstractUser and uses the Command pattern
 * for deferred execution of messaging operations.
 *
 * Attributes:
 *   - chatRooms: Vector of chat rooms the user is a member of
 *   - name: String identifier for the user
 *   - commandQueue: Vector of commands awaiting execution
 *
 * Responsibilities:
 *   - Manages membership in multiple chat rooms
 *   - Implements message sending using SendMessageCommand and LogMessageCommand
 *   - Implements broadcasting using BroadcastCommand
 *   - Maintains and executes a queue of commands
 *   - Provides access to chat room memberships
 */
class User : public AbstractUser {

protected:
	vector<ChatRoom*> chatRooms;
	string name;
	vector<Command*> commandQueue;

public:
	/**
	 * @brief Destructor that cleans up remaining commands in queue
	 */
	~User(); 
	
	/**
	 * @brief Implementation of send using SendMessageCommand and LogMessageCommand
	 * @param message The message content to send
	 * @param room Pointer to the chat room where the message should be sent
	 */
	void send(string message, ChatRoom* room);
	
	/**
	 * @brief Implementation of broadcast using BroadcastCommand to send to all user's rooms
	 * @param message The message content to broadcast
	 */
	void broadcast(string message);

	/**
	 * @brief Implementation of receive that displays incoming messages to console
	 * @param message The message content received
	 * @param fromUser Pointer to the user who sent the message
	 * @param room Pointer to the chat room where the message was sent
	 */
	void receive(string message, AbstractUser* fromUser, ChatRoom* room);

	/**
	 * @brief Implementation of addCommand that adds command to the execution queue
	 * @param command Pointer to the command to be queued
	 */
	void addCommand(Command* command);

	/**
	 * @brief Implementation of executeAll that runs all queued commands and clears queue
	 */
	void executeAll();

	/**
	 * @brief Implementation of addChatRoom that joins user to room and registers with mediator
	 * @param room Pointer to the chat room to join
	 */
	void addChatRoom(ChatRoom* room);
	
	/**
	 * @brief Implementation of removeChatRoom that removes user from room
	 * @param room Pointer to the chat room to leave
	 */
	void removeChatRoom(ChatRoom* room);

	/**
	 * @brief Get read-only access to the user's chat room memberships
	 * @return Const reference to vector of chat room pointers
	 */
	const vector<ChatRoom*>& getChatRooms() const { return chatRooms; }

	/**
	 * @brief Implementation of print that returns the user's display name
	 * @return String representation of the user's name
	 */
	string print();
	
	/**
	 * @brief Remove decorator and return base user (for decorator pattern compatibility)
	 * @return Pointer to this user instance
	 */
	AbstractUser *removeDecorator() { return this;}
	
};

/**
 * @class Alice
 * @brief Concrete user implementation representing Alice
 * 
 * Simple concrete implementation of User with "Alice" as the display name.
 */
class Alice : public User {
public:
	/**
	 * @brief Constructor that sets the user name to "Alice"
	 */
	Alice() { name = "Alice"; }
	
	/**
	 * @brief Implementation of print that returns "Alice"
	 * @return String "Alice"
	 */
	string print() { return name; }
};

/**
 * @class Bob
 * @brief Concrete user implementation representing Bob
 * 
 * Simple concrete implementation of User with "Bob" as the display name.
 */
class Bob : public User {
public:
	/**
	 * @brief Constructor that sets the user name to "Bob"
	 */
	Bob() { name = "Bob"; }
	
	/**
	 * @brief Implementation of print that returns "Bob"
	 * @return String "Bob"
	 */
	string print() { return name; }
};

/**
 * @class Charlie
 * @brief Concrete user implementation representing Charlie
 * 
 * Simple concrete implementation of User with "Charlie" as the display name.
 */
class Charlie : public User {
public:
	/**
	 * @brief Constructor that sets the user name to "Charlie"
	 */
	Charlie() { name = "Charlie"; }
	
	/**
	 * @brief Implementation of print that returns "Charlie"
	 * @return String "Charlie"
	 */
	string print() { return name; }
};


#endif
