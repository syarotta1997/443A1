
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/timeb.h>

/**
 * populate a random array (which is already
 * allocated with enough memory to hold n bytes.
 */
void random_array(char *array, long bytes);

/**
 * Allocate a fixed amount of memory char buffer[block_size]
 * and repeatedly generate random content into buffer, then
 * write buffer to disk
 */
void create_random_file(char* filename, long bytes, long block_size);


/**
 * file_ptr : the file pointer, ready to be read from.
 * hist: an array to hold 26 long integers.  hist[0] is the
 *       number of 'A', and hist[1] is the number of 'B', etc.
 * block_size: the buffer size to be used.
 * milliseconds: time it took to complete the file scan
 * total_bytes_read: the amount data in bytes read
 *
 * returns: -1 if there is an error.
 */
int get_histogram(
    FILE *file_ptr, 
    long hist[], 
    int block_size, 
    long *milliseconds, 
    long *total_bytes_read);

void calculate_occurance(char* buff, long hist[], int size);