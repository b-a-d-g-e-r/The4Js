#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include<string.h>
#include<ctype.h>

void roulette();
void blackjack();
void slotmachine();

//global variables
int JamesChoicez, JamesMoneyz=50, JamezBet=0;

int main()
{
    int a=0;
    while(a==0)
    {
        if(JamesMoneyz==0)
        {
            printf("\nAll out of money, Sorry :(\n");
            a=1;
        }
        else
        {
    printf("Welcome to the underage gambling simulator.\nDo you want to play:\n1: Blackjack\n2: Roulette\n3: Slot Machine\n4: Exit\n");
    scanf("%d",&JamesChoicez);
    switch(JamesChoicez)
    {
        case 1:
        blackjack();
        break;
        case 2: 
        roulette();
        break;
        case 3:
        slotmachine();
        break;
        case 4: 
        a=1;
        break;
    }
    }
    }
}

void blackjack()
{
    int pscore=0,dscore=0,i=0,card,j=0,rannum2,dturn;
    int Brepeat=0;
    char symbol[4][10] = {"Hearts\0","Diamonds\0","Clubs\0","Clover\0"};
    char draw[10];
    char checker[2][10] = {"draw\0","stand\0"};
      printf("\nWelcome to Blackjack.");
    while(Brepeat==0)
    {
        if(JamesMoneyz<=0)
        {
            Brepeat=1;
            dturn=1;
        }
        else
        {
    printf("\nYou have £%d\nEnter how much you want to bet or enter '0' to return to the game select ",JamesMoneyz);
    scanf("%d",&JamezBet);
    while(JamezBet>JamesMoneyz)
    {
        printf("You only ave £%d, Enter a valid bet: ",JamesMoneyz);
        scanf("%d",&JamezBet);

    }
    if(JamezBet==0)
    {
        Brepeat=1;
        dturn=1;
    }
    else
    {
    JamesMoneyz=JamesMoneyz-JamezBet;
    // your turn
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
        JamezBet=JamezBet*2;
        printf("\nBlackjack! You scored exactly 21 and received £%d",JamezBet);
        JamesMoneyz=JamesMoneyz+JamezBet;
        j=1;
        dturn=1;
    }
    else if(pscore>21)
    {
        printf("\nYou went bust, unlucky.");
        j=1;
        dturn=1;
    }
    else{
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
        JamezBet=JamezBet*2;
        printf("**Dealer went bust, You win and receive £%d**",JamezBet);
        JamesMoneyz=JamesMoneyz+JamezBet;
    }
    }
    }
        }
    }
}

void roulette()
{
    int Rrepeat=0;
    printf("\nWelcome to roulette\n");
    char colour[2][10]={"black\0","red\0"};
    char colourg[10];
    int numg,check;
    while(Rrepeat==0)
    {
        if(JamesMoneyz==0)
        {
        Rrepeat=1;
        }
        else
        {
        printf("You have £%d\nHow much would you like to bet? ",JamesMoneyz);
        scanf("%d",&JamezBet);
        while(JamezBet>JamesMoneyz)
        {
            printf("Not enough money, You only have £%d. Enter a bet: ",JamesMoneyz);
            scanf("%d",&JamezBet);
        }
        JamesMoneyz=JamesMoneyz-JamezBet;

        srand(time(NULL));
        int rannum=rand() % 50;
        int rancol=rand() % 2;

        printf("\nWould you like to guess the:\n1: Colour(x2 payout)\n2: Number(x5 payout)\n3: Number and Colour(x20 payout)\n4: Switch Game\n ");
        scanf("%d",&JamesChoicez);

        switch(JamesChoicez)
        {
            case 1: 
            printf("\nEnter the colour you think it will be (red or black)\n");
            scanf("%s",&colourg);
            check=strcmp(colourg,colour[rancol]);
            if(check==0)
            {
                JamezBet=JamezBet*2;
                printf("\nCorrect, the wheel landed on %s %d You receive £%d\n",colour[rancol],rannum,JamezBet);
                JamesMoneyz=JamesMoneyz+JamezBet;
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
                JamezBet=JamezBet*5;
                 printf("\nCorrect, the wheel landed on %s %d You receive £%d\n",colour[rancol],rannum,JamezBet);
                 JamesMoneyz=JamesMoneyz+JamezBet;
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
                JamezBet=JamezBet*20;
                printf("\nJackpot! the wheel landed on %s %d and you guessed it right! you receive £%d",colour[rancol],rannum,JamezBet);
                JamesMoneyz=JamesMoneyz+JamezBet;
            }
            else
            {
                printf("\nUnlucky, the wheel landed on %s %d, Better luck next time.",colour[rancol],rannum);
            }
            break;
            case 4:
            JamesMoneyz=JamesMoneyz+JamezBet;
            Rrepeat=1;
            break;
        }

        }

    }
}

void slotmachine()
{
    int l,k=0,ranspina,ranspinb,ranspinc;
    char choice[4];
   
    char output[10][15] = {"Rolling\0","Rolling\0","Rolling\0,","Cherry\0","Banana\0","Orange\0","Lime\0","lemon\0","Strawberry\0","Jackpot\0"};
    printf("\nWelcome to the slot machine. Match 3 fruits to win a prize.");
    while(k==0)
    {
    printf("\nYou have £%d\nWould you like to: \nplay (£1)\nExit to menu\n",JamesMoneyz);
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
        
        JamesMoneyz=JamesMoneyz-1;
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
        if(strcmp(output[ranspina],output[ranspinb])==0 && strcmp(output[ranspinb],output[ranspinc])==0)
            {
                switch(ranspina)
                {
                    case 6: 
                    JamesMoneyz=JamesMoneyz+10000;
                    printf("**Jackpot!** You won £10,000");
                    break;
                    default:
                    printf("Well done! You got 3 matching %ss, You win £500",output[ranspina+3]);
                    JamesMoneyz=JamesMoneyz+500;
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