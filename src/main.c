#include <stdio.h>
#include "headers/loader.h"
#include "headers/parser.h"

int main()
{	
	char *data = getContent("text.txt"), *words;
	int i;
	
	if (NULL == data) {
		return 0;
	}
	
	
	parse(data);
	
	return 1;
}
