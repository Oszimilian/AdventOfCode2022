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

void dayTwoFirst(FILE *input, List *list)
{
	int count = 0;

	int gameCount = 0;
	int gameMove[2] = {0};
	char *str = NULL;

	do
	{
		str = getStrFromList(list, count);
		gameMove[0] = str[0] - 'A' + 1;
		gameMove[1] = str[2] - 'X' + 1;
		gameCount += gameMove[1];

		if (gameMove[0] == gameMove[1])
		{
			gameCount += _draw;
		}
		if(     (gameMove[0] == _Rock     && gameMove[1] == _Paper) ||
				(gameMove[0] == _Paper    && gameMove[1] == _Scissors) ||
				(gameMove[0] == _Scissors && gameMove[1] == _Rock) )
		{
			gameCount += _win;
		}

		printf("%d %d \n", gameMove[0], gameMove[1]);
		count++;
	}while (getStrFromList(list, count + 1) != NULL);

	printf("-> %d", gameCount);
}

void dayTwoSecond(FILE *input, List *list)
{
	int count = 0;

	int gameCount = 0;
	int gameMove = 0;
	int gameResult = 0;
	char *str = NULL;

	do
	{
		str = getStrFromList(list, count);
		gameMove = str[0] - 'A' + 1;
		gameResult = str[2] - 'X' + 1;


		//draw game
		if (gameResult == 2)
		{
			gameCount += _draw;
			gameCount += gameMove;
		}
		if (gameResult == 1)
		{
			switch(gameMove)
			{
				case _Rock: gameCount += _Scissors; break;
				case _Paper: gameCount += _Rock; break;
				case _Scissors: gameCount += _Paper; break;
			}
		}
		if (gameResult == 3)
		{
			gameCount += _win;

			switch (gameMove)
			{
				case _Rock: gameCount += _Paper; break;
				case _Paper: gameCount += _Scissors; break;
				case _Scissors: gameCount += _Rock; break;
			}
		}

		printf("%d %d \n", gameMove, gameResult);

	}while (getStrFromList(list, ++count + 1) != NULL);

	printf("-> %d", gameCount);
}

void dayThreeFirst(FILE *input, List *list)
{
	char *str;
	int strLen = 0;
	int halfLen = 0;
	char Bag[2][128] = {0};
	int count = 0;
	int sum = 0;
	char element = 0;
	int elementValue = 0;

	do
	{

		str = getStrFromList(list, count);
		strLen = strlen(str);
		halfLen = strLen / 2;

		for (int i = 0; i < strLen; i++)
		{
			if (i < halfLen)
			{
				Bag[0][i] = str[i];
			} else {
				Bag[1][i - halfLen] = str[i];
			}
		}
		Bag[0][halfLen] = '\0';
		Bag[1][halfLen] = '\0';

		for (int i = 0; i < halfLen; i++)
		{
			for (int k = 0; k < halfLen; k++)
			{
				if (Bag[0][i] == Bag[1][k])
				{
					element = Bag[1][k];
					if (element >= 'a' && element <= 'z')
					{
						elementValue = 1 + element - 'a';
					} else {
						elementValue = 1 + element - 'A' + 26;
					}
				}
			}
		}

		sum += elementValue;

	}while (getStrFromList(list, ++count + 1) != NULL);

	printf("-> %d \n", sum);
}

void dayThreeSecond(FILE *input, List *list)
{
	char *str[3] = {NULL};
	int count = 0;
	int element = 0;
	char sticker = 0;
	int strLen[3] = {0};

	do
	{

		for (int i = 0; i < 3; i++)
		{
			str[i] = getStrFromList(list, count++);
			strLen[i] = strlen(str[i]);

			//printf("%s \n", str[i]);
		}

		for (int i = 0; i < strLen[0]; i++)
		{
			char lokalSticker = str[0][i];
			int checkOne = 0;
			int checkTwo = 0;
			for (int k = 0; k < strLen[1]; k++)
			{
				if (lokalSticker == str[1][k])
				{
					checkOne = 1;
				}
			}
			for (int m = 0; m < strLen[2]; m++)
			{
				if (lokalSticker == str[2][m])
				{
					checkTwo = 1;
				}
			}

			if (checkOne && checkTwo)
			{
				sticker = lokalSticker;
			}
		}

		int n = (sticker >= 'A' && sticker <= 'Z') ? sticker - 'A' + 1 + 26: sticker - 'a' + 1;

		//printf("%c -> %d \n", sticker, n);

		element += n;

	}while (getStrFromList(list, count + 1) != NULL);

	printf("-> %d", element);
}
