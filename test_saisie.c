#include "ncurses.h"
#include "string.h" 
int main(void) {	
	WINDOW *boite;
	int end = 1;
	int maxTry = 3;
	int attempts = 1;
	int len = 0;
	char userName[100] = "username";
	char password[100] = "password";
	char currentUserName[100];
	char c[len];
    	initscr();
	while(end) {
		printw("entrer votre username : ");
		getstr(currentUserName);
		if(strcmp(currentUserName,userName)==0){
        		printw("username valide\n");
			while(attempts <= maxTry) {
				char currentPassword[100] = "";
				printw("entrer votre password : ");
				noecho();
				while((*c = getch()) != 10){
					addch('*');
					strcat(currentPassword, c);
					len--;	
					refresh();	
				}
				echo();
				if(strcmp(currentPassword,password)==0){
					printw("\npassword valide\n");
					attempts = 4;
				}
				else{
					printw("\npassword invalide\n");
					printw("essaie restant: %d \n", 3-attempts);
					attempts++;					
				}
			}
			end = 0;
		}
		else{
			printw("username invalide\n");
		}
    	}
	printw("appuyer sur une touche pour quitter");
	getch();
    	endwin();

	free(boite);
    
	return 0;
}
/* compilation avec clang : clang -lncurses test_saisie.c */
