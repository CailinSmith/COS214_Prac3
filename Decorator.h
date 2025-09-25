#ifndef DECORATOR_H
#define DECORATOR_H
#include "AbstractUser.h"

class Decorator : public AbstractUser
{

private:
	AbstractUser *user;

public:
	Decorator(AbstractUser *user);
	AbstractUser *removeDecorator();
	virtual ~Decorator();
	virtual string print();

	virtual void send(string message, ChatRoom* room) override;
	virtual void broadcast(string message) override;
	virtual void receive(string message, AbstractUser* fromUser, ChatRoom* room) override;
	virtual void addCommand(Command* command) override;
	virtual void executeAll() override;
	virtual void addChatRoom(ChatRoom* room) override;
	virtual void removeChatRoom(ChatRoom* room) override;
};

#endif
