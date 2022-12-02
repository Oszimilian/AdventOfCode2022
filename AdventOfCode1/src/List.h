/*
 * List.h
 *
 *  Created on: 02.12.2022
 *      Author: maximilian
 */

#ifndef LIST_H_
#define LIST_H_

#include "Element.h"

struct List
{
	struct Element *head;
	struct Element *tail;
	int listLenagh;
};
typedef struct List List;

List *createList(void);
Element *createElement(char *input);
void pushElement(List *list, Element *element);
Element *getElementAtIndex(List *list, int index);
void printList(const List *list);
void reversePrintList(const List *list);
char *getStrFromList(List *list, int index);

#endif /* LIST_H_ */
