#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*
 *	define escape structure
*/

struct escape {

	const char *begin;
	const char *end;

};

struct escape escape_list[] = {
	{ "\"", "\"" },
	{ "/*", "*/" },
	{ "//", "\n" }
};

/*
 * 	define state parameters
*/

#define IN 1
#define OUT 0

int state = OUT;
struct escape *current = NULL;

/*
 *	push a character into the buffer
*/

#define BUFFER_SIZE 2

char buffer[BUFFER_SIZE];

void push_buffer(char c) {
	
	char *bufp = buffer;

	while (bufp - buffer < BUFFER_SIZE-1) {
		*bufp = *(bufp + 1);
		bufp++;
	}

	*bufp = c;
}

/*
 *	return characters that are not nested within escapes
*/

char get_nescape(void) {
	
	char c;

	do {
		push_buffer(c = getchar());

		struct escape *elp = escape_list;
		struct escape *elp_end = escape_list + sizeof(escape_list) /
						       sizeof(escape_list[0]);

		while (elp < elp_end) {
			if (!strncmp(elp->begin, buffer, strlen(elp->begin)) && !state) {
				if (current == NULL) {
					current = elp;
					state = IN;
				}
			}
			else if (!strncmp(elp->end, buffer, strlen(elp->end)) && state) {
				if (current == elp) {
					current = NULL;
					state = OUT;
				}
			}

			elp++;
		}
	} while (state == IN);

	return c;
}
