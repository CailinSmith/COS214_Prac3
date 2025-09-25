#include "Decorator.h"
#include "ChatRoom.h"
#include "User.h"  


/**
 * @file Decorator.cpp
 * @brief Implementation of the Decorator base class for AbstractUser extension.
 */

/**
 * @brief Constructs a Decorator wrapping the given AbstractUser.
 * @param user Pointer to the AbstractUser to wrap.
 */
Decorator::Decorator(AbstractUser *user) {
    this->user = user;
    this->ownsUser = true;  
}

/**
 * @brief Removes the decorator, returning the wrapped user.
 * @return Pointer to the wrapped AbstractUser.
 */
AbstractUser* Decorator::removeDecorator() {
    ownsUser = false;  
    return user;
}

/**
 * @brief Destructor. Deletes wrapped user if owned.
 */
Decorator::~Decorator() {
    if (ownsUser) {
        delete user;
    }
}

/**
 * @brief Returns the decorated user's name/tag.
 * @return Decorated user name/tag string.
 */
string Decorator::print() {
    return user->print();
}

/**
 * @brief Delegates sending a message to the wrapped user.
 * @param message Message to send.
 * @param room Target chat room.
 */
void Decorator::send(string message, ChatRoom* room) {
    user->send(message, room);
}

/**
 * @brief Delegates broadcasting a message to the wrapped user.
 * @param message Message to broadcast.
 */
void Decorator::broadcast(string message) {
    user->broadcast(message);
}

/**
 * @brief Delegates receiving a message to the wrapped user.
 * @param message Message received.
 * @param fromUser Sender of the message.
 * @param room Chat room where message was received.
 */
void Decorator::receive(string message, AbstractUser* fromUser, ChatRoom* room) {
    user->receive(message, fromUser, room);
}

/**
 * @brief Delegates adding a command to the wrapped user.
 * @param command Command to add.
 */
void Decorator::addCommand(Command* command) {
    user->addCommand(command);
}

/**
 * @brief Delegates executing all commands to the wrapped user.
 */
void Decorator::executeAll() {
    user->executeAll();
}

/**
 * @brief Registers the decorator in the given chat room.
 * @param room Chat room to register in.
 */
void Decorator::addChatRoom(ChatRoom* room) {
    room->registerUser(this);
}

/**
 * @brief Delegates chat room removal to the wrapped user.
 * @param room Chat room to remove.
 */
void Decorator::removeChatRoom(ChatRoom* room) {
    user->removeChatRoom(room);
}
