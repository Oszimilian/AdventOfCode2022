//
// Created by maximilian on 24.12.22.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "List.h"
#include "myFile.h"
#include "adventOfCode.h"

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
