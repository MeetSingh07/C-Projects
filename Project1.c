// Number Guessing game

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    srand(time(0));

    int randomnumber = 1 + rand()%100;

    int guess=-1,count=0;

    printf("COMPUTER GUESSED THE NUMBER.\n");

    while(guess!=randomnumber){
        printf("GUESS THE NUMBER BETWEEN 1 - 100 : \n");
        scanf("%d",&guess);
        count++;

        if(guess<1 || guess>100){
            printf("ENTER A VALID NUMBER.\n");
        }
        else if(guess>randomnumber){
            printf("GUESS LOWER NUMBER.\n");
        }
        else if(guess<randomnumber){
            printf("GUESS HIGHER NUMBER.\n");
        }
        else{
            printf("CONGRATULATIONS!!! YOU GUESSED THE NUMBER.\n");
        }
    }

    printf("Number of guesses : %d",count);

    return 0;
}