/*
 * tree.h
 *
 *  Created on: 07.12.2022
 *      Author: student
 */

#ifndef TREE_H_
#define TREE_H_

#define MAX_FILES 20
#define MAX_BRANCHES 20
#define MAX_BRANCH_NAME 50

struct Branch
{
	struct Branch *branch[MAX_BRANCHES];
	int file[MAX_FILES];
	struct Branch *prev;
	char name[MAX_BRANCH_NAME];
};
typedef struct Branch Branch;

struct Tree
{
	struct Tree *head;
	struct Tree *current;
};
typedef struct Tree Tree;



#endif /* TREE_H_ */
