CPP = g++
CPPFLAGS = -Wall -Wpedantic -Wextra
EXECUTABLE = p3

# Target is the executable, add dependances
$(EXECUTABLE): main.o
	$(CPP) $(CPPFLAGS) -o $(EXECUTABLE) main.o int_min_heap.o

# define how each object file is to be built (one clause per .cpp file)
main.o: main.cpp
	$(CPP) $(CPPFLAGS) -c main.cpp

# Removes all compiled object files and the executable
clean:
	rm -f ./*.o ./$(EXECUTABLE)