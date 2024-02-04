CPP = g++
CPPFLAGS = -Wall -Wpedantic -Wextra
EXECUTABLE = queue

# Target is the executable, add dependances
$(EXECUTABLE): main.o list.o queue.o
	$(CPP) $(CPPFLAGS) -o $(EXECUTABLE) main.o list.o queue.o

# define how each object file is to be built (one clause per .cpp file)
main.o: main.cpp queue.h
	$(CPP) $(CPPFLAGS) -c main.cpp

queue.o: queue.cpp queue.h list.cpp list.h
	$(CPP) $(CPPFLAGS) -c queue.cpp

list.o: list.cpp list.h
	$(CPP) $(CPPFLAGS) -c list.cpp

# Removes all compiled object files and the executable
clean:
	rm -f ./*.o ./$(EXECUTABLE)