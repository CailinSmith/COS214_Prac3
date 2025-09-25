#include "VectorIterator.h"

template <typename T>
VectorIterator<T>::VectorIterator(vector<T>& list): list(list) {
	this->currentPosition = 0;
}

template <typename T>
void VectorIterator<T>::first() {
	currentPosition = 0;
}

template <typename T>
void VectorIterator<T>::next() {
	if (hasNext()) currentPosition++;
}

template <typename T>
bool VectorIterator<T>::hasNext() {
	size_t pos = currentPosition;
	return (pos < list.size());
}

template <typename T>
T VectorIterator<T>::current() {
	return list[currentPosition];

}

