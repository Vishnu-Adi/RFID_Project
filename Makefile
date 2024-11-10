CXX = g++
CXXFLAGS = -std=c++11 -I./src -I./tests
LDFLAGS =

SRC = $(wildcard src/**/*.cpp src/*.cpp)
TEST_SRC = $(wildcard tests/*.cpp)
OBJ = $(SRC:.cpp=.o)
TEST_OBJ = $(TEST_SRC:.cpp=.o)

all: main tests

main: $(OBJ)
    $(CXX) $(CXXFLAGS) -o bin/main $^ $(LDFLAGS)

tests: $(OBJ) $(TEST_OBJ)
    $(CXX) $(CXXFLAGS) -o bin/tests $^ -lgtest $(LDFLAGS)

clean:
    rm -f $(OBJ) $(TEST_OBJ) bin/main bin/tests