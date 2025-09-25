#ifndef ITERATOR_H
#define ITERATOR_H

template <typename T>
class Iterator {

public:
	virtual ~Iterator() {} 
	virtual void first() = 0;
	virtual void next() = 0;
	virtual bool hasNext() = 0;
	virtual T current() = 0;
};

#endif
