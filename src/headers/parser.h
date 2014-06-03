#include <string.h>
#include <stdlib.h>

void parse(char *data)
{
    char *token;
   
    token = strtok(data, " ");
   
    while (token != NULL) 
    {
        printf("%s\n", token);
        token = strtok(NULL, " ");
    }
}
