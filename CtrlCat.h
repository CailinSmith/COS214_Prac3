#ifndef CTRLCAT_H
#define CTRLCAT_H

#include "ChatRoom.h"

class CtrlCat : public ChatRoom {
public:
    string print() { return "CtrlCat"; }
};

#endif
