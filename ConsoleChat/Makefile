all: consolechat

consolechat: main.o Chat.o Message.o User.o
	g++ main.o Chat.o Message.o User.o -o consolechat
main.o: main.cpp
	g++ -c main.cpp
Chat.o: Chat.cpp
	g++ -c Chat.cpp
Message.o: Message.cpp
	g++ -c Message.cpp
User.o: User.cpp
	g++ -c User.cpp
clean:
	rm -rf *.o