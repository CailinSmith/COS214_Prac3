#ifndef VECTORITERATOR_H
#define VECTORITERATOR_H

template <typename T>
class VectorIterator : Iterator {

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

	void ~VectorIterator();
};

#endif
