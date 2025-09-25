#include <iostream>
#include "User.h"
#include "Dogorithm.h"
#include "CtrlCat.h"
#include "SendMessageCommand.h"
#include "LogMessageCommand.h"

using namespace std;
void testMediatorCommand() {
    cout << "=== Testing Mediator Pattern ===" << endl << endl;
    
    ChatRoom* dogorithmRoom = new Dogorithm();
    ChatRoom* ctrlCatRoom = new CtrlCat();
    cout << "   - Created " << dogorithmRoom->print() << " room" << endl;
    cout << "   - Created " << ctrlCatRoom->print() << " room" << endl << endl;
    
    AbstractUser* alice = new Name1();
    AbstractUser* bob = new Name2(); 
    AbstractUser* charlie = new Name3();
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
int main() {
    testMediatorCommand();
    return 0;
}