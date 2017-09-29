#include <stdio.h>
#include "getword.h"

#define MAXWORD 1024

int main()
{
	char word[MAXWORD];

	while (getword(word) != EOF) {
		if (*word) {
			printf("%s\n", word);
		}
	}

	return 0;
}
