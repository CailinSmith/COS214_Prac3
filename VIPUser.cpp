#include "VIPUser.h"
#include <iostream>
#include "ChatRoom.h"

using namespace std;

VIPUser::VIPUser(AbstractUser* user) : Decorator(user) {
}

string VIPUser::print() {
    return Decorator::print() + "\033[33m (VIP)\033[0m";
}

void VIPUser::send(string message, ChatRoom* room) {
    Decorator::send(message, room);
}

void VIPUser::broadcast(string message) {
    Decorator::broadcast(message);
}

void VIPUser::receive(string message, AbstractUser* fromUser, ChatRoom* room) {
    // cout << "----------------------------------------------------------------" << endl;
    string fromName = fromUser->print();
    cout << this->print() << " reports: Message from " << fromName << " in room " << room->print() << ": \n" << message << endl << endl;
    // cout << "----------------------------------------------------------------" << endl;
}