#ifndef COLLECTION_H
#define COLLECTION_H

class Collection {


public:
	virtual Iterator<T> createIterator() = 0;

	virtual boolean isEmpty() = 0;
};

#endif
