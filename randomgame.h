#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>

void endless();

int a = 10;
void boxgame()
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

int playbox()
{
	system("cls");
	srand (time(NULL));
	int select = 0;
	printf("Welcome to Guess the Number!\nWould you like to :\n1. Play\n2. Endless\n3. Settings\n4. Exit\n\n:");
	scanf("%d",&select);
	system("cls");
	switch (select)
	{
		case 1:
			boxgame();
			break;
		case 2:
			system("cls");
			endless();
		case 3:
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
			playbox();
		case 4:
			return 0; 
		default:
			printf("Invalid Input!\n");
	}
	playbox();
	return 0;
}


void endless()
{
	a = 5;
	printf("============= GUESS THE NUMBER =============\n");
	printf("=============   ENDLESS MODE   =============\n\n-Values can only range from (0 - 5).\n-Game will not end until score of 10, has been reached.\n\n"); 
	system("PAUSE");                                                                    
	int i = 0;	
	int temp2 = 0;
	int times = 0;
	int kimes = 0;
	int attempts = 0;
	int af = 0;
	int length  = 1;
	int guess[100],answers[100];
	int score = 0;
	int x = rand()%a;
	for (kimes = 0;kimes<20;kimes++)
	{
		guess[kimes] = 0;
		answers[kimes] = 0;
	}
	while (i == 0)
	{
		system("cls");
		int g = 0;
		int temp;
		int s = rand()%20;
		printf("           +--------------+\n          /|             /|\n         / |            / |\n        *--+-----------*  |\n        |  |           |  |\n        |  |           |  |\n        |  |           |  |\n        |  +-----------+--+\n        | /            | /\n        |/             |/\n        *--------------*");
		printf("\n\nWhat is the number in the box? = ");
		scanf("%d",&g);
		while ((x == g) || (x > 5 ))
		{
			x = rand()%a;
		}
		if (s == 9)
		{
			g = rand()&50 + 1;
		}
		system("cls");
		printf("           +--------------+\n          /|             /|\n         / |            / |\n        *--+-----------*  |\n        |  |           |  |\n        |  |     %d     |  |\n        |  |           |  |\n        |  +-----------+--+\n        | /            | /\n        |/             |/\n        *--------------*",x);
		attempts++;
		printf("\nYou guessed = %d\n\nWrong!\nScore = %d\nAttempts = %d\n",g,score,attempts);
		if (g > 5)
		{
			printf("\nPlease keep your value within range of ( 0 - 5 ).");
		}
		guess[af] = g;
		answers[af] = x;
		temp = guess[0];
		temp2 = answers[0];
		for (times = 0 ;times < 19; times++)
		{
			guess[times] = guess[times+1];
			answers[times] = answers[times+1];
		}
		guess[19] = temp;
		answers[19] = temp2;
		for (times = 0;times<20;times++)
		{
			printf("%d, ",guess[times]);
		}
		for (times = 0;times<20;times++)
		{
			printf("%d, ",answers[times]);
		}
		printf("].\n\n");
		x = g;
		times = 0;
		system("PAUSE");
	}
		
}
