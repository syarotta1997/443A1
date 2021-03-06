#include "library.h"

struct timeb t;

int main(int argc, char *argv[]) {
        if (argc != 4) {
            printf("Usage: %s <filename> <total bytes> <block size>\n", argv[0]);
            exit(1);
        }
        char *end;
        long block_size = strtol(argv[3], &end, 10);
        long total_bytes = strtol(argv[2], &end, 10);
        char *buf = (char *) malloc( block_size * sizeof(char));
        
        ftime(&t);
        long now_in_ms = t.time * 1000 + t.millitm;
        
        FILE *fp = fopen(argv[1], "w");
        
        while (total_bytes > 0){
            memset(buf, '\0', block_size);
            random_array(buf, block_size);
            if (total_bytes < block_size){
                fwrite(buf, 1, total_bytes, fp);
                total_bytes = 0;
            }
            else{
                fwrite(buf, 1, block_size, fp);     
                total_bytes -= block_size;
            }
            fflush(fp);  
                   
        }
        ftime(&t);
        now_in_ms = (t.time * 1000 + t.millitm) - now_in_ms;
        printf("FILE = %s \n", argv[1]);
        printf("BLOCK SIZE = %d \n", (int)block_size);
        printf("TIME = %ld milliseconds \n", now_in_ms);
        
        
        fclose(fp);
        free(buf);

        
        return 0;
        
}