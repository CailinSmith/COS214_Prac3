#include "Decorator.h"
#include "ChatRoom.h"

Decorator::Decorator(AbstractUser *user) {
    this->user = user;
}

AbstractUser* Decorator::removeDecorator() {
    return user;
}

Decorator::~Decorator() {
    delete user;
}

string Decorator::print() {
    return user->print();
}

void Decorator::send(string message, ChatRoom* room) {
    user->send(message, room);
}

void Decorator::broadcast(string message) {
    user->broadcast(message);
}

void Decorator::receive(string message, AbstractUser* fromUser, ChatRoom* room) {
    user->receive(message, fromUser, room);
}

void Decorator::addCommand(Command* command) {
    user->addCommand(command);
}

void Decorator::executeAll() {
    user->executeAll();
}

void Decorator::addChatRoom(ChatRoom* room) {
    room->registerUser(this);
}

void Decorator::removeChatRoom(ChatRoom* room) {
    user->removeChatRoom(room);
}
