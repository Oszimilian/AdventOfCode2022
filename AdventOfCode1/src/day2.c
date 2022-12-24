//
// Created by maximilian on 24.12.22.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "List.h"
#include "myFile.h"
#include "adventOfCode.h"

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
