# Compiler & Flags
CXX = g++
CXXFLAGS = -Wall -std=c++17 -O2

# Source and Object Files
SRCS = packet.cpp graph.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)

# Output Executable
TARGET = main

# Default Rule
all: $(TARGET)

# Link Object Files into Executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile Each .cpp into .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

# Run the Program After Build
run: all
	./$(TARGET)

# Remove Build Artifacts
clean:
	rm -f $(OBJS) $(TARGET)

# Phony Targets (not actual files)
.PHONY: all clean run