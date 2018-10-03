#include "library.h"
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
int get_histogram(FILE *file_ptr, long hist[], int block_size, long *milliseconds, long *total_bytes_read){

    //checking if file is valid first
    if (file_ptr == NULL){
            perror("Cannot open file: ");
            return -1;
     }
    
    struct timeb t;
    char *buf = (char*) malloc( block_size * sizeof(char));
    int num_read = 1;
    
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
    //checks if all bytes are read from file
    fseek(file_ptr, 0, SEEK_END);
    long bytes = ftell(file_ptr);
    rewind(file_ptr);
    
    if (bytes == *total_bytes_read)
        return 0;
    else
        return -1;
}

//checks the number of occurence of alphaberical letters and records into an array
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
        long milliseconds = 0;
        long filelen = 0;
        FILE *file_ptr = fopen(argv[1], "r");
        


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
        printf("BLOCK SIZE: %d bytes\n", block_size);
        printf("TOTAL BYTES: %ld bytes\n", filelen);
        printf("TIME: %ld ms\n", milliseconds);
        printf("Data rate: %f Bps\n", (double)filelen/milliseconds * 1000);
        
        fclose(file_ptr );
        
        return 0;

}