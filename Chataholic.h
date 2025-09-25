#ifndef CHATAHOLIC_H
#define CHATAHOLIC_H
#include "Decorator.h"

class Chataholic :public Decorator {
public:
    Chataholic(AbstractUser* user);
    virtual ~Chataholic(){};
    string print();

    void send(string message, ChatRoom* room) override;
    void broadcast(string message) override;
    void receive(string message, AbstractUser* fromUser, ChatRoom* room) override;
};

#endif
