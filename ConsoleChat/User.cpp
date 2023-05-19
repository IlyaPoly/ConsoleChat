#include "User.h"
#include <string>

User::User(const std::string& name, const std::string& login, const std::string& pass): 
	name_(name), login_(login), pass_(pass) {}

void User::setName(const std::string& name)
{
	name_ = name;
}

void User::setPass(const std::string& pass)
{
	pass_ = pass;
}

const std::string& User::getName() const
{
	return name_;
}

const std::string& User::getLogin() const
{
	return login_;
}

const std::string& User::getPass() const
{
	return pass_;
}
