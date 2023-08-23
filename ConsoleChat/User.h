#pragma once
#include <string>

class User
{
	std::string name_;
	std::string login_;
	std::string pass_;
public:
	User(const std::string& name, const std::string& login, const std::string& pass);
	User() = default;
	void setName(const std::string& name);
	void setPass(const std::string& pass);
	const std::string& getName() const;
	const std::string& getLogin() const;
	const std::string& getPass() const;
	friend std::ostream& operator<<(std::ostream& os, const User& obj);
	friend std::istream& operator>>(std::istream& os, User& obj);
};

