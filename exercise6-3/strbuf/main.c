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
#include	<sys/types.h>
#include	<regex.h>
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
		//03/25/2018 01:48:45 PM
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

	while (element != NULL) {
		printf("%s", element->data);
		element = list_next(element);
	}
}		/* -----  end of function printBuffer  ----- */
