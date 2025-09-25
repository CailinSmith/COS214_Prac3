
/**
 * @file Chataholic.h
 * @brief Decorator for users who are chatty, adds purple tag to user name.
 * @author Jordan Naidoo
 * @date 2025-09-25
 */

#ifndef CHATAHOLIC_H
#define CHATAHOLIC_H
#include "Decorator.h"

/**
 * @class Chataholic
 * @brief Decorator that adds a purple "Chataholic" tag to the user's name and customizes message output.
 */
class Chataholic : public Decorator {
public:
    /**
     * @brief Constructs a Chataholic decorator for the given user.
     * @param user Pointer to the AbstractUser to decorate.
     */
    Chataholic(AbstractUser* user);

    /**
     * @brief Destructor.
     */
    virtual ~Chataholic(){};

    /**
     * @brief Returns the user's name with the Chataholic tag.
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
     * @brief Customizes message reception output for Chataholic users.
     * @param message Message received.
     * @param fromUser Sender of the message.
     * @param room Chat room where message was received.
     */
    void receive(string message, AbstractUser* fromUser, ChatRoom* room) override;
};

#endif
