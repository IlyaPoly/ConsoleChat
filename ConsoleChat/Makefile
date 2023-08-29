all: consolechat

consolechat: main.o chat.o message.o user.o
	g++ main.o chat.o message.o user.o -o consolechat
main.o: main.cpp
	g++ -c consolechat main.cpp
chat.o: Chat.cpp
	g++ -c Chat.cpp
message.o: Message.cpp
	g++ -c Message.cpp
user.o: User.cpp
	g++ -c User.cpp
clean:
	rm -rf *.o