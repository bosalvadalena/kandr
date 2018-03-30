/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  Exercise 6-3. Write a cross-referencer that prints a list of all
 *                                words in a document, and, for each word, a list of
 *                                the line numbers on which it occurs. Remove noise
 *                                words like "the," "and," and so on.
 *
 *        Version:  1.0
 *        Created:  03/26/2018 09:39:00 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Bo Salvadalena, bxsalvadalena01@students.everettcc.edu
 *   Organization:  
 *
 * =====================================================================================
 */

#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include	"bitree/bitree.h"
#include	"getword/getword.h"

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  Main function
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	BiTree		tree, *treePtr;
	int		(*compare)() = &strcmp;
	char		*line;
	char		*word;
	int		lineLength;
	int		wordLength;
	ssize_t		lineSize;

	/* Initialize binary tree */
	treePtr = &tree;
	bitree_init(treePtr, free);
	treePtr->compare = compare;

	do {
		int linePosition = 0;
		lineLength = 0;
		line = NULL;

		/* Get a line until EOF, grab each word, add to tree */
		if ((lineSize = getline(&line, &lineLength, stdin)) > 0) {
			while (getword(line, &linePosition, &word) >= 0) {
				printf("%s ", word);
				free(word);
			}
			printf("\n");
			free(line);
		}
	}
	while (lineSize >= 0);

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
