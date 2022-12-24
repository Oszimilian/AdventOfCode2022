//
// Created by maximilian on 24.12.22.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "List.h"
#include "myFile.h"
#include "adventOfCode.h"

#define NOOP 1
#define ADDX 2

#define TRUE 1
#define FALSE 0

#define COLLSION 1
#define NO_COLLSION 0

#define MAX_CYCLES 10000

#define EXTRA_CYCLE 40

int getCommand(char *str)
{
    if (strncmp(str, "addx", 4) == 0)
    {
        return ADDX;
    } else {
        return NOOP;
    }
}

int getValue(char *str)
{
    return atoi(str);
}

int checkCycleCondition(char *str, int *cycleCounter)
{
    if (str != NULL)
    {
        if (*cycleCounter == 20)
        {
            return TRUE;
        }
        if (*cycleCounter > 20)
        {
            for (int i = 1; i < MAX_CYCLES; i++)
            {
                if ( (int)((*cycleCounter - 20) - (40 * i) ) == 0)
                {
                    return TRUE;
                }
            }
            return FALSE;

        } else {
            return FALSE;
        }
    } else {
        return FALSE;
    }
}

int checkLineCondition(char *str, int *cycleCounter)
{
    if (str != NULL)
    {
        for (int i = 1; i < MAX_CYCLES; i++)
        {
            if ( ( *cycleCounter - (40 * i) ) == 0)
            {
                return TRUE;
            } else {
                return FALSE;
            }
        }
    } else {
        return FALSE;
    }
}



void dayTenFirst(List *list)
{
    char *str = NULL;
    int counter = 0;

    int xRegister = 1;
    int cycleCounter = 1;
    int command = 0;
    int value = 0;
    int sum = 0;
    int n = 0;


    do
    {
        str = getStrFromList(list, counter);
        if (str == NULL) break;
        //printf("%s\n", str);

        command = getCommand(str);
        value = getValue(&str[4]);

        n = (command == ADDX) ? ADDX : NOOP;

        do
        {
            if (checkCycleCondition(str, &cycleCounter) == TRUE)
            {
                checkCycleCondition(str, &cycleCounter);
                printf("-->Cycle Mark: %d XReg: %d ", cycleCounter, xRegister);
                sum += (cycleCounter * xRegister);
                printf("Sum: %d \n", cycleCounter * xRegister);
            }
            cycleCounter++;
        }while(--n > 0);
        xRegister += value;


        counter++;
    }while (str != NULL);

    printf("-> %d", sum);
}

int checkSpriteCollision(int *spritePosition, int *wirtePosition)
{
    for (int i = 0; i < 3; i++)
    {
        if ((*spritePosition + i) == *wirtePosition)
        {
            return TRUE;
        }
    }
    return FALSE;
}

void dayTenSecond(List *list)
{
    char *str = NULL;
    int counter = 0;

    int spritePosition = 0;
    int writePosition = 0;

    int xRegister = 1;
    int cycleCounter = 1;

    int command = 0;
    int value = 0;

    int n = 0;

    do
    {
        str = getStrFromList(list, counter);
        if (str == NULL) break;

        command = getCommand(str);
        value = getValue(&str[4]);

        n = (command == ADDX) ? ADDX : NOOP;

        do
        {
            if (checkLineCondition(str, &writePosition) == TRUE)
            {
                writePosition = 0;
                printf("\n");
            }
            if (checkSpriteCollision(&spritePosition, &writePosition) == COLLSION)
            {
                printf("#");
            } else {
                printf(".");
            }



            writePosition++;
        }while(--n > 0);
        xRegister += value;



        spritePosition = xRegister - 1;
        counter++;
    }while(str != NULL);
}