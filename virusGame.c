#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

void tick(char map[20][40], int day);
void generateMap(char map[20][40]);
void printMap(char map[20][40]);
void gameOver(int finalDays);
void selectMap(char map[20][40], char entity);

void main() {
    int i, j, x, y, input = 0, alive = 1, basePlaced = 0, action = 0, day = 0, round = 0;
    char map[20][40], bomb = 155, base = 206, fighter = 245;
    printf("It's the year 2200, COVID has long since been irradicated...\n");
    printf("COVID-19 that is...\n");
    printf("VIRUS V^rRS VIR<<><MOIKM.\n");
    generateMap(map);

    while (alive == 1) {
        if(basePlaced == 0){
            printf("Where are we situated on this 20x40 plane of existance?");
			while(basePlaced == 0) {
				selectMap(map, base);
				basePlaced = 1;
			}
            system("cls");
        }
        printMap(map);
        tick(map, day);
        printf("It's day %d, you got this.\n\nPlace Bomb >>> 1\nPlace Attacker >>> 2\nRandom Decay >>> 3\n\n", day);
		fflush(stdin);
		input = getch();
			if(input == 49) {
        		printf("Now where goes bang?");
           		selectMap(map, bomb);
          		printf("KABOOOOM!");
				printMap(map);
           		Sleep(1000);
			}
       		else if(input == 50) {
				printf("ATTACK!");
				selectMap(map, fighter);
				printMap(map);
				Sleep(1000);
			}
        	else if(input == 51) {
            
			}
		day++;
        system("cls");
    }
}

void tick(char map[20][40], int day) {
    srand(time(NULL));
    int x, y, virusTotal = 0;
    for(x = 0; x < 20; x++) {
        for(y = 0; y < 40; y++) {
            if(map[x][y] == '*') {
                if((map[x-1][y] == ' ') && (rand() % 2 == 1) && (virusTotal < 2)) {
                    map[x-1][y] = '*';
                    virusTotal++;
                }
                if((map[x+1][y] == ' ') && (rand() % 2 == 1) && (virusTotal < 2)) {
                    map[x+1][y] = '*';
                    virusTotal++;
                }
                if((map[x][y-1] == ' ') && (rand() % 2 == 1) && (virusTotal < 3)) {
                    map[x][y-1] = '*';
                    virusTotal++;
                }
                if((map[x][y+1] == ' ') && (rand() % 2 == 1) && (virusTotal < 3)) {
                    map[x][y+1] = '*';
                    virusTotal++;
                }
			}
			if(map[x][y] == 245) {
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
			if(map[x][y] == '*') {
                if(map[x-1][y] == 'B') {
                    gameOver(day);
                }
                if(map[x+1][y] == 'B') {
                    gameOver(day);
                }
                if(map[x][y-1] == 'B') {
                    gameOver(day);
                }
                if(map[x][y+1] == 'B') {
                    gameOver(day);
                }
			if(map[x][y] == 155) {
				map[x][y] = ' ';
         		map[x+1][y] = ' ';
         		map[x-1][y] = ' ';
         		map[x][y+1] = ' ';
         		map[x][y-1] = ' ';
			}
            }
        }
	}
	if(virusTotal == 0) {
		generateMap(map);
		return 1;
	}
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

void printMap(char map[20][40]) {
	int i, j;
	for(i = 0; i < 20; i ++) {
		for(j = 0; j < 40; j ++) {
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
}

void gameOver(int finalDays) {
	printf("BLOODY HELL, this is bad!\n\n This reality is DOOOOOOMED");
	Sleep(500);
	printf(".");
	Sleep(500);
	printf(".");
	Sleep(500);
	printf(".");
	Sleep(2000);
	printf("It's okay that this is a simulation then\nYou survived %d days", finalDays);
}

void selectMap(char map[20][40], char entity) {
	int input, x = 0, y = 0, selected = 0;
	char temp[20][40];
	printMap(map);
	while(selected == 0) {
		temp[x][y] = map[x][y];
		map[x][y]=178;
		do
		{
			fflush(stdin);
			input = getch();
			system("cls");
		}while(input == -32 || input == 0);
		if(input == 72) {
			x--;
			map[x+1][y]=temp[x+1][y];
			printMap(map);
		}
		if(input == 80) {
			x++;
			map[x-1][y]=temp[x-1][y];
			printMap(map);
		}
		if(input == 75) {
			y--;
			map[x][y+1]=temp[x][y+1];
			printMap(map);
		}
		if(input == 77) {
			y++;
			map[x][y-1]=temp[x][y-1];
			printMap(map);
		}
		if(input == 13) {
			selected = 1;
			map[x][y] = entity;
		}
	}
}