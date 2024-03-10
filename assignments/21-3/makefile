CPP = g++
CPPFLAGS = -Wall -Wpedantic -Wextra
EXECUTABLE = p3

# Target is the executable, add dependances
$(EXECUTABLE): quick_sort.o
	$(CPP) $(CPPFLAGS) -o $(EXECUTABLE) quick_sort.o

# define how each object file is to be built (one clause per .cpp file)
quick_sort.o: quick_sort.cpp
	$(CPP) $(CPPFLAGS) -c quick_sort.cpp

# Removes all compiled object files and the executable
clean:
	rm -f ./*.o ./$(EXECUTABLE)