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

void dayFourFirst(FILE *input, List *list)
{
	int count = 0;
	char *str = NULL;

	int conflicts = 0;
	int borders[2][2];

	do
	{
		str = getStrFromList(list, count);
		//printf("%s -> ", str);

		int i = 0;
		int k = 0;
		int m = 0;
		char lokalStr[3];
		while(str[i] != '\n' && str[i] != '\0')
		{
			m = 0;
			for(int i = 0; i < 3; i++)
			{
				lokalStr[i] = '\0';
			}

			while(str[i] != ',' && str[i] != '-' && str[i] != '\0')
			{
				lokalStr[m] = (char)str[i++];
				m++;
			}
			lokalStr[2] = '\0';

			switch(k)
			{
				case 0: borders[0][0] = atoi(lokalStr); break;
				case 1: borders[0][1] = atoi(lokalStr); break;
				case 2: borders[1][0] = atoi(lokalStr); break;
				case 3: borders[1][1] = atoi(lokalStr); break;
				default: break;
			}

			i++;
			k++;
		}



		if(borders[1][0] >= borders[0][0] && borders[1][1] <= borders[0][1])
		{
			conflicts++;
		}

		else if(borders[0][0] >= borders[1][0] && borders[0][1] <= borders[1][1])
		{
			conflicts++;
		}



		//printf("%d-%d %d-%d -> %d\n", borders[0][0], borders[0][1], borders[1][0], borders[1][1], conflicts);


	}while (getStrFromList(list, ++count + 1) != NULL);

	printf("-> %d \n" ,conflicts);

}

void dayFourSecond(FILE *input, List *list)
{
	int count = 0;
	char *str = NULL;

	int conflicts = 0;
	int borders[2][2];

	do
	{
		str = getStrFromList(list, count);
		//printf("%s -> ", str);

		int i = 0;
		int k = 0;
		int m = 0;
		char lokalStr[3];
		while(str[i] != '\n' && str[i] != '\0')
		{
			m = 0;
			for(int i = 0; i < 3; i++)
			{
				lokalStr[i] = '\0';
			}

			while(str[i] != ',' && str[i] != '-' && str[i] != '\0')
			{
				lokalStr[m] = (char)str[i++];
				m++;
			}
			lokalStr[2] = '\0';

			switch(k)
			{
				case 0: borders[0][0] = atoi(lokalStr); break;
				case 1: borders[0][1] = atoi(lokalStr); break;
				case 2: borders[1][0] = atoi(lokalStr); break;
				case 3: borders[1][1] = atoi(lokalStr); break;
				default: break;
			}

			i++;
			k++;
		}



		if ( ( (borders[1][0] >= borders[0][0]) && (borders[1][0] <= borders[0][1]) ) ||
			 ( (borders[1][1] <= borders[0][1]) && (borders[1][1] >= borders[0][0]) ) )
		{
			conflicts++;
		}
		else if ( ( (borders[0][0] >= borders[1][0]) && (borders[0][0] <= borders[1][1]) ) ||
				  (	(borders[0][1] <= borders[1][1]) && (borders[0][1] >= borders[1][0]) ) )
		{
			conflicts++;
		}



		//printf("%d-%d %d-%d -> %d\n", borders[0][0], borders[0][1], borders[1][0], borders[1][1], conflicts);


	}while (getStrFromList(list, ++count + 1) != NULL);

	printf("-> %d", conflicts);

}

