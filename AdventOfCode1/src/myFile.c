/*
 * inputFile.c
 *
 *  Created on: 02.12.2022
 *      Author: maximilian
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "List.h"
#include "myFile.h"

void inputFileToList(FILE *input, List *list)
{
	char line[MAX_LINE_LEANGH] = {0};

	char c = '\0';
	int len = 0;

	while(c != EOF)
	{
		do
		{
			c = (char) fgetc(input);
			line[len] = c;

		}while(c != '\n' && c != EOF && ++len < MAX_LINE_LEANGH - 1);

		line[len] = '\0';

		pushElement(list, createElement(line));

		len = 0;
	}
}

void clearFile(FILE *output)
{
	while(fgetc(output) != EOF)
	{
		fputc(0, output);
	}
}

void wirteLineToFile(FILE *file, char *str)
{
	int len = strlen(str);

	for (int i = 0; i < len; i++)
	{
		fputc((int)str[i], file);
	}
	fputc((int)'\n', file);
}




