CXX=g++
CXXFLAGS=-Wall -Wextra -std=c++17
SRC=cocp2.cpp parse.cpp vecmath.cpp util.cpp
LDFLAGS=-lc -lstdc++
EXE=cobaltocene

run: db_exe
	./$(EXE) "Fe(CF3SO3)2"
db_exe:
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -g3 $(SRC) -o $(EXE)
