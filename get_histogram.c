#include "library.h"

int get_histogram(FILE *file_ptr, long hist[], int block_size, long *milliseconds, long *total_bytes_read){
    struct timeb t;
    char *buf = (char*) malloc( block_size * sizeof(char));
    int num_read = 1;
    
    //todo - add error handling
    
    
    memset(hist, 0, sizeof(long)*26);
    
    ftime(&t);
    long now_in_ms = t.time * 1000 + t.millitm;
    while ( num_read >0 ){      
            bzero(buf, block_size);
            num_read = fread(buf, 1, block_size, file_ptr);

            if (num_read > 0){
                calculate_occurance(buf, hist, block_size);
            }
            *total_bytes_read += (long)num_read;
    }
    ftime(&t);
    *milliseconds = (long)(t.time * 1000 + t.millitm - now_in_ms);
    free(buf);
    return 0;
}

void calculate_occurance(char* buff, long hist[], int size){
    
            for (int i = 0; i < size; i ++){
                    char ch = buff[i];
                    if (ch != '\0'){
                        int index = (int)ch - 65;
                        hist[index]+= 1;
                    }
                    
             }
    
}

int main(int argc, char *argv[]) {
    
        if (argc != 3) {
            printf("Usage: %s <filename> <block size>\n", argv[0]);
            exit(1);
        }
        char *end;
        int block_size = (int)strtol(argv[2], &end, 10);
        long hist[26];
        long milliseconds;
        long filelen;
        FILE *file_ptr = fopen(argv[1], "r");
        
        if (file_ptr == NULL){
            perror("Cannot open file: ");
            return -1;
        }

        /**
         * Compute the histogram using 2K buffers
         */
        int ret = get_histogram( file_ptr, 
                                 hist, 
                                 block_size,
                                 &milliseconds,
                                 &filelen);
        assert(! (ret < 0));

        printf("Computed the histogram in %ld ms.\n", milliseconds);
        for(int i=0; i < 26; i++) {
            printf("%c : %ld\n", 'A' + i, hist[i]);
        }
        printf("Data rate: %f Bps\n", (double)filelen/milliseconds * 1000);
        
        fflush(file_ptr );
        fclose(file_ptr );
        
        return 0;

}