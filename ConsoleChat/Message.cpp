#include "Message.h"

Message::Message(const std::string& to, const std::string from, const std::string text, const std::string name):
	to_(to),from_(from),text_(text)
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