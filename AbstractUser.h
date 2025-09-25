#ifndef ABSTRACTUSER_H
#define ABSTRACTUSER_H

class AbstractUser {


public:
	virtual void send(string message, ChatRoom room) = 0;

	virtual void receive(string message, AbstracUser fromUser, ChatRoom room) = 0;

	virtual void addCommand(Command command) = 0;

	virtual void executeAll() = 0;

	virtual string print() = 0;
};

#endif