void dayFiveFirst(FILE *input, List *list)
{
	List *stack[9] = {NULL};
	char *str = NULL;
	int count = 0;
	int zeilen = 9;
	int spalten = 9;

	for (int i = 0; i < zeilen; i++)
	{
		stack[i] = createList();
	}

	do
	{
		str = getStrFromList(list, zeilen - count - 2);
		//printf("%s \n", str);

		int lokalCount = 0;

		while(lokalCount < spalten)
		{
			int pos = 1 + (lokalCount * 4);
			if (str[pos] != 32)
			{
				char c[2];
				c[0] = str[pos];
				c[1] = '\0';

				Element *element = createElement(c);

				pushElement(stack[lokalCount], element);
			}
			lokalCount++;
		}

	}while(++count < zeilen - 1);

	for (int i = 0; i < 9; i++)
	{
		printList(stack[i]);
	}

	printf("\n");

	count += 2;

	int instruction[3];

	int instructionCounter = 0;

	do
	{
		instructionCounter = 0;
		str = getStrFromList(list, count);
		//printf("%s \n", str);

		int localCounter = 0;
		char c[3];

		while(str[localCounter] != '\0')
		{
			for (int i = 0; i < 3; i++)
			{
				c[i] = '\0';
			}

			while(str[localCounter] != 32)
			{
				localCounter++;
			}

			localCounter++;

			int numCounter = 0;

			while(str[localCounter] >= '0' && str[localCounter] <= '9')
			{
				c[numCounter] = str[localCounter];
				numCounter++;
				localCounter++;
			}

			instruction[instructionCounter] = atoi(c);

			localCounter++;
			instructionCounter++;
		}

		//printList(stack[instruction[1] - 1]);
		//printList(stack[instruction[2] - 1]);

		//printf("\n");

		for (int i = 0; i < instruction[0]; i++)
		{
			Element *element = listPopHead(stack[instruction[1] - 1]);
			pushElement(stack[instruction[2] - 1], element);
		}

		//printList(stack[instruction[1] - 1]);
		//printList(stack[instruction[2] - 1]);

		//printf("\n");

	}while (getStrFromList(list, ++count + 1) != NULL);

	for (int i = 0; i < 9; i++)
	{
		printList(stack[i]);
	}
}

void dayFiveSecond(FILE *input, List *list)
{
	List *stack[9] = {NULL};
	char *str = NULL;
	int count = 0;
	int zeilen = 9;
	int spalten = 9;

	for (int i = 0; i < zeilen; i++)
	{
		stack[i] = createList();
	}

	do
	{
		str = getStrFromList(list, zeilen - count - 2);
		//printf("%s \n", str);

		int lokalCount = 0;

		while(lokalCount < spalten)
		{
			int pos = 1 + (lokalCount * 4);
			if (str[pos] != 32)
			{
				char c[2];
				c[0] = str[pos];
				c[1] = '\0';

				Element *element = createElement(c);

				pushElement(stack[lokalCount], element);
			}
			lokalCount++;
		}

	}while(++count < zeilen - 1);

	for (int i = 0; i < 9; i++)
	{
		printList(stack[i]);
	}

	printf("\n");

	count += 2;

	int instruction[3];

	int instructionCounter = 0;

	do
	{
		instructionCounter = 0;
		str = getStrFromList(list, count);
		//printf("%s \n", str);

		int localCounter = 0;
		char c[3];

		while(str[localCounter] != '\0')
		{
			for (int i = 0; i < 3; i++)
			{
				c[i] = '\0';
			}

			while(str[localCounter] != 32)
			{
				localCounter++;
			}

			localCounter++;

			int numCounter = 0;

			while(str[localCounter] >= '0' && str[localCounter] <= '9')
			{
				c[numCounter] = str[localCounter];
				numCounter++;
				localCounter++;
			}

			instruction[instructionCounter] = atoi(c);

			localCounter++;
			instructionCounter++;
		}

		//printList(stack[instruction[1] - 1]);
		//printList(stack[instruction[2] - 1]);

		///printf("\n");
		/*
		for (int i = 0; i < instruction[0]; i++)
		{
			Element *element = listPopHead(stack[instruction[1] - 1]);
			pushElement(stack[instruction[2] - 1], element);
		}
		*/
		Element *element = listPopChainHead(stack[instruction[1] - 1], instruction[0]);

		pushElement(stack[instruction[2] - 1], element);

		while(element->prev != NULL)
		{
			element = element->prev;
		}

		stack[instruction[2] - 1]->head = element;
		element->prev = NULL;

		//printList(stack[instruction[1] - 1]);
		//printList(stack[instruction[2] - 1]);

		//printf("\n");

	}while (getStrFromList(list, ++count + 1) != NULL);

	for (int i = 0; i < 9; i++)
	{
		printList(stack[i]);
	}
}

