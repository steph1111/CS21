CPP = g++
CPPFLAGS = -Wall -Wpedantic -Wextra
EXECUTABLE = p8

# Target is the executable, add dependances
$(EXECUTABLE): main.o maze.o
	$(CPP) $(CPPFLAGS) $^ -o $@

# define how each object file is to be built (one clause per .cpp file)
main.o: main.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

maze.o: maze.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

# Removes all compiled object files and the executable
clean:
	rm -f ./*.o ./$(EXECUTABLE)