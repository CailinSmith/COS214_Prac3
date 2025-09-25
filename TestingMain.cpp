#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include "VectorIterator.h"
#include "VectorIterator.cpp"

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

int main()
{
    testIterator();
    return 0;
}