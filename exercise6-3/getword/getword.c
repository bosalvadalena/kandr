/*
 * =====================================================================================
 *
 *       Filename:  getword.c
 *
 *    Description:  Return a word from a line of input
 *
 *        Version:  1.0
 *        Created:  03/26/2018 11:29:45 PM
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
#include	<ctype.h>


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  getword
 *  Description:  Return a word from a line of input
 * =====================================================================================
 */
	int 
getword (const char *line, int *position, char **word)
{
	int length;

	// Iterate through non alpha characters
	while (!isalpha(line[*position])) {
		if (line[*position] == '\0') {
			return -1;
		}
		++(*position);
	}

	// Get word length (up until next non alpha char)
	for (length = 0; isalpha(line[*position + length]); ++length);

	// Allocate room for word
	*word = malloc(sizeof(char) * length);

	// Copy word
	for (int i = 0; i < length; ++i) {
		(*word)[i] = line[*position];
		*position += 1;
	}

	// Add string terminator
	(*word)[length] = '\0';

	return length;
}		/* -----  end of function getword  ----- */
