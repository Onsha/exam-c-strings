#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *content;
    int size  = 0;
    int words = 0;
    int error = 1;
} filedata;

typedef struct {
    char *text;
    int length = 0;
} word;

void _ui_ask_file(char *path)
{   
    printf("Укажите путь к файлу с текстом: ");
    scanf("%s", path);
}

int get_words_count(const char sentence[ ])
{
    int counted = 0;

    const char* it = sentence;
    int inword = 0;

    do switch(*it) {
        case '\0': 
        case ' ': case '\t': case '\n': case '\r':
            if (inword) { inword = 0; counted++; }
            break;
        default: inword = 1;
    } while(*it++);

    return counted;
}

int get_file_size(FILE *file)
{
    int filesize = 0;
    
    fseek(file, 0L, SEEK_END);
    filesize = ftell(file);
    fseek(file, 0L, SEEK_SET);
    
    return filesize;
}

filedata get_filedata(char *filename)
{
    FILE *input;
    filedata data;
    
    if (NULL == (input = fopen(filename, "rb"))) {
        printf("Ошибка: Невозможно открыть файл  '%s'.\n", filename);
        return;
    }
    
    data.size = get_file_size(input);
    
    if (NULL == (data.content = malloc(data.size))) {
        printf("Ошибка: Не удалось выделить память.");
        return;
    }
    
    fread(data.content, data.size, 1, input);
    
    if (0 != fclose(input)) {
        printf("Предупреждение: Не удалось закрыть файл '%s'.\n", filename);
    }
    
    
    
    data.error = 0;
    
    return data;
}

int main()
{
    char filename[255];
    filedata data;
    
    _ui_ask_file(filename);
    
    data = get_filedata(filename);
    
    if (data.error == 1) {
        return 0;
    }
    
    printf("Content: %s\nSize: %d\n", data.content, data.size);
    
    return 0;
}


//~ int test()
//~ {
    //~ 
    //~ char *data = getContent("text.txt"), *token, words[255][255];
    //~ int i = 0, j = 0;
    //~ 
    //~ if (NULL == data) {
        //~ return 0;
    //~ }
        //~ 
    //~ token = strtok(data, " ,.");
    //~ 
    //~ while (token != NULL)  {
        //~ strcpy(words[j], token);
        //~ token = strtok(NULL, " ,.");
        //~ ++j;
    //~ }
    //~ 
    //~ for (i = 0; i < j; ++i) {
        //~ printf("%s ", words[i]);
    //~ }
    //~ 
    //~ printf("\n\n");
    //~ 
    //~ return 1;
//~ }
