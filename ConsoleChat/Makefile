all: consolechat

consolechat: main.o chat.o message.o user.o
^Ig++ main.o chat.o message.o user.o -o consolechat
main.o: main.cpp
^Ig++ -c consolechat main.cpp
chat.o: chat.cpp
^Ig++ -c chat.cpp
message.o: message.cpp
^Ig++ -c message.cpp
user.o: user.cpp
^Ig++ -c user.cpp
clean:
^Irm -rf *.o
