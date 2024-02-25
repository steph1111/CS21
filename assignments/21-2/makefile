CPP = g++
CPPFLAGS = -Wall -Wpedantic -Wextra
EXECUTABLE = p2

# Target is the executable, add dependances
$(EXECUTABLE): main.o int_min_heap.o
	$(CPP) $(CPPFLAGS) -o $(EXECUTABLE) main.o int_min_heap.o

# define how each object file is to be built (one clause per .cpp file)
main.o: main.cpp int_min_heap.h
	$(CPP) $(CPPFLAGS) -c main.cpp

int_min_heap.o: int_min_heap.cpp int_min_heap.h
	$(CPP) $(CPPFLAGS) -c int_min_heap.cpp

# Removes all compiled object files and the executable
clean:
	rm -f ./*.o ./$(EXECUTABLE)