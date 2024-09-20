CXX=g++
CXXFLAGS=-Wall -Wextra -std=c++2a
LD=ld
LDFLAGS=-lc
PROJ=cobaltocene

run: db_exe
	./$(PROJ)
db_exe: db_obj
	$(LD) $(LDFLAGS) *.o -o $(PROJ)
db_obj:
	$(CXX) $(CXXFLAGS) -c -g3 *.cpp
