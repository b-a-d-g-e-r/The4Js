#include"lingo.h"
#include"Mine Sweeper.h"
#include"Casino.h"
#include"chinesememory.h"

#include"randomgame.h"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

#define OPTIONS 9
#define SELECTIONS 4

//Jonathan made all of this part :)
struct stat
{
	char userName[10];
	int game;
	int score;
};

int logIn(struct player* playerStorage);
void pressTo();
int check(char userName[10]);
void scoreDisplay(struct player currentAccout);
int checkPossition(int game_index, struct player currentAccout);
void getLeader(struct stat list[5]);
void swapstat(struct stat *one, struct stat *two);
void setting();



int main()
{
	char Screen[23][80] = {
	" #######                  #######                               # ###        \n",
	"    #    #    # ######    #        ####  #    # #####           # ###  ####  \n",
	"    #    #    # #         #       #    # #    # #    #          #  #  #      \n",
	"    #    ###### #####     #####   #    # #    # #    #          # #    ####  \n",
	"    #    #    # #         #       #    # #    # #####     #     #          # \n",
	"    #    #    # #         #       #    # #    # #   #     #     #     #    # \n",
	"    #    #    # ######    #        ####   ####  #    #     #####       ####  \n",
	"                                                                             \n",
	"          #######                  #######                                   \n",
	"             #     ####  #####     #       # #    # ######      #            \n",
	"             #    #    # #    #    #       # #    # #           #            \n",
	"             #    #    # #    #    #####   # #    # #####     #####          \n",
	"             #    #    # #####     #       # #    # #           #            \n",
	"             #    #    # #         #       #  #  #  #           #            \n",
	"             #     ####  #         #       #   ##   ######                   \n",
	"                                                                             \n",
	"                    #####                                                    \n",
	"                   #     #   ##   #    # ######  ####                        \n",
	"                   #        #  #  ##  ## #      #                            \n",
	"                   #  #### #    # # ## # #####   ####                        \n",
	"                   #     # ###### #    # #           #                       \n",
	"                   #     # #    # #    # #      #    #                       \n",
	"                    #####  #    # #    # ######  ####                        \n"                                                                                                                                                                                                             
	};


	char end[15][70] =
	{
	" #######                                       #######               \n",
	"    #    #    #   ##   #    # #    #  ####     #        ####  #####  \n",
	"    #    #    #  #  #  ##   # #   #  #         #       #    # #    # \n",
	"    #    ###### #    # # #  # ####    ####     #####   #    # #    # \n",
	"    #    #    # ###### #  # # #  #        #    #       #    # #####  \n",
	"    #    #    # #    # #   ## #   #  #    #    #       #    # #   #  \n",
	"    #    #    # #    # #    # #    #  ####     #        ####  #    # \n",
	"                                                                     \n",
	"             ######                                                  \n",
	"             #     # #        ##   #   # # #    #  ####              \n",
	"             #     # #       #  #   # #  # ##   # #    #             \n",
	"             ######  #      #    #   #   # # #  # #                  \n",
	"             #       #      ######   #   # #  # # #  ###             \n",
	"             #       #      #    #   #   # #   ## #    #             \n",
	"             #       ###### #    #   #   # #    #  ####              \n"
	};

	char stats[7][45] =
	{
		"  #####                                     \n",
		" #     #  ####   ####  #####  ######  ####  \n",
		" #       #    # #    # #    # #      #      \n",
		"  #####  #      #    # #    # #####   ####  \n",
		"       # #      #    # #####  #           # \n",
		" #     # #    # #    # #   #  #      #    # \n",
		"  #####   ####   ####  #    # ######  ####  \n"		
	};


	char options[OPTIONS][20] = {
		"Lingo        ",
		"Mine Sweaper ",
		"Memory Game  ",
		"Virus Game?  ",
		"Enter Casino ",
		"Scores       ",
		"Leader Board ",
		"Settings     ",
		"Exit         "
	};

	int counter, lineCounter, letterCounter, optionCounter, flag = 1, selection = 0, loggedIn = 0;
	struct player acctiveAccount;
	char input;


	while(loggedIn == 0)
	{
		loggedIn = logIn(&acctiveAccount);
	}

	if(loggedIn == 1)
	{
		while(flag == 1)
		{
			system("cls");
			for(lineCounter = 0; lineCounter < 23; lineCounter ++)
			{
				for(letterCounter = 0; letterCounter < 80; letterCounter ++)
				{
					printf("%c", Screen[lineCounter][letterCounter]);
				}
			}

			printf("\n\n\n\n\n");

			printf("\t\t\t\t   ------------------\n");

			for(counter = 0; counter < OPTIONS; counter ++)
			{
				printf("\t\t\t\t  | ");
				for(letterCounter = 0; options[counter][letterCounter] != '\0'; letterCounter ++)
				{
					printf("%c", options[counter][letterCounter]);
				}

				if(counter == selection)
				{
					printf("<<< |");
				}

				else
				{
				printf("    |");
				}
				printf("\n");
			}

			printf("\t\t\t\t   ------------------\n");
			fflush(stdin);
			do
			{
				input = getch();
			}while(input == -32 || input == 0);

			printf("\n\n\n\n\n\n");

			system("cls");


			if(input == 'w' || input == 'W' || input == 72)
			{
				selection --;
			}

			else if(input == 'S' || input == 's' || input == 80)
			{
				selection ++;
			}



			if(selection  == OPTIONS)
			{
				selection = 0;
			}

			else if(selection == -1)
			{
				selection = OPTIONS - 1;
			}



			else if(input == 13)
			{
				system("cls");
				switch(selection)
				{
					case 0:
					//lingo
					playLingo(&acctiveAccount);
					break;

					case 1:
					// Mine Sweaper
					playMineSweaper(&acctiveAccount);
					writeAccount(&acctiveAccount);
					break;

					case 2:
					//Chinese Memory Game
					playChineseMemoryGame(&acctiveAccount);
					writeAccount(&acctiveAccount);
					break;

					case 3:
					//Jake's Virus Game, if ever finished
					writeAccount(&acctiveAccount);
					break;

					case 4:
					//Casino
					Casino(&acctiveAccount);
					writeAccount(&acctiveAccount);
					break;

					case 5:
					//stats
					for(counter = 0; counter < 7; counter ++)
					{
						printf("\t       ");
						for(letterCounter = 0; letterCounter < 45; letterCounter++)
						{
							printf("%c",stats[counter][letterCounter]);
						}
					}
					
					printf("\n\n\n");
					scoreDisplay(acctiveAccount);
					pressTo();
					break;

					case 6:
					getLeader(NULL);
					break;

					case 7:
					setting();
					break;

					case 8:
					//exit
					for(counter = 0; counter < 15; counter ++)
					{	printf("   ");
						for(letterCounter = 0; letterCounter < 70; letterCounter ++)
						{
							printf("%c", end[counter][letterCounter]);
						}

					}
					printf("\n\n\n\n\n\nPress enter to Exit or esc to return:");
					do
					{
						input = getch();
					}while(input != 13 && input != 27);

					if(input == 13)
					{
						flag = 0;
						system("color 07");
						printf("Thank you for playing, %s.", acctiveAccount.userName);
					}
					break;

				}
			}
		}
	}
}


