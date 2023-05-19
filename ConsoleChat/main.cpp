#include <iostream> 
#include <conio.h>
#include <string>
#include "Chat.h"
using namespace std;

int main()
{
	Chat chat;
	chat.chatOn();
	do {
		if (chat.getSelectedUser())
			chat.userMenu();
		else 
			chat.mainMenu();
	} while (chat.getStatus());
}