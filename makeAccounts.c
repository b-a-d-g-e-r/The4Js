#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define GAME_COUNT 4

struct player
{
	char userName[10];
	char password[10];
	int scores[5];
	int attempts[4];
	int location;
};

int main()
{
	FILE *accountFile;
	struct player newPlayer;
	int counter,counter1, accounts;
	int flag = 1;
	char input;

	struct player jake;
	struct player john;
	struct player jaco;
	struct player james;

	strcpy(jake.userName, "Jake");
	strcpy(jake.password, "Ennis");

	jake.scores[0] = 7;
	jake.scores[1] = 75;
	jake.scores[2] = 650;
	jake.scores[3] = 100;
	jake.scores[4] = 123;

	jake.attempts[0] = 20;
	jake.attempts[1] = 1;
	jake.attempts[2] = 7;
	jake.attempts[3] = 100;

	jake.location = 0;




	strcpy(john.userName, "Jonathan");
	strcpy(john.password, "Noble");

	john.scores[0] = 0;
	john.scores[1] = 483;
	john.scores[2] = 200;
	john.scores[3] = 80;
	john.scores[4] = 32;

	john.attempts[0] = 176;
	john.attempts[1] = 5;
	john.attempts[2] = 80;
	john.attempts[3] = 10;

	john.location = 1;



	strcpy(jaco.userName, "Jacob");
	strcpy(jaco.password, "Symes");

	jaco.scores[0] = 4;
	jaco.scores[1] = 300;
	jaco.scores[2] = 850;
	jaco.scores[3] = 40;
	jaco.scores[4] = 146;

	jaco.attempts[0] = 23;
	jaco.attempts[1] = 11;
	jaco.attempts[2] = 7;
	jaco.attempts[3] = 64;

	jaco.location = 2;


	strcpy(james.userName, "James");
	strcpy(james.password, "Vinson");

	james.scores[0] = 1;
	james.scores[1] = 5;
	james.scores[2] = 72;
	james.scores[3] = 15;
	james.scores[4] = 200;

	james.attempts[0] = 12;
	james.attempts[1] = 15;
	james.attempts[2] = 79;
	james.attempts[3] = 10;

	james.location = 3;



	accountFile = fopen("accountInfo.bin", "wb");
	fwrite(&jake, sizeof(struct player), 1, accountFile);
	fwrite(&john, sizeof(struct player), 1, accountFile);
	fwrite(&jaco, sizeof(struct player), 1, accountFile);
	fwrite(&james, sizeof(struct player), 1, accountFile);
	fclose(accountFile);

	return 0;
}