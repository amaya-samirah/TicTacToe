cc = g++  # use g++ compiler
path = ..
standard = c++17

flags = -std=$(standard)  # with standard
flags += -Wall -pedantic -g -I $(path)

link = $(cc) $(flags) -o

compile = $(cc) $(flags) -c -o

tictac : tictac.o
	$(link) $@ $<

tictac.o : tictac.cc
	$(compile) $@ $<

clean:
	$(RM) tictac tictac.o