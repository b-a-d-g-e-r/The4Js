#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

#define VIRUS_INDEX 3

void saveAccount(struct player *currentAccount);
//All Jake Ennis
int tick(char map[20][40], int score, int day, struct player * currentAccount);
void generateMap(char map[20][40]);
void printMap(char map[20][40]);
void gameOver(int finalScore, int finalDays, struct player *currentAccount);
void selectMap(char map[20][40], char entity);

void playVirus(struct player* currentAccount) {
    int i, j, x, y, input = 0, alive = 1, basePlaced = 0, action = 0, day = 0, round = 0;
    char map[20][40];

    currentAccount->attempts[VIRUS_INDEX] = currentAccount->attempts[VIRUS_INDEX];
    saveAccount(currentAccount);


    printf("It's the year 2200, COVID has long since been irradicated...\n");
    printf("COVID-19 that is...\n");
    printf("VIRUS V^rRS VIR<<><MOIKM.\n");
    generateMap(map);

    while (alive == 1) {
        if(basePlaced == 0){
            printf("Where are we situated on this 20x40 plane of existance?\nEnter X coord: ");
			while(basePlaced == 0) {
				selectMap(map);
			}
            scanf("%d", &x);
            printf("Enter Y coord: ");
            scanf("%d", &y);
            map[x][y] = 2;
            basePlaced = 1;
            system("cls");
        }
        printMap(map);
        round = tick(map, score, day, currentAccount);
        printf("It's day %d, you got this.\n\nPlace Bomb >>> 1\nPlace Attacker >>> 2\nRandom Decay >>> 3\n\n", day);
		fflush(stdin);
		input = getch();
			if(input == 49) {
        		printf("Now where goes bang?\nEnter X coord: ");
           		scanf("%d", &x);
				printf("Enter Y coord: ");
         		scanf("%d", &y);
         		map[x][y] = ' ';
         		map[x+1][y] = ' ';
         		map[x-1][y] = ' ';
         		map[x][y+1] = ' ';
         		map[x][y-1] = ' ';
          		printf("KABOOOOM!");
           		Sleep(1000);
			}
       		else if(input == 50) {
				printf("ATTACK!\nEnter X coord: ");
				scanf("%d", &x);
        	    printf("Enter Y coord: ");
         	 	scanf("%d", &y);
				map[x][y]=64;
				Sleep(1000);
			}
        	else if(input == 51) {
            
			}
		day++;
        system("cls");
    }
}

int tick(char map[20][40], int score, int day, struct player * currentAccount) {
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
			if(map[x][y] == '@') {
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
                if((map[x-1][y] == 'B') && (rand() % 2 == 1)) {
                    gameOver(score, day, currentAccount);
                }
                if((map[x+1][y] == 'B') && (rand() % 2 == 1)) {
                    gameOver(score, day, currentAccount);
                }
                if((map[x][y-1] == '*') && (rand() % 2 == 1)) {
                    gameOver(score, day, currentAccount);
                }
                if((map[x][y+1] == '*') && (rand() % 2 == 1)) {
                    gameOver(score, day, currentAccount);
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

void gameOver(int finalScore, int finalDays, struct player *currentAccount) {
	printf("BLOODY HELL, this is bad!\n\n This reality is DOOOOOOMED");
	Sleep(500);
	printf(".");
	Sleep(500);
	printf(".");
	Sleep(500);
	printf(".");
	Sleep(2000);
	printf("It's okay that this is a simulation then\nYou survived %d days, scoring %d points", finalDays, finalScore);
	if(finalScore > currentAccount->scores[VIRUS_INDEX])
	{
		printf("\n\nNEW HIGH SCORE!!!");
		currentAccount->scores[VIRUS_INDEX] = finalScore;
		saveAccount(currentAccount);
	}
}

void selectMap(char map[20][40], char entity) {
	int input, x = 0, y = 0, selected = 0;
	char temp[20][40];
	input = getch();
	while(selected == 0) {
		temp[x][y] = map[x][y];
		map[x][y]=178;
		if(input == 119) {
			y++;
			// map[x][y-1] == temp[] //this line is usless as it is comaping two values and doing nothing with the result, so if it was supposed to do something you need to change that
		}
		if(input == 115) {
			y--;
		}
		if(input == 97) {
			x--;
		}
		if(input == 100) {
			x++;
		}
		if(input == 100) {
			selected = 1;
			map[x][y] = entity;
		}
		
	}
}


void saveAccount(struct player *currentAccount)
{
	FILE *fp;
	fp = fopen("accountInfo.bin", "rb+");
	fseek(fp, currentAccount->location, SEEK_SET);
	fwrite(currentAccount, sizeof(struct player), 1, fp);
}
