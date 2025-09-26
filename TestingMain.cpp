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

void testMediatorCommand()
{
    cout << "=== Testing Mediator Pattern ===" << endl
         << endl;

    ChatRoom *dogorithmRoom = new Dogorithm();
    ChatRoom *ctrlCatRoom = new CtrlCat();
    cout << "   - Created " << dogorithmRoom->print() << " room" << endl;
    cout << "   - Created " << ctrlCatRoom->print() << " room" << endl
         << endl;

    AbstractUser *alice = new Alice();
    AbstractUser *bob = new Bob();
    AbstractUser *charlie = new Charlie();
    cout << "   - Created 3 users" << endl
         << endl;

    try
    {
        alice->addChatRoom(dogorithmRoom);
        bob->addChatRoom(dogorithmRoom);
        bob->addChatRoom(ctrlCatRoom);
        charlie->addChatRoom(ctrlCatRoom);
        cout << "   Users registered successfully" << endl;
    }
    catch (const char *error)
    {
        cout << "   Registration error: " << error << endl;
    }
    cout << endl;

    try
    {
        alice->send("Hello from Alice", dogorithmRoom);
        bob->send("Hi Alice, this is Bob", dogorithmRoom);
        cout << "   Messages sent through mediator" << endl;

        alice->executeAll();
        bob->send("Hello from Bob in CtrlCat", ctrlCatRoom);
        bob->executeAll();
        cout << "   Commands executed successfully" << endl;
    }
    catch (const char *error)
    {
        cout << "   Command error: " << error << endl;
    }
    cout << endl;

    try
    {
        cout << "   Bob broadcasting message to all his rooms (Dogorithm and CtrlCat)..." << endl;
        bob->broadcast("This is a broadcast message from Bob to all rooms");
        bob->executeAll();
        cout << "   Broadcast executed successfully" << endl;

        cout << "   Charlie broadcasting message to his room (CtrlCat only)..." << endl;
        charlie->broadcast("Charlie's broadcast message to CtrlCat");
        charlie->executeAll();
        cout << "   Charlie's broadcast executed successfully" << endl;
    }
    catch (const char *error)
    {
        cout << "   Broadcast error: " << error << endl;
    }
    cout << endl;

    try
    {
        bool isEmpty = dogorithmRoom->isEmpty();
        cout << "Dogorithm room is " << (isEmpty ? "empty" : "not empty") << endl;

        isEmpty = ctrlCatRoom->isEmpty();
        cout << "CtrlCat room is " << (isEmpty ? "empty" : "not empty") << endl;
    }
    catch (const char *error)
    {
        cout << "isEmpty error: " << error << endl;
    }
    cout << endl;

    try
    {
        dogorithmRoom->removeUser(alice);
        cout << "   User removed from Dogorithm room" << endl;
    }
    catch (const char *error)
    {
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
    cout << "=== Testing Iterator Pattern ===" << endl
         << endl;
    std::vector<std::string *> messages;
    messages.push_back(new std::string("Message 1"));
    messages.push_back(new std::string("Message 2"));
    messages.push_back(new std::string("Message 3"));

    VectorIterator<std::string *> msgIter(messages);
    cout << "Iterating over messages:" << endl;
    for (msgIter.first(); msgIter.hasNext(); msgIter.next())
        cout << "  " << *(msgIter.current()) << endl;

    for (auto msg : messages)
        delete msg;

    std::vector<AbstractUser *> users;
    users.push_back(new Alice());
    users.push_back(new Bob());
    users.push_back(new Charlie());

    VectorIterator<AbstractUser *> userIter(users);
    cout << "\nIterating over users:" << endl;
    for (userIter.first(); userIter.hasNext(); userIter.next())
    {
        AbstractUser *u = userIter.current();
        cout << "  User: " << u->print() << endl;
    }

    for (auto u : users)
        delete u;

    std::vector<int> numbers = {1, 2, 3, 4, 5};
    VectorIterator<int> ints(numbers);
    cout << "Iterating over numbers:" << endl;
    for (ints.first(); ints.hasNext(); ints.next())
        cout << "  " << (ints.current()) << endl;

    cout << "=== Iterator Pattern Test Complete ===" << endl;
}

void testDecorator()
{
    cout << "=== Testing Decorator Pattern with Colors ===" << endl
         << endl;

    ChatRoom *room = new Dogorithm();
    cout << "   - Created " << room->print() << " chat room" << endl;

    AbstractUser *alice = new Alice();
    AbstractUser *bob = new Bob();
    AbstractUser *charlie = new Charlie();
    cout << "   - Created 3 base users" << endl;

    alice = new Chataholic(alice);
    bob = new AnimalLover(bob);
    charlie = new Chataholic(charlie);
    cout << "   - Applied decorators to users" << endl;
    cout << "     " << alice->print() << endl;
    cout << "     " << bob->print() << endl;
    cout << "     " << charlie->print() << endl;

    alice->addChatRoom(room);
    bob->addChatRoom(room);
    charlie->addChatRoom(room);
    cout << "   - Registered decorated users to chat room" << endl
         << endl;

    cout << "=== Test 1: Messages with decorators ===" << endl;
    alice->send("Hello everyone!", room);
    bob->send("Hi Alice!", room);
    charlie->send("Welcome to the chat!", room);
    cout << "   - Messages sent" << endl;

    alice->executeAll();
    bob->executeAll();
    charlie->executeAll();
    cout << "   - Commands executed" << endl
         << endl;

    cout << "=== Test 2: Remove decorator from Alice ===" << endl;
    cout << "   - Alice before: " << alice->print() << endl;

    AbstractUser *aliceDecorator = alice;
    alice = alice->removeDecorator();
    delete aliceDecorator;
    cout << "   - Alice after: " << alice->print() << endl;

    delete alice;
    delete bob;
    delete charlie;
    delete room;

    AbstractUser *user = new Alice();
    user = new Chataholic(user);
    user = new AnimalLover(user);
    cout << user->print() << endl;
    AbstractUser *removed = user;
    user = user->removeDecorator(); 
    delete removed;
    cout << user->print() << endl;
    delete user;

    cout << "=== Decorator Pattern Test Complete ===" << endl;
}

int main()
{
    testIterator();
    testMediatorCommand();
    testDecorator();

    return 0;
}