int logIn(struct player* playerStorage)
{
	FILE * accountFile;
	struct player playerBuffer;
	struct stat statistics[5];

	int flag = 1, counter, letterCounter, selection = 0, logFlag = 0, accounts, conflict = 0;
	char input;
	char InUserName[10], InPassWord[10];

				
	accountFile = fopen("accountInfo.bin", "rb");
	fseek(accountFile, 0, SEEK_END);
	accounts = ftell(accountFile) / sizeof(struct player);
	fclose(accountFile);

	char options[SELECTIONS][20] = 
	{
		"Log in\t",
		"Sign up\t",
		"View Leader Board ",
		"Exit\t"
	};

	while(flag == 1)
	{
		printf("Which of these operations would you like to proceed with:\n\n\n");

		for(counter = 0; counter < SELECTIONS; counter ++)
		{
			for(letterCounter = 0; options[counter][letterCounter] != '\0'; letterCounter ++)
			{
				printf("%c", options[counter][letterCounter]);
			}

			if(counter == selection)
			{
				printf("  <<<");
			}
			printf("\n");
		}



		fflush(stdin);
		do
		{
			input = getch();
		}while(input == -32 || input == 0);

		printf("\n\n\n\n\n\n");

		system("cls");


		if(input == 'w' || input == 'W' || input == 72)
		{
			selection --;
		}

		else if(input == 'S' || input == 's' || input == 80)
		{
			selection ++;
		}

		else if(input == 13)
		{
			switch(selection)
			{



				case 0:
				if(accountFile == NULL)
				{
					accountFile = fopen("accountInfo.bin", "wb");
					fclose(accountFile);

				}

				fclose(accountFile);
				accountFile = fopen("accountInfo.bin", "rb");
				if(accounts > 0)
				{
					while(logFlag == 0)
					{
						system("cls");
						printf("Enter a user name or type 'exit' to return to menue: ");
						fflush(stdin);
						gets(InUserName);

						if(strcmp(InUserName, "exit") == 0)
						{
							return 0;
						}


						printf("\n\nEnter a password: ");
						fflush(stdin);
						gets(InPassWord );

						for(counter = 0; counter < accounts && logFlag == 0; counter ++)
						{
							fread(&playerBuffer, sizeof(struct player), 1, accountFile);
							if(strcmp(playerBuffer.userName, InUserName) == 0 && strcmp(playerBuffer.password, InPassWord) == 0)
							{
								printf("You have Succsessfuly logged in\n\n");
								pressTo();
								logFlag = 1;
								strcpy(playerStorage->userName, playerBuffer.userName);
								strcpy(playerStorage->password, playerBuffer.password);

								playerStorage->attempts[0] = playerBuffer.attempts[0];
								playerStorage->attempts[1] = playerBuffer.attempts[1];
								playerStorage->attempts[2] = playerBuffer.attempts[2];
								playerStorage->attempts[3] = playerBuffer.attempts[3];

								playerStorage->scores[0] = playerBuffer.scores[0];
								playerStorage->scores[1] = playerBuffer.scores[1];
								playerStorage->scores[2] = playerBuffer.scores[2];
								playerStorage->scores[3] = playerBuffer.scores[3];
								playerStorage->scores[4] = playerBuffer.scores[4];

								playerStorage->location = playerBuffer.location;
								return 1;
							}
						}
					puts("Faild to log in\n\n");
					printf("\n\n");
					}
				}

				else
				{
					printf("There are no accouts on this machine or an error had occured\n");
					pressTo();
				}

				fclose(accountFile);
				break;




				case 1:
				while(logFlag == 0)
				{
					accountFile = fopen("accountInfo.bin", "rb");
					conflict = 0;
					do
					{
						system("cls");
						printf("Enter a 2-10 letter user name or type 'exit' to return to menue: ");
						fflush(stdin);
						gets(InUserName);
					}while(check(InUserName) == 0);

					if(strcmp(InUserName, "exit") == 0)
					{
						return 0;
					}

					for(counter = 0; counter < accounts && conflict ==0; counter++)
					{
						fread(&playerBuffer, sizeof(struct player), 1, accountFile);
						if(strcmp(playerBuffer.userName, InUserName) == 0)
						{
							conflict = 1;
						}
					}

					if(conflict == 1)
					{
						printf("This user name has already been taken\n");
						pressTo();
						return 0;
					}

					do
					{
						system("cls");
						printf("Now enter a 2-10 letter password: ");
						fflush(stdin);
						gets(InPassWord);
					}while(check(InPassWord) == 0);

					system("cls");
					printf("Are you sure you want these credentials:\n\n\nUser Name - %s\nPassword - %s\n\n", InUserName, InPassWord);
					
					printf("\n\n\n\n\n\nPress enter to confirm or esc to return:");
					do
					{
						fflush(stdin);
						input = getch();
					}while(input != 13 && input != 27);

					if(input == 13)
					{
						printf("\n\n");
						strcpy(playerStorage->userName, InUserName);
						strcpy(playerStorage->password, InPassWord);

						playerStorage->scores[0] = 0;
						playerStorage->scores[1] = 0;
						playerStorage->scores[2] = 0;
						playerStorage->scores[3] = 0;
						playerStorage->scores[4] = 50;

						playerStorage->attempts[0] = 0;
						playerStorage->attempts[1] = 0;
						playerStorage->attempts[2] = 0;
						playerStorage->attempts[3] = 0;
						playerStorage->scores[4] = 50;

						fseek(accountFile, 0, SEEK_END);
						playerStorage->location = ftell(accountFile) / sizeof(struct player);

						fclose(accountFile);
						fopen("accountInfo.bin", "ab");
						fwrite(playerStorage, sizeof(struct player), 1, accountFile);
						fclose(accountFile);
						return 1;
					}
					return 0;
				}
				break;

				case 2:
				getLeader(statistics);
				return 0;
				break;

				case 3:
				return -1;
				break;

			}
		}


		if(selection  == SELECTIONS)
		{
			selection = 0;
		}

		else if(selection == -1)
		{
			selection = SELECTIONS - 1;
		}

	}
	return 1;
}


