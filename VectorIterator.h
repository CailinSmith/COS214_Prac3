/**
 * @file VectorIterator.h
 * @brief Template iterator that will be used by the other classes to itterate over users and messages
 * @author Jordan Naidoo
 * @date 2025-09-25
 */

#ifndef VECTORITERATOR_H
#define VECTORITERATOR_H

#include "Iterator.h"
#include <vector>
using namespace std;

/**
 * @class VectorIterator
 * @brief Iterator for traversing elements in the user and message vecotrs in other classes
 * 
 * Attributes:
 *   - currentPosition: Current index in the vector.
 *   - list: Reference to the vector being iterated.
 *
 * Responsibilities:
 *   - Provides methods to iterate, access elements, and check for end of collection.
 * @tparam T Type of elements in the vector.
 *
 */
template <typename T>
class VectorIterator : public Iterator<T>
{
    friend class ChatRoom;

protected:
    int currentPosition; 
    vector<T> &list; 

public:
    /**
     * @brief Constructs a VectorIterator for a given vector.
     * @param list Reference to the vector to iterate over.
     */
    VectorIterator(vector<T> &list);

    /**
     * @brief Destructor.
     */
    virtual ~VectorIterator() = default;

    /**
     * @brief Sets iterator to the first element.
     */
    void first();

    /**
     * @brief moves iterator to the next element.
     */
    void next();

    /**
     * @brief Checks if there are more elements to iterate.
     * @return True if more elements exist, false otherwise.
     */
    bool hasNext();

    /**
     * @brief Returns the current element.
     * @return The current element of type T.
     */
    T current();
};


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

#endif
