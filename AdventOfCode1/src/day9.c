//
// Created by maximilian on 23.12.22.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "List.h"
#include "myFile.h"
#include "adventOfCode.h"

#define TOUCHING 0
#define NOT_TOUCHING 1
#define X_POS 0
#define Y_POS 1

#define MOVE_UP 0
#define MOVE_UP_RIGHT 1
#define MOVE_RIGHT 2
#define MOVE_RIGHT_DOWN 3
#define MOVE_DOWN 4
#define MOVE_DOWN_LEFT 5
#define MOVE_LEFT 6
#define MOVE_LEFT_UP 7

#define FAIL 8

#define TRUE 1
#define FALSE 0

struct LOCAL_ELEMENT
{
    int x;
    int y;
    struct LOCAL_ELEMENT *next;
};
typedef struct LOCAL_ELEMENT LOCAL_ELEMENT;

struct LOCAL_LIST
{
    int leangh;
    struct LOCAL_ELEMENT *head;
};
typedef struct LOCAL_LIST LOCAL_LIST;

LOCAL_LIST *createLocalList()
{
    LOCAL_LIST *list = (LOCAL_LIST*)malloc(sizeof (LOCAL_LIST));
    if (list == NULL) return NULL;
    list->head = NULL;
    list->leangh = 0;
    return list;
}

LOCAL_ELEMENT *createLocalElement(int x, int y)
{
    LOCAL_ELEMENT *element = (LOCAL_ELEMENT*) malloc(sizeof (LOCAL_ELEMENT));
    if (element == NULL) return NULL;
    element->x = x;
    element->y = y;
    element->next = NULL;
    return element;
}

void pushLocalElement(LOCAL_LIST *list, LOCAL_ELEMENT *element)
{
    element->next = list->head;
    list->head = element;
    list->leangh++;
}

int checkDublicatList(LOCAL_LIST *list, int x, int y)
{
    LOCAL_ELEMENT *element = list->head;
    while(element != NULL)
    {
        if (element->x == x && element->y == y)
        {
            return TRUE;
        } else {
            element = element->next;
        }
    }
    return FALSE;
}

int betrag(int n)
{
    return (n >= 0) ? n : -n;
}

int checkDistance(int *headPosition, int *tailPosition)
{
    if (betrag(headPosition[X_POS] - tailPosition[X_POS]) <= 1)
    {
        if (betrag(headPosition[Y_POS] - tailPosition[Y_POS]) <= 1)
        {
            return TOUCHING;
        }
    }
    return NOT_TOUCHING;
}

int checkMovement(int *headPosition, int *tailPosition) {
    int xDistance = headPosition[X_POS] - tailPosition[X_POS];
    int yDistance = headPosition[Y_POS] - tailPosition[Y_POS];

    if (xDistance == 0 && yDistance == -2) return MOVE_UP;
    else if (xDistance == 1 && yDistance == -2) return MOVE_UP_RIGHT;
    else if (xDistance == 2 && yDistance == -1) return MOVE_UP_RIGHT;
    else if (xDistance == 2 && yDistance == -0) return MOVE_RIGHT;
    else if (xDistance == 2 && yDistance == 1) return MOVE_RIGHT_DOWN;
    else if (xDistance == 1 && yDistance == 2) return MOVE_RIGHT_DOWN;
    else if (xDistance == 0 && yDistance == 2) return MOVE_DOWN;
    else if (xDistance == -1 && yDistance == 2) return MOVE_DOWN_LEFT;
    else if (xDistance == -2 && yDistance == 1) return MOVE_DOWN_LEFT;
    else if (xDistance == -2 && yDistance == 0) return MOVE_LEFT;
    else if (xDistance == -2 && yDistance == -1) return MOVE_LEFT_UP;
    else if (xDistance == -1 && yDistance == -2) return MOVE_LEFT_UP;
    else if (xDistance == 2 && yDistance == -2) return MOVE_UP_RIGHT;
    else if (xDistance == 2 && yDistance == 2) return MOVE_RIGHT_DOWN;
    else if (xDistance == -2 && yDistance == 2) return MOVE_DOWN_LEFT;
    else if (xDistance == -2 && yDistance == -2) return MOVE_LEFT_UP;
    else return FAIL;
}

