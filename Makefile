CXX=g++
CXXFLAGS=-Wall -Wextra -std=c++17
SRC=cocp2.cpp parse.cpp vecmath.cpp util.cpp
LDFLAGS=-lc -lstdc++
EXE=cobaltocene

run: db_exe
	./$(EXE) "(NH4)2(Ce(NO3)6)"
db_exe:
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -g3 $(SRC) -o $(EXE)
