/*
 * adventOfCode.c
 *
 *  Created on: 02.12.2022
 *      Author: maximilian
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "List.h"
#include "myFile.h"
#include "adventOfCode.h"

void dayOneFirst(FILE *input, List *list)
{
	int caloriecount = 0;
	int count = 0;
	char *str = NULL;
	int maxCalorie = 0;
	int elf = 0;


	do
	{
		caloriecount = 0;
		do
		{
			str = getStrFromList(list, count);
			caloriecount += atoi(str);
			count++;
		}while(*str != 0);

		if (caloriecount > maxCalorie)
		{
			maxCalorie = caloriecount;
			elf = count;
		}
	}while (getStrFromList(list, count + 1) != NULL);

	printf("1.1 -> %d \n", maxCalorie);
}

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void bubbleSort(int *arr, int n)
{

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}

void dayOneSecond(FILE *input, List *list)
{
	int caloriecount = 0;
	int count = 0;
	char *str = NULL;
	int maxCalorie[4] = {0};
	int totalCalorie = 0;



	do
	{
		caloriecount = 0;
		do
		{
			str = getStrFromList(list, count);
			caloriecount += atoi(str);
			count++;
		}while(*str != 0);

		maxCalorie[0] = caloriecount;

		bubbleSort(maxCalorie, 4);

	}while (getStrFromList(list, count + 1) != NULL);

	for (int i = 1; i < 4; i++)
	{
		totalCalorie += maxCalorie[i];
	}

	printf("1.2 -> %d \n", totalCalorie);
}
