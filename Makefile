# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall -O2

# Target executable
TARGET = project

# Source files
SRCS = main.cpp Scene.cpp Player.cpp EquipmentList.cpp Equipment.cpp ContinuousEquipment.cpp Character.cpp Enemy.cpp Mob.cpp Boss.cpp Shop.cpp Mystery.cpp Winners.cpp Run.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Build and run
all: $(TARGET)
	./$(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Cleanup
clean:
	rm -f $(TARGET) $(OBJS)