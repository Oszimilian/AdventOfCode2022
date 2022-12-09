/*
 * day7.c
 *
 *  Created on: 07.12.2022
 *      Author: student
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "List.h"
#include "myFile.h"
#include "adventOfCode.h"

int scanDir(List *list, int *i, int *m, int *dir)
{
	char *str = NULL;

	int level = *m;
	*m = *m + 1;

	while( (str = getStrFromList(list, *i)) != NULL)
	{
		*i = *i + 1;

		if (str[0] == '$')
		{
			if (str[2] == 'c')
			{
				if (str[5] == '.')
				{
					break;
				} else {
					dir[level] += scanDir(list, i, m, dir);
				}
			}
		}
		else if (str[0] >= '0' && str[0] <= '9')
		{
			int size = 0;
			if (sscanf(str, "%d", &size))
			{
				dir[level] += size;
			}
		}

	}



	return dir[level];
}

void daySevenFirstAndSecond(FILE *input, List *list)
{
	int i = 0;
	int m = 0;
	int dirSize[1000] = {0};
	int size = 0;

	int total = scanDir(list, &i, &m, dirSize);

	for (int i = 0; i < 1000; i++)
	{
		if (dirSize[i] <= 100000)
		{
			size += dirSize[i];
		}
	}

	bubbleSort(dirSize, 1000);

	int start = 0;
	while(dirSize[start] == 0){
		start++;
	}

	int freeSpace = -1 *(70000000 - total - 30000000);

	while(dirSize[start] <= freeSpace && start <= 1000)
	{
		start++;
	}

	printf("->%d \n", size);

	printf("->%d \n", dirSize[start]);
}
