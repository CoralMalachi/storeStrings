#include <stdio.h>
#include <stdlib.h> 
#include "help.h"

/*
url : https://stackoverflow.com/questions/314401/how-to-read-a-line-from-the-console-in-c
*/
char* read_line(char* line) {

	int c;
	line = malloc(sizeof(char));
	//checking if allocation was successful or not
	if (line == NULL)
	{
		printf("%s\n", "Allocation failed");
		exit(1);
	}
	
	/*
	unsigned type might be seen used as loop variable as loop variables 
	are typically greater than or equal to 0
	*/	

	size_t i = 0;	
	while ((c = getchar()) != '\n' && c != EOF)
	{
		//type casting `int` to `char`, since getchar return int
		line[i] = (char)c;
		i++;
		line = realloc(line, (i + 1) * sizeof(char));
		if (line == NULL) {
			printf("%s\n", "Reallocation failed");
			exit(1);
		}	
	}
	//inserting null character at the end
	line[i ] = '\0';


	return line;
}

size_t insert_line(char** line)
{
	int c;
	*line = malloc(sizeof(char));
	//checking if allocation was successful or not
	if (*line == NULL)
	{
		printf("%s\n", "Allocation failed");
		exit(1);
	}

	/*
	unsigned type might be seen used as loop variable as loop variables
	are typically greater than or equal to 0
	*/

	size_t i = 0;
	//*line[i] = '\0';
	while ((c = getchar()) != '\n' && c != EOF)
	{
		//type casting `int` to `char`, since getchar return int
		(*line)[i] = (char)c;
		i++;
		*line = realloc(*line, (i + 1) * sizeof(char));
		if (*line == NULL) {
			printf("%s\n", "Reallocation failed");
			exit(1);
		}
	}
	//inserting null character at the end
	(*line)[i] = '\0';


	return i;
}
