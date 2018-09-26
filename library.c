#include "library.h"

void random_array(char* array, long bytes){
    for (int i = 0; i < (int)bytes ; i++){
        arrray[i] =  'A' + (rand() % 26);
    }
}
