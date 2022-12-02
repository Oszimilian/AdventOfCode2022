/*
 * inputFile.h
 *
 *  Created on: 02.12.2022
 *      Author: maximilian
 */

#ifndef INPUTFILE_H_
#define INPUTFILE_H_

void inputFileToList(FILE *input, List *list);
void deleteOutputFile(FILE *output);
void wirteLineToFile(FILE *file, char *str);

#endif /* INPUTFILE_H_ */
