/*
 * tree.c
 *
 *  Created on: 07.12.2022
 *      Author: student
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "List.h"
#include "myFile.h"
#include "adventOfCode.h"
#include "tree.h"

Tree *createTree(void)
{
	Tree *tree = (Tree*) malloc(sizeof(Tree));
	tree->head = NULL;
	tree->current = NULL;
	return tree;
}

Branch *createBranch(int files, int branches, char *name)
{
	Branch *branch = (Branch*) malloc(sizeof(Branch));

	branch->prev = NULL;

	for (int i = 0; i < branches; i++)
	{
		branch->branch[i] = NULL;
	}

	for (int i = 0; i < files; i++)
	{
		branch->file[i] = 0;
	}

	strcpy(branch->name, name);

	return branch;
}
