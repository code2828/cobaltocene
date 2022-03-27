CXX=g++
CXXFLAGS=-Wall -Wextra -std=c++2a
LD=ld
LDFLAGS=-lc -lc++ -lstdc++ -lm -lncurses -lncurses_g -lncurses++ -lncurses++_g -ljemalloc

db_exe: db_obj
	$(LD) $(LDFLAGS) *.o -o whatever
db_obj:
	$(CXX) $(CXXFLAGS) -c -g3 *.cpp
