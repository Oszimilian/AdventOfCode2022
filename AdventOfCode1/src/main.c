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

	FILE *output = fopen("output.txt", "w");
	FILE *input = fopen("in.txt", "r+");

	List *inputList = createList();



	inputFileToList(input, inputList);

	//printList(inputList);

	//reversePrintList(inputList);

	/*
	for (int i = 0; i < inputList->listLenagh; i++)
	{
		wirteLineToFile(output, getStrFromList(inputList,i));
	}
	*/

	dayOne(input, inputList);
	dayTwo(input, inputList);

	fclose(input);
	fclose(output);

	return EXIT_SUCCESS;
}
