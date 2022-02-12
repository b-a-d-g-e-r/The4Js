//created by JAKE ENNIS
//virusGame

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

int tick(char map[20][40], int day);
void generateMap(char map[20][40]);
void printMap(char map[20][40], int x, int y);
void gameOver(int finalDays);
int selectMap(char map[20][40], char entity);
 
void main() {
    int i, j, x, y, input = 0, alive = 1, basePlaced = 0, action = 0, day = 0;
    char map[20][40], bomb = 'O', base = 'B', fighter = 'F';
    printf("It's the year 2200, COVID has long since been irradicated...\n");
    printf("COVID-19 that is...\n");
    printf("VIRUS V^rRS VIR<<><MOIKM.\n");
    generateMap(map);

    while (alive == 1) {
        if(basePlaced == 0){
            printf("Where are we situated on this 20x40 plane of existance?\n\n");
			while(basePlaced == 0) {
				printf("\ntest\n");
				basePlaced = selectMap(map, base); 
            	system("cls");
			}
        }
        else{
	        printMap(map, -1, -1);
	        alive = tick(map, day);
	        printf("It's day %d, you got this.\n\nPlace Bomb >>> 1\nPlace Attacker >>> 2\n\n", day);
			fflush(stdin);
			do
			{
				input = getch();
				if(input == 49) {
					system("cls");
	        		printf("Now where goes bang?\n\n");
	           		if(selectMap(map, bomb) == -1)
	           		{
	           			alive = 0;
	           		}
	          		printf("\n\nKABOOOOM!");
					printMap(map,-1,-1);
	           		Sleep(1000);
				}
	       		else if(input == 50) {
					system("cls");
					printf("ATTACK!\n\n");
					selectMap(map, fighter);
					printMap(map, -1, -1);
					Sleep(1000);
				}
			}while(input != 49 && input != 50);
			day++;
	        system("cls");
	    }
    }
		system("cls");
		printf("BLOODY HELL, this is bad!\n\nThis reality is DOOOOOOMED\n\n");
		Sleep(500);
		printf(".");
		Sleep(500);
		printf(".");
		Sleep(500);
		printf(".");
		Sleep(2000);
		printf("It's okay that this is a simulation then\nYou survived %d days", day);
		Sleep(5000);
		
}

int tick(char map[20][40], int day) {
    srand(time(NULL));
    int x, y, virusTotal = 0;
    for(x = 0; x < 20; x++) {
        for(y = 0; y < 40; y++) {
            if(map[x][y] == 42) {
                if((map[x-1][y] == ' ') && (rand() % 2 == 1) && (virusTotal < 2)) {
                    map[x-1][y] = 42;
                    virusTotal++;
                }
                if((map[x+1][y] == ' ') && (rand() % 2 == 1) && (virusTotal < 2)) {
                    map[x+1][y] = 42;
                    virusTotal++;
                }
                if((map[x][y-1] == ' ') && (rand() % 2 == 1) && (virusTotal < 3)) {
                    map[x][y-1] = 42;
                    virusTotal++;
                }
                if((map[x][y+1] == ' ') && (rand() % 2 == 1) && (virusTotal < 3)) {
                    map[x][y+1] = 42;
                    virusTotal++;
                }
			}
			
			if(map[x][y] == 'F') {
                if((map[x-1][y] == '*') && (rand() % 2 == 1)) {
                    map[x-1][y] = ' ';
                }
                if((map[x+1][y] == '*') && (rand() % 2 == 1)) {
                    map[x+1][y] = ' ';
                }
                if((map[x][y-1] == '*') && (rand() % 2 == 1)) {
                    map[x][y-1] = ' ';
                }
                if((map[x][y+1] == '*') && (rand() % 2 == 1)) {
                    map[x][y+1] = ' ';
                }
            }

			if(map[x][y] == 'B') {
                if(map[x-1][y] == '*') {
                    return 0;
                }
                if(map[x+1][y] == '*') {
                    return 0;
                }
                if(map[x][y-1] == '*') {
                    return 0;
                }
                if(map[x][y+1] == '*') {
                    return 0;
                }
			}

			if((rand() % 10 > 9) && (map[x][y] == '*')) {
				map[x][y] = ' ';
			}

			if(map[x][y] == 'O') {
				map[x][y] = ' ';
         		map[x+1][y] = ' ';
         		map[x-1][y] = ' ';
         		map[x][y+1] = ' ';
         		map[x][y-1] = ' ';
			}
        }
    }
	return 1;
}


void generateMap(char map[20][40]) {
    srand(time(NULL));
	int i, j;
	for(i = 0; i < 20; i++) {
		for(j = 0; j < 40; j++) {
			map[i][j] = ' ';
		}
	}
    map[rand() % 20][rand() % 40] = '*';
}

void printMap(char map[20][40], int x, int y) {
	int i, j;
	for(i = 0; i < 20; i ++) {
		for(j = 0; j < 40; j ++) {
			if(i==y && j==x)
			{
				printf("%c",178);
			}
			else
			{
				printf("%c", map[i][j]);
			}
		}
		printf("\n");
	}
	printf("\n");
}

void gameOver(int finalDays) {
	

}

int selectMap(char map[20][40], char entity) {
	int input, x = 0, y = 0, selected = 0;
	char temp;
	printMap(map, x,y);
	while(selected == 0) {
		temp = map[x][y];
		do
		{
			fflush(stdin);
			input = getch();
			system("cls");
		}while(input == -32 || input == 0);
		if(input == 72) {
			y--;
			if(y < 0)
			{
				y = 19;
			}
			// map[x][y] = 178;
			// map[x+1][y]=' ';
			printMap(map,x,y);
		}
		if(input == 80) {
			y++;
			if(y>=20)
			{
				y = 0;
			}
			// map[x][y] = 178;
			// map[x-1][y]=' ';

			printMap(map,x,y);
		}
		if(input == 75) {
			x--;
			if(x<0)
			{
				x= 39;
			}
			// map[x][y] = 178;
			// map[x][y+1]=' ';
			printMap(map,x,y);
		}
		if(input == 77) {
			x++;
			if(x>=40)
			{
				x= 0;
			}
			// map[x][y] = 178;
			// map[x][y-1]=' ';
			printMap(map,x,y);
		}
		if(input == 13) {

			selected = 1;
			if(map[y][x] == 'B' && entity == 'O')
			{
				return -1;
			}

			if(map[y][x] == '*' && entity == 'B')
			{
				selected = 0;
			}
		}
	}
	map[y][x] = entity;
	return 1;
}
