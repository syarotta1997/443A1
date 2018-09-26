#include "library.h"

void random_array(char* array, long bytes){
    for (int i = 0; i < (int)bytes ; i++){
        int offset = rand() % 26;
        array[i] =  'A' + (offset);
    }
}
