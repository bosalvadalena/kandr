/*
 * =====================================================================================
 *
 *       Filename:  getword.h
 *
 *    Description:  Header for getword.c
 *
 *        Version:  1.0
 *        Created:  03/27/2018 12:06:17 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Bo Salvadalena (), bxsalvadalena01@students.everettcc.edu
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef GETWORD_H
#define GETWORD_H

/*
 *	As of 03/27/2018, the lengths of the longest English words are,
 *	
 *	189,819		longest technical,
 *	1,909		longest published,
 *	182		longest to appear in litterature,
 *	45		longest to appear in major dictionary
 *
 *	according to Wikipedia. <en.wikipedia.org/wiki/Longest_word_in_English>
 *
 *	"Agglutinative languages allow for the creation of long words via compounding.
 *	Even non-agglutinative languages may allow word formation of theoretically
 *	limitless length in certain contexts." <en.wikipedia.org/wiki/Longest_words>
 *
 * 	Therefore, GETWORD_WS will be set to an arbitary number, and the respective
 * 	string buffer can be resized if neccesary.
*/

#define GETWORD_WS 50

char *getword(const char line);

#endif
