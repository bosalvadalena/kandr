#include <stdio.h>
#include "escape.h"

/* default word characters */
char *wc = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_.";

/* iswc - check if a char is a word character */
int iswc(char c) {
	char *wp;

	wp = wc;
	while (*wp) {
		if (c == *wp) { return 1; }
		else { wp++; }
	}

	return 0;
}
	
/* getword - get a word from standard input */
char getword(char *word) {
	char *wp, c;

	wp = word;
	while (iswc(c = get_nescape())) {
		*wp++ = c;
	}

	*wp = '\0';
	return c;
}
