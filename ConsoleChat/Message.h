#pragma once
#include <string>
class Message
{
	std::string to_;
	std::string from_;
	std::string text_;
	std::string fromPname;
public:
	Message(const std::string& to, const std::string from, const std::string text, const std::string name);
	const std::string& getTo() const;
	const std::string& getFrom() const;
	const std::string& getText() const;
	const std::string& getFromPname() const;
};

