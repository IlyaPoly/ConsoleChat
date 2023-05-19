#pragma once
#include <string>
class User
{
	std::string name_;
	const std::string login_;
	std::string pass_;
public:
	User(const std::string& name, const std::string& login, const std::string& pass);
	void setName(const std::string& name);
	void setPass(const std::string& pass);
	const std::string& getName() const;
	const std::string& getLogin() const;
	const std::string& getPass() const;
};

