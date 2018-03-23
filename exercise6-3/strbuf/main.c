/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  Experimenting with storing strings in a linked list
 *
 *        Version:  1.0
 *        Created:  03/21/2018 07:39:26 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Bo Salvadalena (), bxsalvadalena01@students.everettcc.edu
 *   Organization:  
 *
 * =====================================================================================
 */

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	"list.h"

void printBuffer (List *list);

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	FILE		*filePtr = stdin; // change this

	List		stringBuffer;
	List		*listPtr = &stringBuffer;

	ssize_t		getlineReturn;

	list_init(listPtr, free);

	do {
		char *string = NULL;
		size_t stringLength = 0;

		if ((getlineReturn = getline(&string, &stringLength, filePtr)) >= 0) {
			list_ins_next(listPtr, list_tail(listPtr), strdup(string));
			free(string);
		}
		//printf("\t%d\n", list_size(listPtr));
	}
	while (getlineReturn != EOF);

	printBuffer(listPtr);
	list_destroy(listPtr);

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  printBuffer
 *  Description:  Print the stringBuffer
 * =====================================================================================
 */
	void
printBuffer (List *list)
{
	ListElmt *element = list_head(list);
	//
	// 03/23/2018 12:40:11 AM
	//
	// This needs work, perhaps try recursion
	//
	while (element != list_next(element)) {
		printf("%s", element->data);
		if (list_next(element) != list_tail(list))
			element = list_next(element);
	}
}		/* -----  end of function printBuffer  ----- */
