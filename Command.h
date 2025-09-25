#ifndef COMMAND_H
#define COMMAND_H

class Command {

protected:
	ChatRoom room;
	string message;
	User fromUser;

public:
	void execute();
};

#endif
