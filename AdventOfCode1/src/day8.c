/*
 * day8.c
 *
 *  Created on: 09.12.2022
 *      Author: student
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "List.h"
#include "myFile.h"
#include "adventOfCode.h"

#define LINE_LEANGH 99

int *lookOneDirection(List *list, int direction, int start)
{
	static int line[LINE_LEANGH];
	for(int i= 0; i < LINE_LEANGH; i++)
	{
		line[i] = 0;
	}

	switch(direction)
	{
		//up -> down
		case 0:
			for (int i = 0; i < LINE_LEANGH; i++)
			{
				line[i] = *(getStrFromList(list, i) + start) - '0';
			}
		break;

		//right -> left
		case 1:
			for (int i = 0; i < LINE_LEANGH; i++)
			{
				line[i] = *(getStrFromList(list, start) + LINE_LEANGH - i - 1) - '0';
			}
		break;

		//down -> up
		case 2:
			for (int i = 0; i < LINE_LEANGH; i++)
			{
				line[i] = *(getStrFromList(list, LINE_LEANGH - 1 - i) + start) - '0';
			}
		break;

		//right -> left
		case 3:
			for (int i = 0; i < LINE_LEANGH; i++)
			{
				line[i] = *(getStrFromList(list, start) + i) - '0';
			}

	}

	return line;
}

void checkLineVisibility(int *line)
{
	int highest = line[0];
	line[0] = 1;

	for (int i = 1; i < LINE_LEANGH; i++)
	{
		if (line[i] > highest)
		{
			highest = line[i];
			line[i] = 1;
		} else {
			line[i] = 0;
		}
	}

}



void fillMapInDirection(int map[][LINE_LEANGH], int *line, int direction, int start)
{
	switch(direction)
	{
		//up -> down
		case 0:
			for (int i = 0; i < LINE_LEANGH; i++)
			{
				if (line[i] == 1)
				{
					map[i][start] = 1;
				}
			}
		break;

		//right -> left
		case 1:
			for (int i = 0; i < LINE_LEANGH; i++)
			{
				if (line[i] == 1)
				{
					map[start][LINE_LEANGH - i - 1] = 1;
				}
			}
		break;

		//down -> up
		case 2:
			for (int i = 0; i < LINE_LEANGH; i++)
			{
				if (line[i] == 1)
				{
					map[LINE_LEANGH - i - 1][start] = 1;
				}
			}
		break;

		//right -> left
		case 3:
			for (int i = 0; i < LINE_LEANGH; i++)
			{
				if (line[i] == 1)
				{
					map[start][i] = 1;
				}
			}

	}
}

void printLine(int *line)
{
	for (int i = 0; i < LINE_LEANGH; i++)
	{
		printf("%d", line[i]);
	}

	printf("\n");
	fflush(stdout);
}

void printMap(int map[][LINE_LEANGH])
{
	for (int i = 0; i < LINE_LEANGH; i++)
	{
		for (int j = 0; j < LINE_LEANGH; j++)
		{
			printf("%d", map[i][j]);
		}
		printf("\n");
	}
}

void cmpMaps(List *list, int map[][LINE_LEANGH])
{
	char *str = NULL;

	for (int i = 0; i < LINE_LEANGH; i++)
	{
		str = getStrFromList(list, i);

		for (int j = 0; j < LINE_LEANGH; j++)
		{
			if ((str[j] - '0') == 0)
			{
				map[i][j] = 0;
			}
		}
	}
}

int countTrees(int map[][LINE_LEANGH])
{
	int sum  = 0;
	for (int i = 0; i < LINE_LEANGH; i++)
	{
		for (int j = 0; j < LINE_LEANGH; j++)
		{
			sum += map[i][j];
		}
	}

	return sum;
}

void dayEightFirst(FILE *input, List *list)
{
	int visibleMap[LINE_LEANGH][LINE_LEANGH];
	for (int i = 0; i < LINE_LEANGH; i++)
	{
		for (int j = 0; j < LINE_LEANGH; j++)
		{
			visibleMap[i][j] = 0;
		}
	}

	int *line = NULL;


	printf("\n");

	for (int dir = 0; dir < 4; dir++)
	{
		for (int i = 0; i < LINE_LEANGH; i++)
		{
			line = lookOneDirection(list, dir, i);
			//printLine(line);
			checkLineVisibility(line);
			fillMapInDirection(visibleMap, line, dir, i);
		}
		printf("\n");
		//printMap(visibleMap);
		//printf("Dir: %d \n\n", dir);
	}

	printMap(visibleMap);

	printf("\n\n %d\n", countTrees(visibleMap));
}

int lookInEachDirection(List *list, int x, int y)
{
	if (x == 0 || y == 0 || x == LINE_LEANGH - 1 || y == LINE_LEANGH - 1) return 0;

	int *line = NULL;
	int view[4] = {0};
	int i = 0;

	line = lookOneDirection(list, 0, x);

	do
	{
		i++;
	}while(line[y] > line[y + i] && (y + i) < LINE_LEANGH - 1);

	view[0] = i;

	i = 0;

	do
	{
		i++;
	}while(line[y] > line[y - i] && (y - i) > 0);

	view[2] = i;

	line = lookOneDirection(list, 3, y);
	i = 0;

	do
	{
		i++;
	}while(line[x] > line[x + i] && (x + i) < LINE_LEANGH - 1);

	view[1] = i;

	i = 0;

	do
	{
		i++;
	}while(line[x] > line[x - i] && (x - i) > 0);

	view[3] = i;

	int result = (view[0] * view[1] * view[2] * view[3]);

	printf("%d / %d : ( %d )%d %d %d %d -> %d \n", x + 1, y + 1,line[x], view[0], view[1], view[2], view[3], result);



	return result;
}

void dayEightSecond(FILE *input, List *list)
{
	int max = 0;
	int local = 0;

	for (int i = 0; i < LINE_LEANGH; i++)
	{
		for (int j = 0; j < LINE_LEANGH; j++)
		{
			local = lookInEachDirection(list, j, i);

			if (local > max)
			{
				max = local;
			}
		}
	}
	printf("-> %d \n", max);
}
