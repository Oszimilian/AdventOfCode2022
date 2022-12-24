//
// Created by maximilian on 24.12.22.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "List.h"
#include "myFile.h"
#include "adventOfCode.h"

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
