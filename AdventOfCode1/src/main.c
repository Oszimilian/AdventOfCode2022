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



	FILE *input = fopen("Inputs/day5.txt", "r+");

	List *inputList = createList();

	inputFileToList(input, inputList);

	//dayOneFirst(input, inputList);
	//dayOneSecond(input, inputList);

	//dayTwoFirst(input, inputList);
	//dayTwoSecond(input, inputList);

	//dayThreeFirst(input, inputList);
	//dayThreeSecond(input, inputList);

	//dayFourFirst(input, inputList);
	//dayFourSecond(input, inputList);

	//dayFiveFirst(input, inputList);
	dayFiveSecond(input, inputList);

	fclose(input);

	int wait;
	scanf("%d ", &wait);

	return EXIT_SUCCESS;
}
