#ifndef USER_H
#define USER_H

class User : AbstractUser {

protected:
	vector<ChatRoom*> chatRooms;
	string name;
	vector<Command*> commandQueue;

public:
	void send(string message, ChatRoom room);

	void receive(string message, AbstractUser fromUser, ChatRoom room);

	void addCommand(Command command);

	void executeAll();

	string print();
};

#endif
