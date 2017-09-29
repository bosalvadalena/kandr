#include <stdio.h>

/*
 * 	define linked list structure
*/

struct word_list {

	char			*word
	unsigned int		*line;
	unsigned int		*eolp;
	struct list		*next;

};

/*
 * 	global variables
*/

int current_line = 0;

/*
 * 	list_init - initialize a struct word_list
*/

void list_init(struct word_list *wl) {

	/*
	 * 	create a pointer (to be used as an array) to hold line
	 * 	numbers and point line to it
	*/

	int *temp = malloc(sizeof(int *));
	wl.line = temp;
	wl.eolp = wl.line;

	wl->word = NULL;
	wl->next = NULL;

}

/*
 * 	list_add_line - add a line number (ln) to the int array (line) in the
 * 			struct word_list (wl)
*/

void list_add_line(struct word_list *wl, static int ln) {

	wl->eolp = ln;

	wl.eolp = realloc(wl.line, sizeof(wl.line + 1));

}
