#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int a = 10;
void game()
{
	int i = 0;	
	int score = 0;
	while (i == 0)
	{
		system("cls");
		int x = rand()%a;
		int g = 0;
		printf("           +--------------+\n          /|             /|\n         / |            / |\n        *--+-----------*  |\n        |  |           |  |\n        |  |           |  |\n        |  |           |  |\n        |  +-----------+--+\n        | /            | /\n        |/             |/\n        *--------------*");
		printf("\n\nWhat is the number in the box? = ");
		scanf("%d",&g);
		system("cls");
		printf("           +--------------+\n          /|             /|\n         / |            / |\n        *--+-----------*  |\n        |  |           |  |\n        |  |     %d     |  |\n        |  |           |  |\n        |  +-----------+--+\n        | /            | /\n        |/             |/\n        *--------------*",x);
		if (g == x)
		{
			printf("\n\nCorrect!");
			score++;
		}
		else
		{
			printf("\n\nWrong!");
			i++;
		}
		printf("\nScore = %d",score);
	}
	printf("\nGame Over!\n\n");
	system("PAUSE");
	system("cls");
}

int playBox()
{
	system("cls");
	srand (time(NULL));
	int select = 0;
	printf("Welcome to Guess the Number!\nWould you like to :\n1. Play\n2. Settings\n3. Exit\n\n:");
	scanf("%d",&select);
	system("cls");
	switch (select)
	{
		case 1:
			game();
			break;
		case 2:
			printf("Adjust difficulty : \n1. Easy\n2. Medium\n3. Hard\n4. Expert\n\n:");
			scanf("%d",&select);
			switch (select)
			{
				case 1:
					printf("Easy selected.\n");
					a = 10;
					break;
				case 2:
					printf("Medium selected.\n");
					a = 30;
					break;
				case 3:
					printf("Hard selected.\n");
					a = 50;
					break;
				case 4:
					printf("Expert selected.\n");
					a = 100;
					break;
			}
			system("PAUSE");
			playBox();
		case 3:
			return 0; 
		default:
			printf("Invalid Input!\n");
	}
	playBox();
	return 0;
}
