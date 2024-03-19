CPP = g++
CPPFLAGS = -Wall -Wpedantic -Wextra
EXECUTABLE = p5

# Target is the executable, add dependances
$(EXECUTABLE): main.o hash_table.o
	$(CPP) $(CPPFLAGS) -o $(EXECUTABLE) main.o hash_table.o

# define how each object file is to be built (one clause per .cpp file)
main.o: main.cpp hash_table.h str_record.h
	$(CPP) $(CPPFLAGS) -c main.cpp

hash_table.o: hash_table.cpp hash_table.h record.h
	$(CPP) $(CPPFLAGS) -c hash_table.cpp

str_record.o: str_record.cpp str_record.h record.h
	$(CPP) $(CPPFLAGS) -c str_record.cpp

# Removes all compiled object files and the executable
clean:
	rm -f ./*.o ./$(EXECUTABLE)