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

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  Main function
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	BiTree tree;

	bitree_init(&tree, free);

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
