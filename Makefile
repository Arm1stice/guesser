all: Guesser.exe

Guesser.exe: main.cpp
	g++ -o Guesser.exe main.cpp -D_WIN32