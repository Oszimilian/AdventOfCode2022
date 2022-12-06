/*
 * day6.c
 *
 *  Created on: 06.12.2022
 *      Author: student
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "List.h"
#include "myFile.h"
#include "adventOfCode.h"

#define TRUE 1
#define FALSE 0


int cmpElements(char *str, int n)
{

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (str[i] == str[j])
			{
				return FALSE;
			}
		}
	}
	return TRUE;
}


void daySixFirst(FILE *input, List *list)
{
	int searchamount = 4;

	char *str = getStrFromList(list, 0);
	//printf("%s \n", str);

	int success = 0;
	int count = 0;

	while(success == 0)
	{
		success = cmpElements(&str[count], searchamount);
		count++;
	}
	count--;
	printf("-->%d ", count + searchamount);

	for (int i = 0; i < searchamount; i++)
	{
		printf("%c ", str[count + i]);
	}

	printf("\n");
}

void daySixSecond(FILE *input, List *list)
{
	int searchamount = 14;

	char *str = getStrFromList(list, 0);
	//printf("%s \n", str);

	int success = 0;
	int count = 0;

	while(success == 0)
	{
		success = cmpElements(&str[count], searchamount);
		count++;
	}
	count--;
	printf("-->%d ", count + searchamount);

	for (int i = 0; i < searchamount; i++)
	{
		printf("%c ", str[count + i]);
	}

	printf("\n");
}

