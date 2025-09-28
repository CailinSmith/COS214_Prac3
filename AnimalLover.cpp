#include "AnimalLover.h"
#include <iostream>
#include "ChatRoom.h"

using namespace std;

AnimalLover::AnimalLover(AbstractUser* user) : Decorator(user) {
}

string AnimalLover::print() {
    return Decorator::print() + "\033[34m (Animal Lover)\033[0m";
}

void AnimalLover::send(string message, ChatRoom* room) {
    Decorator::send(message, room);
}

void AnimalLover::broadcast(string message) {
    Decorator::broadcast(message);
}

void AnimalLover::receive(string message, AbstractUser* fromUser, ChatRoom* room) {
    string fromName = fromUser->print();
    cout << this->print() << " reports: Message from " << fromName << " in room " << room->print() << ": \n" << message << endl << endl;
}