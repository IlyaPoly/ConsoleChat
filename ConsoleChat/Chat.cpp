#include "Chat.h"
#include <iostream>
#include <fstream>
#define FILEUSERS "users.txt"
#define FILEMESS "messages.txt"
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
	
	load(FILEUSERS, users_);
	load(FILEMESS, messages_);
	std::cout << div << "Choose an action:\n1 - Reg in chat\n2 - Sign in\n0 - quit" << std::endl;
	std::cin >> act;
	switch (act-48) {
	case 0:
	{
		chatOff();
		upload(FILEUSERS, users_);
		upload(FILEMESS, messages_);
		break;
	}
	case 1:
		regChat();
		break;
	case 2:
		signIn();
		break;
	default:
		std::cout << "Unknown command!" << std::endl;
	}
}

void Chat::regChat()
{
	std::string name, login, pass;
	auto allow = 0;
	std::system("clear");
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
	std::system("clear");
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
	std::system("clear");
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
	std::system("clear");
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
	std::system("clear");
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

template<typename T>
inline void Chat::load(std::string file_path, std::vector<T>& mass)
{
	std::fstream file = std::fstream(file_path, std::ios::in);
	if (!file)
	{
		std::cout << "Download from the file cannot be finished, file not found!";
		return;
	}
	file.seekg(0, std::ios_base::beg);
	while (!file.eof())
	{
		if (!file.eof())
		mass.push_back(T());
		file >> mass.back();
	}
	file.close();
}

template<class T>
void Chat::upload(std::string file_path, std::vector<T>& mass)
{
	std::fstream file = std::fstream(file_path, std::ios::out | std::ios::trunc);
		if (!file)
			std::cout << "Download from the file cannot be finished, file not found!";
		file.seekg(0, std::ios_base::beg);
		for (auto& i : mass)
		{
			file << i;
		}
}
