/**
 * @file Dogorithm.h
 * @brief Concrete implementation of ChatRoom representing the Dogorithm chat room
 * @author Cailin Smith
 * @date 2025-09-25
 */

#ifndef DOGORITHM_H
#define DOGORITHM_H

#include "ChatRoom.h"

/**
 * @class Dogorithm
 * @brief Concrete chat room implementation for Dogorithm-themed discussions
 * 
 * This class extends ChatRoom to provide a specific themed chat room.
 * It inherits all mediator functionality from ChatRoom and provides
 * its own identification through the print method.
 *
 * Responsibilities:
 *   - Inherits all ChatRoom mediator functionality
 *   - Provides specific room identification as "Dogorithm"
 *   - Serves as concrete mediator for Dogorithm-themed conversations
 */
class Dogorithm : public ChatRoom {
public:
    /**
     * @brief Implementation of print method that returns room identifier
     * @return String "Dogorithm" identifying this specific chat room type
     */
    string print() { return "Dogorithm"; }
};

#endif