void pressTo()
{
	char input;
	printf("Press enter to continue...");
	do
	{
		fflush(stdin);
		input = getch();
	}while(input != 13);

	printf("\n");
	system("cls");
}

int check(char userName[10])
{
	int counter;
	int flag = 0;

	for(counter = 2; counter < 10 && flag == 0; counter ++)
	{
		if(userName[counter] == '\0')
		{
			flag = 1;
		}
	}
	return flag;
}

void scoreDisplay(struct player currentAccout)
{
	char Games[5][20] = {
		"    Lingo    ",
		"Mine  Sweaper",
		" Memory Game ",
		" Virus Game? "
	};

	int counter;

	for(counter = 0; counter < 4; counter ++)
	{
		printf("\t\t\t\t%s\n", Games[counter]);
		printf("\n");
		printf("\t\t\tHigh score\t-\t %d", currentAccout.scores[counter]);
		printf("\n\t\t\tAttempts\t-\t %d", currentAccout.attempts[counter]);
		printf("\n\t\t\tPossition\t-\t %d",checkPossition(counter, currentAccout));
		printf("\n\n\n");
	}
}

int checkPossition(int game_index, struct player currentAccout)
{
	int possition = 0,people = 0, counter, size;
	struct player bufferAccount;


	FILE * fp;

	fp = fopen("accountInfo.bin", "rb");

	if(fp != NULL)
	{
		fseek(fp, 0, SEEK_END);
		size = ftell(fp) / sizeof(struct player);
		fseek(fp, 0, SEEK_SET);	

		for(counter = 0; counter < size; counter ++)
		{
			fread(&bufferAccount, sizeof(struct player), 1, fp);
			people ++;
			if(currentAccout.scores[game_index] > bufferAccount.scores[game_index])
			{
				possition ++;
			}
		}
	}
	return people - possition;
}

