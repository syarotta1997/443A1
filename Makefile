all: create_random_file get_histogram
 
create_random_file: create_random_file.c library.o
    gcc -c -Wall -g -o $@ $< library.o
 
get_histogram: get_histogram.c library.o
    gcc -c -Wall -g -o $@ $< library.o

%.o: %.c
	gcc -c -Wall -g -o $@ $<