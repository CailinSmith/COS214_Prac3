#include "Chataholic.h"
#include <iostream>
#include "ChatRoom.h"

using namespace std;


Chataholic::Chataholic(AbstractUser* user) : Decorator(user) {
}

string Chataholic::print() {
    return Decorator::print() + "\033[35m (Chataholic)\033[0m";
}

void Chataholic::send(string message, ChatRoom* room) {
    Decorator::send(message, room);
}

void Chataholic::broadcast(string message) {
    Decorator::broadcast(message);
}

void Chataholic::receive(string message, AbstractUser* fromUser, ChatRoom* room) {
    string fromName = fromUser->print();
    cout << this->print() << " reports: Message from " << fromName << " in room " << room->print() << ": \n" << message << endl << endl;
}
