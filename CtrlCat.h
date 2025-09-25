/**
 * @file CtrlCat.h
 * @brief Concrete implementation of ChatRoom representing the CtrlCat chat room
 * @author Cailin Smith
 * @date 2025-09-25
 */

#ifndef CTRLCAT_H
#define CTRLCAT_H

#include "ChatRoom.h"

/**
 * @class CtrlCat
 * @brief Concrete chat room implementation for CtrlCat-themed discussions
 * 
 * This class extends ChatRoom to provide a specific themed chat room.
 * It inherits all mediator functionality from ChatRoom and provides
 * its own identification through the print method.
 *
 * Responsibilities:
 *   - Inherits all ChatRoom mediator functionality
 *   - Provides specific room identification as "CtrlCat"
 *   - Serves as concrete mediator for CtrlCat-themed conversations
 */
class CtrlCat : public ChatRoom {
public:
    /**
     * @brief Implementation of print method that returns room identifier
     * @return String "CtrlCat" identifying this specific chat room type
     */
    string print() { return "CtrlCat"; }
};

#endif
