all: consolechat

consolechat: main.o chat.o message.o user.o
        g++ main.o chat.o message.o user.o -o consolechat
main.o: main.cpp
        g++ -c consolechat main.cpp
chat.o: chat.cpp
        g++ -c chat.cpp
message.o: message.cpp
        g++ -c message.cpp
user.o: user.cpp
        g++ -c user.cpp
clean:
        rm -rf *.o
