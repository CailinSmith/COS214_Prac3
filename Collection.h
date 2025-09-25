/**
 * @file Collection.h
 * @brief Abstract base class defining collection interface for iterating over users and messages
 * @author Cailin Smith
 * @date 2025-09-25
 */

#ifndef COLLECTION_H
#define COLLECTION_H

#include "Iterator.h"
#include <string>
using namespace std;

class AbstractUser;

/**
 * @class Collection
 * @brief Abstract base class providing iterator interface for collections of users and messages
 * 
 * This class defines the interface for collections that need to provide
 * iterator access to their internal data structures. It supports iteration
 * over both user collections and message collections using the Iterator pattern.
 *
 * Responsibilities:
 *   - Defines interface for creating user iterators
 *   - Defines interface for creating message iterators  
 *   - Defines interface for checking collection emptiness
 *   - Serves as base class for concrete collections (like ChatRoom)
 */
class Collection {

public:
	/**
	 * @brief Virtual destructor for proper polymorphic cleanup
	 */
	virtual ~Collection(){};
	
	/**
	 * @brief Create an iterator for traversing user collections
	 * @return Pointer to iterator for AbstractUser* elements
	 * @note Pure virtual function - must be implemented in subclasses
	 */
	virtual Iterator<AbstractUser*>* createUserIterator() = 0;
	
	/**
	 * @brief Create an iterator for traversing message collections
	 * @return Pointer to iterator for string* elements  
	 * @note Pure virtual function - must be implemented in subclasses
	 */
	virtual Iterator<string*>* createMessageIterator() = 0;

	/**
	 * @brief Check if the collection is empty
	 * @return True if collection contains no elements, false otherwise
	 * @note Pure virtual function - must be implemented in subclasses
	 */
	virtual bool isEmpty() = 0;
};

#endif
