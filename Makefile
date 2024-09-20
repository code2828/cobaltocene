CXX=g++
CXXFLAGS=-Wall -Wextra -std=c++17
SRC=cocp2.cpp
LDFLAGS=-lc -lstdc++
EXE=cobaltocene

run: db_exe
	./$(EXE)
db_exe:
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -g3 $(SRC) -o $(EXE)
