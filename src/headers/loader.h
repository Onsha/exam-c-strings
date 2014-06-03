#include <stdlib.h>

char *getContent(char *filename)
{
    FILE *input;
    char *data;
    
    if (NULL == (input = fopen(filename, "rb"))) {
        printf("Error: Unable to open file: %s\n", filename);
        return NULL;
    }
    
    if (NULL == (data = malloc(getFileSize(input)))) {
        printf("Error: Malloc failed");
        return NULL;
    }
    
    fread(data, getFileSize(input), 1, input);
    
    if (0 != fclose(input)) {
        printf("Warning: Unable to close file: %s\n", filename);
    }
    
    return data;
}

int getFileSize(FILE *file)
{
    int filesize = 0;
    
    fseek(file, 0L, SEEK_END);
    filesize = ftell(file);
    fseek(file, 0L, SEEK_SET);
    
    return filesize;
}
