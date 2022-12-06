/*
 * Element.h
 *
 *  Created on: 02.12.2022
 *      Author: maximilian
 */

#ifndef ELEMENT_H_
#define ELEMENT_H_

#define MAX_LINE_LEANGH 4100

struct Element
{
	char str[MAX_LINE_LEANGH];
	struct Element *next;
	struct Element *prev;
};
typedef struct Element Element;

#endif /* ELEMENT_H_ */
