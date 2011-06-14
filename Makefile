compile:
	@gcc -Wall main.c tictactoe.h -o main

test: 
	@gcc -Wall test.c tictactoe.h -o game_tests && ./game_tests

run: compile
	@./main
