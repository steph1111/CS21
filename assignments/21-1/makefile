CPP = g++
CPPFLAGS = -Wall -Wpedantic -Wextra
EXECUTABLE = p1

# Target is the executable, add dependances
$(EXECUTABLE): main.o list.o stack.o
	$(CPP) $(CPPFLAGS) -o $(EXECUTABLE) main.o list.o stack.o

# define how each object file is to be built (one clause per .cpp file)
main.o: main.cpp stack.h
	$(CPP) $(CPPFLAGS) -c main.cpp

stack.o: stack.cpp stack.h list.cpp list.h
	$(CPP) $(CPPFLAGS) -c stack.cpp

list.o: list.cpp list.h
	$(CPP) $(CPPFLAGS) -c list.cpp

# Removes all compiled object files and the executable
clean:
	rm -f ./*.o ./$(EXECUTABLE)