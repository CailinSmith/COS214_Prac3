#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include "VectorIterator.h"
#include "User.h"
#include "Dogorithm.h"
#include "CtrlCat.h"
#include "SendMessageCommand.h"
#include "LogMessageCommand.h"
#include "Decorator.h"
#include "Chataholic.h"
#include "AnimalLover.h"

void testMediatorCommand() {
    cout << "=== Testing Mediator Pattern ===" << endl << endl;
    
    ChatRoom* dogorithmRoom = new Dogorithm();
    ChatRoom* ctrlCatRoom = new CtrlCat();
    cout << "   - Created " << dogorithmRoom->print() << " room" << endl;
    cout << "   - Created " << ctrlCatRoom->print() << " room" << endl << endl;
    
    AbstractUser* alice = new Alice();
    AbstractUser* bob = new Bob(); 
    AbstractUser* charlie = new Charlie();
    cout << "   - Created 3 users" << endl << endl;
    
    try {
        alice->addChatRoom(dogorithmRoom);
        bob->addChatRoom(dogorithmRoom);
        bob->addChatRoom(ctrlCatRoom);
        charlie->addChatRoom(ctrlCatRoom);
        cout << "   Users registered successfully" << endl;
    } catch (const char* error) {
        cout << "   Registration error: " << error << endl;
    }
    cout << endl;
    
    try {
        alice->send("Hello from Alice", dogorithmRoom);
        bob->send("Hi Alice, this is Bob", dogorithmRoom);
        cout << "   Messages sent through mediator" << endl;
        
        alice->executeAll();
        bob->send("Hello from Bob in CtrlCat", ctrlCatRoom);
        bob->executeAll();
        cout << "   Commands executed successfully" << endl;
    } catch (const char* error) {
        cout << "   Command error: " << error << endl;
    }
    cout << endl;
    
    try {
        cout << "   Bob broadcasting message to all his rooms (Dogorithm and CtrlCat)..." << endl;
        bob->broadcast("This is a broadcast message from Bob to all rooms");
        bob->executeAll();
        cout << "   Broadcast executed successfully" << endl;
        
        cout << "   Charlie broadcasting message to his room (CtrlCat only)..." << endl;
        charlie->broadcast("Charlie's broadcast message to CtrlCat");
        charlie->executeAll();
        cout << "   Charlie's broadcast executed successfully" << endl;
    } catch (const char* error) {
        cout << "   Broadcast error: " << error << endl;
    }
    cout << endl;
    
    try {
        bool isEmpty = dogorithmRoom->isEmpty();
        cout << "Dogorithm room is " << (isEmpty ? "empty" : "not empty") << endl;
        
        isEmpty = ctrlCatRoom->isEmpty();
        cout << "CtrlCat room is " << (isEmpty ? "empty" : "not empty") << endl;
    } catch (const char* error) {
        cout << "isEmpty error: " << error << endl;
    }
    cout << endl;
    
    try {
        dogorithmRoom->removeUser(alice);
        cout << "   User removed from Dogorithm room" << endl;
    } catch (const char* error) {
        cout << "Removal error: " << error << endl;
    }
    cout << endl;
    
    cout << "=== Mediator Pattern Testing Complete ===" << endl;
    
    delete alice;
    delete bob;
    delete charlie;
    delete dogorithmRoom;
    delete ctrlCatRoom;
}


void testIterator()
{
    std::vector<std::string*> messages;
    messages.push_back(new std::string("Message 1"));
    messages.push_back(new std::string("Message 2"));
    messages.push_back(new std::string("Message 3"));

    VectorIterator<std::string*> iter(messages);

    for (iter.first(); iter.hasNext(); iter.next())
        cout << *(iter.current()) << endl;

    for (auto msg : messages) 
        delete msg;
    
}

void testDecorator(){
    cout << "=== Testing Decorator Pattern with Colors ===" << endl << endl;

    // Create a chat room
    ChatRoom* room = new Dogorithm();
    cout << "   - Created chat room: " << room->print() << endl;

    // Create users with different tags
    AbstractUser* alice = new Alice();
    AbstractUser* bob = new Bob();
    AbstractUser* charlie = new Charlie();

    // Decorate users
    alice = new Chataholic(alice);      // Purple
    bob = new AnimalLover(bob);         // Blue
    charlie = new Chataholic(charlie);  // Purple
    charlie = new AnimalLover(charlie); // Blue (double decorated)

    // Register users to the chat room
    alice->addChatRoom(room);
    bob->addChatRoom(room);
    charlie->addChatRoom(room);
    cout << "   - Registered users with tags to chat room" << endl << endl;

    // Print users and their tags
    cout << "   - Users and tags:" << endl;
    cout << "     " << alice->print() << endl;
    cout << "     " << bob->print() << endl;
    cout << "     " << charlie->print() << endl << endl;

    // Simulate chat messages using print() for names
    cout << alice->print() << " says: Hello everyone!" << endl;
    cout << bob->print() << " says: Hi Alice!" << endl;
    cout << charlie->print() << " says: Welcome to the chat!" << endl;

    // Send messages through the chat room (actual logic)
    alice->send("Hello everyone!", room);
    bob->send("Hi Alice!", room);
    charlie->send("Welcome to the chat!", room);
    cout << "   - Messages sent to chat room" << endl;

    // Execute commands (if any)
    alice->executeAll();
    bob->executeAll();
    charlie->executeAll();
    cout << "   - Commands executed" << endl;

    // Clean up
    delete alice;
    delete bob;
    delete charlie;
    delete room;

    cout << endl << "=== Decorator Pattern Color Test Complete ===" << endl;
}


int main()
{
    // testIterator();
    // testMediatorCommand();
    testDecorator();

    return 0;
}