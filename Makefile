all: create_random_file get_histogram
 
create_random_file: create_random_file.c library.o
	gcc -Wall -g -o $@ $< library.o
 
get_histogram: get_histogram.c library.o
	gcc -Wall -g -o $@ $< library.o

%.o: %.c
	gcc -c -Wall -g -o $@ $<

clean:
	rm -f *.o create_random_file get_histogram file1 file2 file3 file4 file5 file6 file7 file8 file9 file10 result.txt