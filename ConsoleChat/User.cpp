#include "User.h"
#include <string>
#include <iostream>

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

std::ostream& operator<<(std::ostream& os, const User& obj)
{
	os << obj.name_;
	os << ' ';
	os << obj.login_;
	os << ' ';
	os << obj.pass_;
	os << ' ';
	return os;
}

std::istream& operator>>(std::istream& os, User& obj)
{
	os >> obj.name_;
	os >> obj.login_;
	os >> obj.pass_;
	return os;
}
