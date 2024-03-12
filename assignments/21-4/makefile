CPP = g++
CPPFLAGS = -Wall -Wpedantic -Wextra
EXECUTABLE = p4

# Target is the executable, add dependances
$(EXECUTABLE): radix_bucket_sort.o
	$(CPP) $(CPPFLAGS) -o $(EXECUTABLE) radix_bucket_sort.o

# define how each object file is to be built (one clause per .cpp file)
radix_bucket_sort.o: radix_bucket_sort.cpp
	$(CPP) $(CPPFLAGS) -c radix_bucket_sort.cpp

# Removes all compiled object files and the executable
clean:
	rm -f ./*.o ./$(EXECUTABLE)