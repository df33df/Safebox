#include <ncurses.h>
#include <string.h>
#include "authenticate.h"

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
