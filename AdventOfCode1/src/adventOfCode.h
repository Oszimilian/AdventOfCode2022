/*
 * adventOfCode.h
 *
 *  Created on: 02.12.2022
 *      Author: maximilian
 */

#ifndef ADVENTOFCODE_H_
#define ADVENTOFCODE_H_

#define _Rock 1
#define _Paper 2
#define _Scissors 3

#define _A _Rock
#define _X _Rock
#define _B _Paper
#define _Y _Paper
#define _C _Scissors
#define _Z _Scissors

#define _Lose 0
#define _draw 3
#define _win 6

void dayOneFirst(FILE *input, List *list);
void dayOneSecond(FILE *input, List *list);

void dayTwoFirst(FILE *input, List *list);
void dayTwoSecond(FILE *input, List *list);

void dayThreeFirst(FILE *input, List *list);
void dayThreeSecond(FILE *input, List *list);

void dayFourFirst(FILE *input, List *list);
void dayFourSecond(FILE *input, List *list);

void dayFiveFirst(FILE *input, List *list);
void dayFiveSecond(FILE *input, List *list);

void daySixFirst(FILE *input, List *list);
void daySixSecond(FILE *input, List *list);

void daySevenFirstAndSecond(FILE *input, List *list);
void bubbleSort(int *arr, int n);

void dayEightFirst(FILE *input, List *list);
void dayEightSecond(FILE *input, List *list);

void dayNineFirst(List *list);
void dayNineSecond(List *list);

void dayTenFirst(List *list);
void dayTenSecond(List *list);

#endif /* ADVENTOFCODE_H_ */
