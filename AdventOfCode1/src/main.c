/*
 * main.c
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

int main(int argc, char **argv)
{
	printf("Test \n");


	FILE *input = fopen("Inputs/day3.txt", "r+");

	List *inputList = createList();

	inputFileToList(input, inputList);

	//dayOneFirst(input, inputList);
	//dayOneSecond(input, inputList);

	//dayTwoFirst(input, inputList);
	//dayTwoSecond(input, inputList);

	dayThreeFirst(input, inputList);
	dayThreeSecond(input, inputList);

	fclose(input);

	int wait;
	scanf("%d ", &wait);

	return EXIT_SUCCESS;
}
