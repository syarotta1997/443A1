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
        
        long now_in_ms = t.time * 1000 + t.millitm;
        
        FILE *fp = fopen(argv[1], "w");
        
        while (total_bytes > 0){
            random_array(buf, block_size);
            fwrite(buf, 1, block_size, fp);
            total_bytes -= block_size;
        }
        fflush(fp);
        fclose(fp);
        free(buf);
        
        now_in_ms = (t.time * 1000 + t.millitm) - now_in_ms;
        fprintf("Finished writing to file in &.2f", &now_in_ms);
        
        return 0;
        
}