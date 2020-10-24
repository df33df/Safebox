#include "ncurses.h"
#include "string.h"
int authenticate(char userName[], char password[]);
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
int authenticate(char userName[], char password[]){
	char currentUserName[100];
	int len = 0;
	char c[len];
	int end = 1;
	int maxTry = 3;
	int attempts = 1;
	while(end) {
		printw("entrer votre username : ");
		getnstr(currentUserName, 99);
		if(strcmp(currentUserName,userName)==0){
        		printw("username valide\n");
			while(attempts <= maxTry) {
				char currentPassword[100] = "";
				int i = 0;
				printw("entrer votre password : ");
				noecho();
				while((*c = getch()) != 10){
					addch('*');
					i++;
					if (i < 100){
						strcat(currentPassword, c);
					}
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
	return 0;
}
/* compilation avec clang : clang -lncurses test_saisie.c */

