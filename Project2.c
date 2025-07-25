// Write a C program capable of playing rock , paper and scissors with you.
// Your program should be able to print the result after you choose.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));
    
    int choice ,computer , computer_score = 0, your_score = 0 , running=1;
    
    FILE *ptr = fopen("score.txt", "w");
    
    while (running)
    {
        computer = 1 + rand() % 4;
        printf("Welcome to Rock , Paper and Scissors.\n");
        printf("Choose:\n1 for Rock\n2 for Paper\n3 for Scissors\n4 for exit\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice > 4 || choice < 1)
        {
            printf("Please enter a valid choice.\n");
        }
        else
        {
            switch (choice)
            {
            case 1:
                printf("You chose Rock!!!\n");
                if (computer == 1)
                {
                    printf("Computer chose Rock!!!\n");
                    printf("Draw\n");
                }
                else if (computer == 2)
                {
                    printf("Computer chose Paper!!!\n");
                    printf("You Loss\n");
                    computer_score++;
                }
                else
                {
                    printf("Computer chose Scissor!!!\n");
                    printf("You Won\n");
                    your_score++;
                }
                break;

            case 2:
                printf("You chose Paper!!!\n");
                if (computer == 1)
                {
                    printf("Computer chose Rock!!!\n");
                    printf("You Won\n");
                    your_score++;
                }
                else if (computer == 2)
                {
                    printf("Computer chose Paper!!!\n");
                    printf("Draw\n");
                }
                else
                {
                    printf("Computer chose Scissor!!!\n");
                    printf("You Loss\n");
                    computer_score++;
                }
                break;

            case 3:
                printf("You chose Scissor!!!\n");
                if (computer == 1)
                {
                    printf("Computer chose Rock!!!\n");
                    printf("You Loss\n");
                    computer_score++;
                }
                else if (computer == 2)
                {
                    printf("Computer chose Paper!!!\n");
                    printf("You Won\n");
                    your_score++;
                }
                else
                {
                    printf("Computer chose Scissor!!!\n");
                    printf("Draw\n");
                }
                break;
            case 4:
                printf("\nGame Over\n");
                running=0;
                break;

            default:
                break;
            }
        }
    }

    fprintf(ptr, "Computer: %d\n", computer_score);
    fprintf(ptr, "You: %d\n", your_score);

    fclose(ptr);

    return 0;
}