#include "DogWhisperer.h"
#include <iostream>
#include "ChatRoom.h"

using namespace std;

DogWhisperer::DogWhisperer(AbstractUser* user) : Decorator(user) {
}

string DogWhisperer::print() {
    return Decorator::print() + "\033[32m (Dog Whisperer)\033[0m";
}

void DogWhisperer::send(string message, ChatRoom* room) {
    Decorator::send(message, room);
}

void DogWhisperer::broadcast(string message) {
    Decorator::broadcast(message);
}

void DogWhisperer::receive(string message, AbstractUser* fromUser, ChatRoom* room) {
    string fromName = fromUser->print();
    cout << this->print() << " reports: Message from " << fromName << " in room " << room->print() << ":\n" << message << endl << endl;
}