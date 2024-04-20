# Compiler and compiler flags
CXX = g++
CXXFLAGS = -g -Wall -Wextra -Wpedantic

# Phony target for 'make all'
.PHONY: all
all: Restaurant Test

# Target to build the executable 'Restaurant' using object files
Restaurant: main.o menu.o
	$(CXX) $(CXXFLAGS) -o $@ $^

#Target to build the executable 'Test' using object files
Test: test.o menu.o catch_amalgamated.o
	$(CXX) $(CXXFLAGS) -o $@ $^

#Target to build 'catch_amalgamated.o' from it's source file
catch_amalgamated.o: catch_amalgamated.cpp catch_amalgamated.hpp
	$(CXX) $(CXXFLAGS) -c $<

#Target to build 'test.o' from it's source file
test.o: test.cpp catch_amalgamated.hpp menu.h
	$(CXX) $(CXXFLAGS) -c $<

# Target to build 'main.o' from its source file
main.o: main.cpp menu.h
	$(CXX) $(CXXFLAGS) -c $<

# Target to build 'menu.o' from its source file
menu.o: menu.cpp menu.h
	$(CXX) $(CXXFLAGS) -c $<

# Phony target for cleaning up generated files
.PHONY: clean
clean:
	$(RM) *.o    # Remove all object files
	$(RM) Restaurant  # Remove the executable 'Restaurant'
	$(RM) Test
