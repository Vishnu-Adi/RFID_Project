CXX = g++
CXXFLAGS = -std=c++11 -I./src -I./tests
LDFLAGS =

SRC = $(wildcard src/**/*.cpp src/*.cpp)
TEST_SRC = $(wildcard tests/*.cpp)
OBJ = $(SRC:.cpp=.o)
TEST_OBJ = $(TEST_SRC:.cpp=.o)

all: main tests

main: $(OBJ)
\t$(CXX) $(CXXFLAGS) -o bin/main $^ $(LDFLAGS)

