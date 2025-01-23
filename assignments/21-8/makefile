CPP = g++
CPPFLAGS = -Wall -Wpedantic -Wextra
EXECUTABLE = p7

# Target is the executable, add dependances
$(EXECUTABLE): main.o
	$(CPP) $(CPPFLAGS) $^ -o $@

# define how each object file is to be built (one clause per .cpp file)
main.o: main.cpp 
	$(CPP) $(CPPFLAGS) -c $< -o $@

# binary_search_tree.o: binary_search_tree.cpp
# 	$(CPP) $(CPPFLAGS) -c $< -o $@

# Removes all compiled object files and the executable
clean:
	rm -f ./*.o ./$(EXECUTABLE)
