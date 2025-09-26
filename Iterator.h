/**
 * @file Iterator.h
 * @brief Abstract base class template for iterator pattern implementation
 * @author COS214 Team
 * @date 2025-09-26
 */

#ifndef ITERATOR_H
#define ITERATOR_H

/**
 * @class Iterator
 * @brief Abstract iterator interface for traversing collections
 * 
 * This template class defines the interface for the Iterator pattern.
 * It provides pure virtual methods that concrete iterators must implement
 * to traverse different types of collections.
 * 
 * Responsibilities:
 *   - Defines the interface for collection traversal
 *   - Provides abstract methods for navigation and access
 *   - Supports different element types through templating
 * 
 * @tparam T Type of elements to iterate over
 */
template <typename T>
class Iterator {

public:
	/**
	 * @brief Virtual destructor to ensure proper cleanup of derived classes
	 */
	virtual ~Iterator() {} 
	
	/**
	 * @brief Sets iterator position to the first element in the collection
	 */
	virtual void first() = 0;
	
	/**
	 * @brief Advances iterator to the next element in the collection
	 */
	virtual void next() = 0;
	
	/**
	 * @brief Checks if there are more elements to iterate over
	 * @return True if more elements exist, false if at end of collection
	 */
	virtual bool hasNext() = 0;
	
	/**
	 * @brief Returns the current element at iterator position
	 * @return The current element of type T
	 */
	virtual T current() = 0;
};

#endif
