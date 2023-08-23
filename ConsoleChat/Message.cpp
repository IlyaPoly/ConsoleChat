#include "Message.h"
#include <iostream>

Message::Message(const std::string& to, const std::string from, const std::string text, const std::string name):
	to_(to),from_(from),text_(text), name_(name)
{
	fromPname = from_ + " (" + name + ")";
}

const std::string& Message::getTo() const
{
	return to_;
}

const std::string& Message::getFrom() const
{
	return from_;
}

const std::string& Message::getText() const
{
	return text_;
}

const std::string& Message::getFromPname() const
{
	return fromPname;
}

std::ostream& operator<<(std::ostream& os, const Message& obj)
{
	os << obj.to_;
	os << ' ';
	os << obj.from_;
	os << ' ';
	os << obj.name_;
	os << ' ';
	os << obj.text_;
	os << '\n';
	return os;
}

std::istream& operator>>(std::istream& os, Message& obj)
{
	os >> obj.to_;
	os >> obj.from_;
	os >> obj.name_;
	std::getline(os, obj.text_);
	return os;
}