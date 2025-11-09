cc = g++  # use g++ compiler
path = ..
standard = c++17

flags = -std=$(standard)  # with standard
flags += -Wall -pedantic -g -I $(path)

link = $(cc) $(flags) -o

compile = $(cc) $(flags) -c -o


tictac.o : src/tictac.cc inc/tictac.h
	$(compile) $@ $<

tictac : tictac.o
	$(link) $@ $<

tictactoe : tictac
	./tictac

clean:
	$(RM) tictac tictac.o