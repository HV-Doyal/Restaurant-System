# Compiler and compiler flags
CXX = g++
CXXFLAGS = -g -Wall -Wextra -Wpedantic

# Phony target for 'make all'
.PHONY: all
all: restaurant

# Target to build the executable 'restaurant' using object files
restaurant: Restaurant.o staff.o
	$(CXX) $(CXXFLAGS) -o $@ $^

# Target to build 'Restaurant.o' from its source file
Restaurant.o: Restaurant.cpp staff.h
	$(CXX) $(CXXFLAGS) -c $<

# Target to build 'staff.o' from its source file
staff.o: staff.cpp staff.h
	$(CXX) $(CXXFLAGS) -c $<

# Phony target for cleaning up generated files
.PHONY: clean
clean:
	$(RM) *.o    # Remove all object files
	$(RM) restaurant  # Remove the executable 'restaurant'