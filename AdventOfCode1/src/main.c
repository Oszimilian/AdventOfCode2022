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



	FILE *input = fopen("/home/maximilian/CLionProjects/AdventOfCode2022/AdventOfCode1/Inputs/day9.txt", "r+");

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
	//dayFiveSecond(input, inputList);

	//daySixFirst(input, inputList);
	//daySixSecond(input, inputList);

	//daySevenFirstAndSecond(input, inputList);

	//dayEightFirst(input, inputList);
	//dayEightSecond(input, inputList);

    //dayNineFirst(inputList);
    dayNineSecond(inputList);

	fclose(input);

	int wait;
	scanf("%d ", &wait);

	return EXIT_SUCCESS;
}
