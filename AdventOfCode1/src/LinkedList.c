/*
 * LinkedList.c
 *
 *  Created on: 02.12.2022
 *      Author: maximilian
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "List.h"

List *createList(void)
{
	List *list = (List*) malloc(sizeof(List));
	list->head = NULL;
	list->tail = NULL;
	list->listLenagh = 0;
	return list;
}

Element *createElement(char *input)
{
	Element *element = (Element*) malloc(sizeof(Element));
	strcpy(element->str, input);
	element->next = NULL;
	element->prev = NULL;
	return element;
}

void pushElement(List *list, Element *element)
{
	element->next = list->head;
	if (element->next == NULL)
	{
		list->tail = element;
		list->head = element;
		list->listLenagh++;
	} else {
		list->head = element;
		element->next->prev = element;
		list->listLenagh++;
	}
}

Element *getElementAtIndex(List *list, int index)
{
	Element *element = list->head;

	while(index > 0 && element != NULL)
	{
		element = element->next;

		index--;
	}

	return element;
}

void printList(const List *list)
{
	Element *element = list->head;

	printf("\n");

	if (element == NULL)
	{
		printf("Liste leer! \n");
	}

	while(element != NULL)
	{
		printf("%s - %x\n", element->str, element->str[0]);

		element = element->next;

		if (element == NULL)
		{
			printf("\n");
		}
	}
}

void reversePrintList(const List *list)
{
	printf("\n");

	Element *element = list->tail;

	if (element == NULL)
	{
		printf("Liste leer! \n");
	}

	while(element != NULL)
	{
		printf("%s - %x\n", element->str, element->str[0]);

		element = element->prev;

		if (element == NULL)
		{
			printf("\n");
		}
	}
}

char *getStrFromList(List *list, int index)
{
	Element *element = list->tail;

	while(index > 0 && element != NULL)
	{
		element = element->prev;

		index--;
	}

	if (element == NULL)
	{
		return NULL;
	} else {
		return element->str;
	}
}
