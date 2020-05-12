//P1705 : CARDDECK.C – Storing playing card data
//Define a struct with following members to store information about the
//52 playing cards used for playing contract bridge.
#include <stdio.h>
#include <stdlib.h>

void showCard(int i);
int card_comp(const void * a, const void *b);
int myrandint(int nmax)
{
 return (nmax * 1.0* rand()/(1.0+RAND_MAX));
}

typedef struct
    {
        char suite;
        int suiteOrder;
        char rank[2];
        int rankOrder;
    } DECKCARD;

DECKCARD cards[52] =
{
    {'S',4," 2",1}, {'S',4," 3",2},  {'S',4," 4",3},  {'S',4," 5",4},
    {'S',4," 6",5}, {'S',4," 7",6},  {'S',4," 8",7},  {'S',4," 9",8},
    {'S',4,"10",9}, {'S',4," J",10}, {'S',4," Q",11}, {'S',4," K",12},
    {'S',4," A",13},
    {'H',3," 2",1}, {'H',3," 3",2},  {'H',3," 4",3},  {'H',3," 5",4},
    {'H',3," 6",5}, {'H',3," 7",6},  {'H',3," 8",7},  {'H',3," 9",8},
    {'H',3,"10",9}, {'H',3," J",10}, {'H',3," Q",11}, {'H',3," K",12},
    {'H',3," A",13},
    {'D',2," 2",1}, {'D',2," 3",2},  {'D',2," 4",3},  {'D',2," 5",4},
    {'D',2," 6",5}, {'D',2," 7",6},  {'D',2," 8",7},  {'D',2," 9",8},
    {'D',2,"10",9}, {'D',2," J",10}, {'D',2," Q",11}, {'D',2," K",12},
    {'D',2," A",13},
    {'C',1," 2",1}, {'C',1," 3",2},  {'C',1," 4",3},  {'C',1," 5",4},
    {'C',1," 6",5}, {'C',1," 7",6},  {'C',1," 8",7},  {'C',1," 9",8},
    {'C',1,"10",9}, {'C',1," J",10}, {'C',1," Q",11}, {'C',1," K",12},
    {'C',1," A",13}

};


void showCard(int i)
{
    printf("[%c %2s]",cards[i].suite,cards[i].rank);
    return;
}

int main()
{
    unsigned int i,k,tmp,seed;
    int north[13],east[13],south[13],west[13];
    int mydeck[52];
//initialize the deck
    for(i=0;i<52;i++)
        {
            mydeck[i]=i;
            showCard(i);
        }
    printf("\n\nEnter a seed integer for random numbers >>");
    scanf("%d",&seed);
    srand(seed);
// random shuffling of deck
// using the correct version of the Knuth Fisher Yates Shuffle
    for (i=0;i<52;i++)
    {
        k         = i+myrandint(52-i);
        printf("swap %d %d \n",i,k);
        tmp       = mydeck[i];
        mydeck[i] = mydeck[k];
        mydeck[k] = tmp;
    }
    printf("Shuffled deck is as follows:\n");
    for (i=0;i<52;i++)
        printf("%2d ",mydeck[i]);
    printf("\n");
// deal the cards - starting with north
    for(i=0;i<13;i++)
    {
        north[i] = mydeck[4*i+0];
         east[i] = mydeck[4*i+1];
        south[i] = mydeck[4*i+2];
         west[i] = mydeck[4*i+3];
    }
// sort each hand and display
//north
    qsort((void *)north,13,sizeof(int),card_comp);
    printf("north\n");
    printf("S : ");
    for (i=0;i<13;i++)
        if(cards[north[i]].suite=='S') printf(" %2s",cards[north[i]].rank);
    printf("\n");
    printf("H : ");
    for (i=0;i<13;i++)
        if(cards[north[i]].suite=='H') printf(" %2s",cards[north[i]].rank);
    printf("\n");
    printf("D : ");
    for (i=0;i<13;i++)
        if(cards[north[i]].suite=='D') printf(" %2s",cards[north[i]].rank);
    printf("\n");
    printf("C : ");
    for (i=0;i<13;i++)
        if(cards[north[i]].suite=='C') printf(" %2s",cards[north[i]].rank);
    printf("\n");
//east
    qsort((void *)east,13,sizeof(int),card_comp);
    printf("east\n");
    printf("S : ");
    for (i=0;i<13;i++)
        if(cards[east[i]].suite=='S') printf(" %2s",cards[east[i]].rank);
    printf("\n");
    printf("H : ");
    for (i=0;i<13;i++)
        if(cards[east[i]].suite=='H') printf(" %2s",cards[east[i]].rank);
    printf("\n");
    printf("D : ");
    for (i=0;i<13;i++)
        if(cards[east[i]].suite=='D') printf(" %2s",cards[east[i]].rank);
    printf("\n");
    printf("C : ");
    for (i=0;i<13;i++)
        if(cards[east[i]].suite=='C') printf(" %2s",cards[east[i]].rank);
    printf("\n");

//south
    qsort((void *)south,13,sizeof(int),card_comp);
    printf("south\n");
    printf("S : ");
    for (i=0;i<13;i++)
        if(cards[south[i]].suite=='S') printf(" %2s",cards[south[i]].rank);
    printf("\n");
    printf("H : ");
    for (i=0;i<13;i++)
        if(cards[south[i]].suite=='H') printf(" %2s",cards[south[i]].rank);
    printf("\n");
    printf("D : ");
    for (i=0;i<13;i++)
        if(cards[south[i]].suite=='D') printf(" %2s",cards[south[i]].rank);
    printf("\n");
    printf("C : ");
    for (i=0;i<13;i++)
        if(cards[south[i]].suite=='C') printf(" %2s",cards[south[i]].rank);
    printf("\n");

//west
    qsort((void *)west,13,sizeof(int),card_comp);
    printf("west\n");
    printf("S : ");
    for (i=0;i<13;i++)
        if(cards[west[i]].suite=='S') printf(" %2s",cards[west[i]].rank);
    printf("\n");
    printf("H : ");
    for (i=0;i<13;i++)
        if(cards[west[i]].suite=='H') printf(" %2s",cards[west[i]].rank);
    printf("\n");
    printf("D : ");
    for (i=0;i<13;i++)
        if(cards[west[i]].suite=='D') printf(" %2s",cards[west[i]].rank);
    printf("\n");
    printf("C : ");
    for (i=0;i<13;i++)
        if(cards[west[i]].suite=='C') printf(" %2s",cards[west[i]].rank);
    printf("\n");

    return 0;
}

int card_comp(const void * a, const void *b)
{
    return ( *(int*)a - *(int*)b );
}
