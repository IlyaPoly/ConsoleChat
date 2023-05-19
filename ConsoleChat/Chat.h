#pragma once
#include "User.h"
#include "Message.h"
#include <vector>
#include <memory>
class Chat
{
	std::string div = "*****************\n";
	std::vector<User> users_;
	std::vector<Message> messages_;
	std::shared_ptr<User> selectedUser_ = nullptr;
	bool chatStatus_ = false;
public:
	void chatOn();
	void chatOff();
	const bool getStatus() const;
	const std::shared_ptr<User>& getSelectedUser() const;
	void mainMenu();
	void regChat();
	void signIn();
	void userMenu();
	void writeMessage();
	void usersList();
	void signOut();
	void dispChat();
};