#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/loader.h"
//~ #include "headers/parser.h"

int main()
{   
    char *data = getContent("text.txt"), *token, words[255][255];
    int i = 0, j = 0;
    
    if (NULL == data) {
        return 0;
    }
        
    token = strtok(data, " ,.");
    
    while (token != NULL) 
    {
        strcpy(words[j], token);
        token = strtok(NULL, " ,.");
        ++j;
    }
    
    for (i = 0; i < j; ++i) {
        printf("%s ", words[i]);
    }
    
    printf("\n\n");
    
    return 1;
}
