#ifndef COLLECTION_H
#define COLLECTION_H

#include "Iterator.h"
#include <string>
using namespace std;

class AbstractUser;

class Collection {

public:
	virtual Iterator<AbstractUser*>* createUserIterator() = 0;
	
	virtual Iterator<string*>* createMessageIterator() = 0;

	virtual bool isEmpty() = 0;
};

#endif