void getLeader(struct stat list[5])
{
	FILE * fp;
	int game_index;
	int size, counter1, counter2;
	int selection = 0;
	struct player playerBuf;
	char tempName[10];
	int tempScore, temp;
	int input, swapped = 1;

	char options[5][20] = {
	"Lingo        ",
	"Mine Sweaper ",
	"Memory Game  ",
	"Virus Game?  ",
	"Casino       "
	};


	printf("\n\n\n");
	do
	{
		printf("\n\n");
		system("cls");
		printf("What game do you want to see the leader board for?\n\n");

		printf("\t\t\t\t -----------------\n");
		for(counter1 = 0; counter1 < 5; counter1 ++)
		{
			printf("\t\t\t\t| %s", options[counter1]);
			if(selection == counter1)
			{
				printf(" < |");
			}

			else
			{
				printf("   |");
			}
			printf("\n");
		}
		printf("\t\t\t\t -----------------");
		input = getMove();

		switch(input)
		{
			case 1:
			selection --;
			if(selection < 0)
			{
				selection = 4;
			}
			break;

			case 2:
			selection ++;
			if(selection >= 5)
			{
				selection = 0;
			}
			break;
		}


	}while(input != 5 && input != 6);

	if(input == 5)
	{
		game_index = selection;
		fp = fopen("accountInfo.bin", "rb");
		fseek(fp, 0, SEEK_END);
		size = ftell(fp) / sizeof(struct player);
		fseek(fp, 0, SEEK_SET);

		struct stat statistics[size];

		for(counter1 = 0; counter1 < size; counter1 ++)
		{
			fread(&playerBuf, sizeof(struct player), 1, fp);
			strcpy(statistics[counter1].userName, playerBuf.userName);
			statistics[counter1].score = playerBuf.scores[game_index];
			statistics[counter1].game = game_index;
		}
		fclose(fp);


		for(counter1 = 1; counter1 < size; counter1 ++)
		{
			temp = counter1 - 1;
			while(statistics[temp+1].score > statistics[temp].score && temp >= 0)
			{
				swapstat(&statistics[temp], &statistics[temp +1]);
				temp--;
			}
		}

		system("cls");
		printf("\n\n");
		printf("\t\t\tName   -   Score\n\n");
		for(counter1 = 0; counter1 < size; counter1 ++)
		{
			if(game_index == 4)
			{
				printf("\t\t\t%s  -   %c%d\n", statistics[counter1].userName, POUND, statistics[counter1].score);
			}

			else
			{
				printf("\t\t\t%s  -   %d\n", statistics[counter1].userName, statistics[counter1].score);
			}
		}
		printf("\n\n");
		pressTo();
	}
}