void setPosition(int *position, int move)
{
    switch(move)
    {
        case MOVE_UP: position[Y_POS]--; break;
        case MOVE_UP_RIGHT : position[X_POS]++; position[Y_POS]--; break;
        case MOVE_RIGHT: position[X_POS]++; break;
        case MOVE_RIGHT_DOWN: position[X_POS]++; position[Y_POS]++; break;
        case MOVE_DOWN: position[Y_POS]++; break;
        case MOVE_DOWN_LEFT: position[X_POS]--; position[Y_POS]++; break;
        case MOVE_LEFT: position[X_POS]--; break;
        case MOVE_LEFT_UP: position[X_POS]--; position[Y_POS]--; break;
        default: printf("no Move possible"); break;
    }
}

int getHeadDirection(char *str)
{
    int ret = FAIL;
    switch(str[0])
    {
        case 'U': ret = MOVE_UP; break;
        case 'R': ret = MOVE_RIGHT; break;
        case 'D': ret = MOVE_DOWN; break;
        case 'L': ret = MOVE_LEFT; break;
        default: break;
    }

    return ret;
}

int getHeadAmount(char *str)
{
    return atoi(str);
}


void dayNineFirst(List *list)
{
    int headPosition[2] = {300, 300};
    int tailPosition[2] = {300, 300};

    char *str = NULL;
    int counter = 0;

    int move = FAIL;
    int n = 0;
    int tailMove = FAIL;

    LOCAL_LIST *taskList = createLocalList();
    LOCAL_ELEMENT *taskElement = NULL;

    do
    {
        str = getStrFromList(list, counter);
        if (str == NULL) break;

        printf("%s \n", str);

        move = getHeadDirection(str);
        n = getHeadAmount(&str[2]);

        while (n > 0)
        {
            setPosition(headPosition, move);
            n--;
            if (checkDistance(headPosition, tailPosition) == NOT_TOUCHING)
            {
                tailMove = checkMovement(headPosition, tailPosition);
                setPosition(tailPosition, tailMove);
                if (checkDublicatList(taskList, tailPosition[X_POS], tailPosition[Y_POS]) == FALSE)
                {
                    taskElement = createLocalElement(tailPosition[X_POS], tailPosition[Y_POS]);
                    pushLocalElement(taskList,taskElement);
                }
            }

            printf("HEAD: [%d][%d] TAIL: [%d][%d] \n", headPosition[0], headPosition[1], tailPosition[0], tailPosition[1]);
        }

        counter++;

        printf("\n");
    }while(str != NULL);

    printf("-> %d", taskList->leangh);
}

void dayNineSecond(List *list)
{
    int position[10][2];
    for (int y = 0; y < 10; y++)
    {
        for (int x = 0; x < 2; x++)
        {
            position[y][x] = 500;
        }
    }

    char *str = NULL;
    int counter = 0;

    int move = FAIL;
    int n = 0;
    int tailMove = FAIL;

    LOCAL_LIST *taskList = createLocalList();
    LOCAL_ELEMENT *taskElement = NULL;

    do {
        str = getStrFromList(list, counter);
        if (str == NULL) break;

        printf("%s \n", str);

        move = getHeadDirection(str);
        n = getHeadAmount(&str[2]);

        while(n > 0)
        {

            setPosition(position[0], move);
            n--;
            for (int i = 0; i < 9; i++)
            {
                if (checkDistance(position[i], position[i + 1]) == NOT_TOUCHING)
                {
                    tailMove = checkMovement(position[i], position[i + 1]);
                    setPosition(position[i + 1], tailMove);
                    printf("->Movement: ");

                    if (checkDublicatList(taskList, position[i + 1][X_POS], position[i + 1][Y_POS]) == FALSE && i == 8)
                    {
                        taskElement = createLocalElement(position[i + 1][X_POS], position[i + 1][Y_POS]);
                        pushLocalElement(taskList,taskElement);
                    }
                }
                printf("HEAD (%d): [%d][%d] TAIL: [%d][%d] \n", i, position[i][X_POS], position[i][Y_POS], position[i + 1][X_POS], position[i + 1][Y_POS]);
            }

        }
    counter++;


    }while(str != NULL);
    printf("-> %d", taskList->leangh + 1);
}