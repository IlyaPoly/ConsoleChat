#include "Chat.h"
#include <iostream>
void Chat::chatOn()
{
	chatStatus_ = true;
}

void Chat::chatOff()
{
	chatStatus_ = false;
}

const bool Chat::getStatus() const
{
	return chatStatus_;
}

const std::shared_ptr<User>& Chat::getSelectedUser() const
{
	return selectedUser_;
}

void Chat::mainMenu()
{
	char act;
	std::cout << div << "Choose an action:\n1 - Reg in chat\n2 - Sign in\n0 - quit" << std::endl;
	std::cin >> act;
	switch (act-48) {
	case 0:
		chatOff();
		break;
	case 1:
		regChat();
		break;
	case 2:
		signIn();
		break;
	default:
		std::cout << "Unknnow command!" << std::endl;
	}
}

void Chat::regChat()
{
	std::string name, login, pass;
	auto allow = 0;
	std::system("cls");
	std::cout << "Input your name : ";
	std::cin >> name;
	 do{
		std::cout << "Input login : ";
		std::cin >> login;
		allow = 0;
		for (auto& user : users_)
		{
			if (login == user.getLogin())
			{
				std::cout << "Login is busy!" << std::endl;
				break;
			}
			else
			{
				allow ++;
			}
		}
	}while (allow!=users_.size());
	std::cout << "Input password : ";
	std::cin >> pass;
	users_.push_back(User(name, login, pass));
}

void Chat::signIn()
{
	std::string login, pass;
	bool allow = false;
	std::system("cls");
	if (!(users_.empty()))
	{
		std::cout << "Input your login: ";
		std::cin >> login;
		for (auto& user : users_)
		{
			if (login == user.getLogin())
				allow = true;
		}
		if (allow)
		{
			std::cout << "Input your passwod: ";
			std::cin >> pass;
		}
		else
		{
			std::cout << "Accoun isn't found!" << std::endl;
			return;
		}
		for (auto& user : users_)
		{
			if (pass == user.getPass())
			{
				allow = false;
				selectedUser_ = std::make_shared<User>(user);
				break;
			}
		}
		if (allow) std::cout << "Wrong password!" << std::endl;
	}
	else std::cout << "No registered accounts!" << std::endl;

}

void Chat::userMenu()
{
	char act;
	std::cout<< div << "Choose an action:\n1 - Write message\n2 - Users list\n3 - Display chat\n0 - Sign out" << std::endl;
	std::cin >> act;
	switch (act-48) {
	case 0:
		signOut();
		break;
	case 1:
		writeMessage();
		break;
	case 2:
		usersList();
		break;
	case 3:
		dispChat();
		break;
	default:
		std::cout << "Unknnow command!" << std::endl;
	}
}

void Chat::writeMessage()
{
	std::string to;
	std::string from;
	std::string text;
	bool find = false;
	std::system("cls");
	std::cout << "Write login recipient or 'all' : ";
	std::cin >> to;
	for (auto& user : users_)
	{
		if (to == user.getLogin())
			if (to == selectedUser_->getLogin())
			{
				std::cout << "You can't write a message to yourself!" << std::endl;
				return;
			}
			else
				find = true;
	}
	if (find || to == "all")
	{
		std::cout << "Write your message : ";
		std::cin.ignore();
		std::getline(std::cin, text);
		messages_.push_back(Message(to, selectedUser_->getLogin(), text, selectedUser_->getName()));
	}
	else
		std::cout << "User not found!" << std::endl;
}

void Chat::usersList()
{
	std::string out;
	std::system("cls");
	std::cout << "     Users :" << std::endl;
	for (auto& user : users_)
	{
		out.clear();
		if (user.getLogin() == selectedUser_->getLogin())
			out = " (this account)";
		std::cout << "Login : '" << user.getLogin()<< "' " << out << std::endl;
	}
	std::cout << std::endl;
}

void Chat::signOut()
{
	selectedUser_ = nullptr;
}

void Chat::dispChat()
{
	std::system("cls");
	if (!messages_.size())
		std::cout << "Chat is clear!" << std::endl;
	for (auto& messages : messages_)
	{
		if ((selectedUser_->getLogin() == messages.getFrom() || selectedUser_->getLogin() == messages.getTo() || messages.getTo() == "all"))
		{
			std::cout << div << "From : " << messages.getFromPname() << "\nTo : " << messages.getTo() << "\nText : " << messages.getText() << std::endl;
		}
	}
}
