#ifndef CHATROOM_H
#define CHATROOM_H

class ChatRoom : Collection {

private:
	vector<AbstractUser*> users;
	vector<string*> chatHistory;

public:
	virtual void registerUser(AbstractUser user) = 0;

	virtual void sendMessage(string message, AbstractUser fromUser) = 0;

	virtual void saveMessage(string message, AbstractUser fromUser) = 0;

	virtual void removeUser(AbstractUser user) = 0;

	Iterator<T> createIterator();

	boolean isEmpty();
};

#endif
