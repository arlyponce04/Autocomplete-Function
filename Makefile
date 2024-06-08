#Define Compiler
CC = clang++

#Define Compiler Flags
CFLAGS = -pedantic

#Link Objects to Create Executable
autocomplete-big-list: autocomplete-big-list.o
	$(CC) $(CFLAGS) -o autocomplete-big-list autocomplete-big-list.o

#Compile Source File into Object File
autocomplete-big-list.o: autocomplete-big-list.cpp
	$(CC) $(CFLAGS) -c autocomplete-big-list.cpp

#Clean Generated Files to Start Over 
clean:
	rm -f autocomplete-big-list.o autocomplete-big-list


#Test Files using Top 10
test: 
	./autocomplete-big-list ./cities2.txt 10
