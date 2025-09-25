#ifndef VECTORITERATOR_H
#define VECTORITERATOR_H

#include "Iterator.h"
#include <vector>
using namespace std;

template <typename T>
class VectorIterator : public Iterator<T> {
	
	friend class ChatRoom;  

protected:
	int currentPosition;
	vector<T> list;

public:
	void first();

	void next();

	bool hasNext();

	T current();

protected:
	VectorIterator(vector<T> list);

	~VectorIterator();
};

#endif
