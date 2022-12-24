//
// Created by maximilian on 24.12.22.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "List.h"
#include "myFile.h"
#include "adventOfCode.h"

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