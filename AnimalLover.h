#ifndef ANIMALLOVER_H
#define ANIMALLOVER_H
#include "Decorator.h"

class AnimalLover : public Decorator {

public:
	AnimalLover(AbstractUser* user);
	virtual ~AnimalLover(){};
	string print();
	
	void send(string message, ChatRoom* room) override;
	void broadcast(string message) override;
	void receive(string message, AbstractUser* fromUser, ChatRoom* room) override;
};


#endif
