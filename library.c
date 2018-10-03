#include "library.h"
/**
 * Allocate a fixed amount of memory char buffer[block_size]
 * and repeatedly generate random content into buffer, then
 * write buffer to disk
 */
void random_array(char* array, long bytes){
    for (int i = 0; i < (int)bytes ; i++){
        int offset = rand() % 26;
        array[i] =  'A' + (offset);
    }
}
