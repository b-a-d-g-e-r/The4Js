#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include<string.h>
#include<ctype.h>

#define POUND 156
#define CASINO_INDEX 4

void roulette(int *money);
void blackjack(int *money);
void slotmachine(int *money);


int Casino(struct player* currentAccount)
{
    int gameOver=0, choice;
    int *money = &(currentAccount->scores[CASINO_INDEX]);


    while(gameOver==0)
    {
        if(*money==0)
        {
            printf("\nAll out of money, Sorry :(\n");
            gameOver=1;
        }
        
        else
        {
            printf("Welcome,%s, to the underage gambling simulator.\nDo you want to play:\n1: Blackjack\n2: Roulette\n3: Slot Machine\n4: Exit\n", currentAccount->userName);
            scanf("%d",&choice);
            switch(choice)
            {
                case 1:
                blackjack(money);
                break;

                case 2: 
                roulette(money);
                break;

                case 3:
                slotmachine(money);
                break;

                case 4: 
                gameOver=1;
                return 0;
                break;
           }
        }
    }
}

void blackjack(int *money)
{
    int bet = 0;
    int pscore=0,dscore=0,i=0,card,j=0,rannum2,dturn;
    int Brepeat=0;
    char symbol[4][10] = {"Hearts\0","Diamonds\0","Clubs\0","Spades\0"};
    char draw[10];
    char checker[2][10] = {"draw\0","stand\0"};
    
    printf("\nWelcome to Blackjack.");
    while(Brepeat==0)
    {
        if(*money<=0)
        {
            Brepeat=1;
            dturn=1;
        }

        else
        {
            dturn=0;
            printf("\nYou have %c%d\nEnter how much you want to bet or enter '0' to return to the game select ",POUND, *money);
            scanf("%d",&bet);

            while(bet>*money)
            {
                printf("You only ave %c%d, Enter a valid bet: ",POUND, *money);
                scanf("%d",&bet);
            }

            if(bet==0)
            {
                Brepeat=1;
                dturn=1;
            }

            else
            {
                *money=*money-bet;
                // your turn
                pscore=0;
                j=0;

                while(j==0)
                {
                    srand(time(NULL));
                    card=rand() % 13;
                    rannum2=rand() % 4;
                    switch(card)
                    {
                        case 0:
                        printf("Ace of %s, 1 point",symbol[rannum2]);
                        pscore=pscore+1;
                        break;

                        case 1:
                        printf("Ace of %s, 1 point",symbol[rannum2]);
                        pscore=pscore+1;
                        break;

                        case 11:
                        printf("Jack of %s, 10 points",symbol[rannum2]);
                        pscore=pscore+10;
                        break;

                        case 12:
                        printf("Queen of %s, 10 points",symbol[rannum2]);
                        pscore=pscore+10;
                        break;

                        case 13:
                        printf("King of %s, 10 points",symbol[rannum2]);
                        pscore=pscore+10;
                        break;

                        default:
                        printf("%d of %s, %d points",card,symbol[rannum2],card);
                        pscore=pscore+card;
                        break;

                    }
                    
                    if(pscore==21)
                    {
                        bet=bet*2;
                        printf("\nBlackjack! You scored exactly 21 and received %c%d",POUND, bet);
                        *money=*money+bet;
                        j=1;
                        dturn=1;
                    }

                    else if(pscore>21)
                    {
                        printf("\nYou went bust, unlucky.");
                        j=1;
                        dturn=1;
                    }
                    
                    else
                    {
                        printf("\nYour total score is %d\nWould you like to Draw or Stand? ",pscore);
                        scanf("%s",&draw);
                        for(i=0;i<5;i++)
                        {
                            draw[i]=tolower(draw[i]);
                        }

                        if(strcmp(draw,checker[0])!=0)
                        {
                            j=1;
                        }
                    }
                }

                // Dealers turn
                if(dturn==0)
                {
                    dscore=0;
                    while(dscore<=pscore)
                    {
                        srand(time(NULL));
                        card=rand() % 13; 
                        rannum2=rand() % 4;

                        switch(card)
                        {
                            case 0:
                            printf("Dealer draws an Ace of %s, 1 point",symbol[rannum2]);
                            dscore=dscore+1;
                            break;

                            case 1:
                            printf("Dealer draws an Ace of %s, 1 point",symbol[rannum2]);
                            dscore=dscore+1;
                            break;

                            case 11:
                            printf("Dealer draws a Jack of %s, 10 points",symbol[rannum2]);
                            dscore=dscore+10;
                            break;

                            case 12:
                            printf("Dealer draws a Queen of %s, 10 points",symbol[rannum2]);
                            dscore=dscore+10;
                            break;

                            case 13:
                            printf("Dealer draws a King of %s, 10 points",symbol[rannum2]);
                            dscore=dscore+10;
                            break;

                            default:
                            printf("Dealer draws a %d of %s, %d points",card,symbol[rannum2],card);
                            dscore=dscore+card;
                            break;
                        }

                        printf("\nDealer's total score is %d\n",dscore);
                        sleep(2);
                    }
    
                    if(dscore>pscore && dscore<=21)
                    {
                        printf("**Dealer scored %d, you lose :(**",dscore);
                    }
        
                    else
                    {
                        bet=bet*2;
                        printf("**Dealer went bust, You win and receive %c%d**",POUND, bet);
                        *money=*money+bet;
                    }
                }
            }
        }
    }
}

