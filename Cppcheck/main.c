#include <ncurses.h>
#include <string.h>
#include "authenticate.h"


void free(void *ptr);

int main(void) {	
	WINDOW *boite;
	char userName[100] = "username";
	char password[100] = "password";
    	initscr();
	authenticate(userName,password);
	printw("appuyer sur une touche pour quitter");
	getch();
    	endwin();

	free(boite);
}


/* compilation avec clang : clang -lncurses test_saisie.c */