void swapstat(struct stat *one, struct stat *two)
{
	char tempName[20];
	int tempScore;

	strcpy(tempName, one->userName);
	tempScore = one->score;

	strcpy(one->userName, two->userName);
	one->score =two->score;

	strcpy(two->userName, tempName);
	two->score = tempScore;	
}

void setting()
{
	int section=0, selection=0, input,counter, back = -1, front = -1;
	char backColor, frontColor;
	char command[10];

	char firstSelections[4][19] =
	{
		"     Black    ",
		"     White    ",
		" Bright Green ",
		" Normal Green "
	};

	system("color");
	do
	{
		system("cls");
		printf("\t\t\t\t ---------------------- \n");
		printf("\t\t\t\t|   Background Color   |\n");
		printf("\t\t\t\t|                      |\n");
		for(counter = 0; counter < 4; counter ++)
		{
			if(selection == counter && section == 0)
			{
				printf("\t\t\t\t|    %s<<< |\n", firstSelections[counter]);
			}

			else
			{
				printf("\t\t\t\t|    %s    |\n", firstSelections[counter]);
			}
		}


		printf("\t\t\t\t|                      |\n");
		printf("\t\t\t\t|                      |\n");
		printf("\t\t\t\t|   Foreground Color   |\n");
		printf("\t\t\t\t|                      |\n");
		for(counter = 0; counter < 4; counter ++)
		{
			if(selection == counter && section == 1)
			{
				printf("\t\t\t\t|    %s<<< |\n", firstSelections[counter]);
			}

			else
			{
				printf("\t\t\t\t|    %s    |\n", firstSelections[counter]);
			}
		}

		printf("\t\t\t\t|                      |\n");
		printf("\t\t\t\t|                      |\n");

		if(section == 1 && selection == 4)
		{
			printf("\t\t\t\t|A tribute to Rhys Mils| <<<\n");
		}

		else
		{
			printf("\t\t\t\t|A tribute to Rhys Mils|\n");
		}

		printf("\t\t\t\t|                      |\n");
		printf("\t\t\t\t ---------------------- \n");

		input = getMove();

		switch(input)
		{
			case 1:
			selection--;

			if(section == 0)
			{
				if(selection < 0)
				{
					selection = 3;
				}
			}

			else
			{
				if(selection < 0)
				{
					selection = 4;
				}
			}

			break;

			case 2:
			selection ++;


			if(section == 0)
			{
				if(selection > 3)
				{
					selection = 0;
				}
			}

			else
			{
				if(selection > 4)
				{
					selection = 0;
				}
			}
			break;

			case 5:
			if(section == 0)
			{
				front = selection;
				section ++;
			}

			else
			{
				if(selection != 4)
				{
					back = selection;
					input = 6;
					printf("\nTest\n");
				}
				else
				{
					playBox();
				}
			}
			break;
		}
	}while(input != 6);

	switch(front)
	{
		case 0:
		frontColor = '0';
		break;

		case 1:
		frontColor = '7';
		break;

		case 2:
		frontColor = 'A';
		break;

		case 3:
		frontColor = '2';
		break;
	}

	switch(back)
	{
		case 0:
		backColor = '0';
		break;

		case 1:
		backColor = '7';
		break;

		case 2:
		backColor = 'A';
		break;

		case 3:
		backColor = '2';
		break;
	}
	sprintf(command, "color %c%c", backColor, frontColor);
	system(command);
}