void roulette(int *money)
{
    int Rrepeat=0, bet = 0, choice;
    printf("\nWelcome to roulette\n");
    char colour[2][10]={"black\0","red\0"};
    char colourg[10];
    int numg,check;

    while(Rrepeat==0)
    {
        if(*money==0)
        {
            Rrepeat=1;
        }

        else
        {
            printf("You have %c%d\nHow much would you like to bet? ",POUND, *money);
            scanf("%d",&bet);
            while(bet>*money)
            {
                printf("Not enough money, You only have %c%d. Enter a bet: ",POUND, *money);
                scanf("%d",&bet);
            }
            *money=*money-bet;

            srand(time(NULL));
            int rannum=rand() % 50;
            int rancol=rand() % 2;

            printf("\nWould you like to guess the:\n1: Colour(x2 payout)\n2: Number(x5 payout)\n3: Number and Colour(x20 payout)\n4: Switch Game\n ");
            scanf("%d",&choice);

            switch(choice)
            {
                case 1: 
                printf("\nEnter the colour you think it will be (red or black)\n");
                scanf("%s",&colourg);
                check=strcmp(colourg,colour[rancol]);

                if(check==0)
                {
                    bet=bet*2;
                    printf("\nCorrect, the wheel landed on %s %d You receive %c%d\n",colour[rancol],rannum,POUND, bet);
                    *money=*money+bet;
                }

                else
                {
                    printf("\nYou were wrong, the wheel landed oh %s %d\n ",colour[rancol],rannum);
                }
                break;

                case 2:
                printf("\nEnter the number you think it will land on: ");
                scanf("%d",&numg);

                if(numg==rannum)
                {
                    bet=bet*5;
                    printf("\nCorrect, the wheel landed on %s %d You receive %c%d\n",colour[rancol],rannum,POUND, bet);
                    *money=*money+bet;
                }

                else
                {
                    printf("\nYou were wrong, the wheel landed on %s %d\n ",colour[rancol],rannum);
                }
                break;

                case 3: 
                printf("\nEnter the colour you think it will be (red or black)\n");
                scanf("%s",&colourg);
                check=strcmp(colourg,colour[rancol]);
                printf("\nEnter the number you think it will land on: ");
                scanf("%d",&numg);

                if(check==0 && numg==rannum)
                {
                    bet=bet*20;
                    printf("\nJackpot! the wheel landed on %s %d and you guessed it right! you receive %c%d",colour[rancol],rannum,POUND, bet);
                    *money=*money+bet;
                }

                else
                {
                    printf("\nUnlucky, the wheel landed on %s %d, Better luck next time.",colour[rancol],rannum);
                }
                break;

                case 4:
                *money=*money+bet;
                Rrepeat=1;
                break;
            }
        }
    }
}

void slotmachine(int *money)
{
    int bet = 0;
    int l,k=0,ranspina,ranspinb,ranspinc;
    char choice[4];
   
    char output[10][15] = {"Rolling\0","Rolling\0","Rolling\0,","Cherry\0","Banana\0","Orange\0","Lime\0","lemon\0","Strawberry\0","Jackpot\0"};
    printf("\nWelcome to the slot machine. Match 3 fruits to win a prize.");
    
    while(k==0)
    {
        printf("\nYou have %c%d\nWould you like to: \nplay (%c1)\nExit to menu\n",POUND, *money, POUND);
        fflush(stdin);
        scanf("%s",&choice);
        srand(time(NULL));

        for(l=0;l<4;l++)
        {
            choice[l] = tolower(choice[l]);
        }

        if(strcmp(choice,"exit")==0)
        {
            k=1;
        }

        else if(strcmp(choice,"play")==0)
        {
             ranspinb = rand() % 6;
             ranspinc = rand() % 6;
             ranspina = rand() % 6;
            
            *money=*money-1;
            for(l=0;l<4;l++)
            { 
                switch(l)
                {
                    case 0:
                    printf("\nRolling Rolling Rolling");
                    break;

                    case 1:
                    printf("\n%s Rolling Rolling",output[ranspina+3]);
                    sleep(2);
                    break;

                    case 2:
                    printf("\n%s %s Rolling",output[ranspina+3],output[ranspinb+3]);
                    sleep(2);
                    break;

                    case 3:
                    printf("\n%s %s %s\n",output[ranspina+3],output[ranspinb+3],output[ranspinc+3]);
                    sleep(2);
                    break;
                }
            }

            if(ranspina ==ranspinb && ranspinb == ranspinc)
            {
                switch(ranspina)
                {
                    case 6: 
                    *money=*money+10000;
                    printf("**Jackpot!** You won %c10,000", POUND);
                    break;

                    default:
                    printf("Well done! You got 3 matching %ss, You win %c500",output[ranspina+3], POUND);
                    *money=*money+500;
                    break;
                }
            }

            else
            {
                printf("\nSO CLOSE! Try again\n");      
            }
        }
    }
}
