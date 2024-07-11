CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

SRC = main.cpp graph.cpp kosaraju.cpp
HEADERS = graph.hpp kosaraju.hpp
OBJ = $(SRC:.cpp=.o)
EXEC = kosaraju_scc

all: $(EXEC)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@

clean:
	rm -f $(OBJ) $(EXEC)

