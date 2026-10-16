#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *txtFile;

    // Check if args passed to prgm.
    if(argc > 1) {
        int c;
        int count = 0;

        int charReadint;
        int charReadcount = 0;
        txtFile = fopen(argv[1], "r");
        if(txtFile == NULL) printf("Your file you passed does not exist or couldn't be found/opened!\n");
        else { 
            printf("File opened successfully...\n");
            printf("Here are the stats of file... %s\n\n", argv[1]);
            for (c=getc(txtFile); c != EOF; c = getc(txtFile)) {
                if (c == '\n') count++;
            }
            //C uses a pointer to read files. That is why we rewind to the beginning. (Weird, isn't it!)
            rewind(txtFile);
            for (charReadint = getc(txtFile); charReadint != EOF; charReadint = getc(txtFile)) {
                charReadcount++;
            }
            
            
        }
        printf("Lines: %d\n", count);
        printf("Characters: %d\n", charReadcount);
        rewind(txtFile);
        // Move the file pointer to the end of the file to get the size.
        fseek(txtFile,0,SEEK_END);
        long int res = ftell(txtFile);
        printf("File size: %ld bytes\n", res);
    } else {
        printf("You did not supply an argument!\n");
    }
    return 0;
}