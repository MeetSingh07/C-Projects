// Project 3
// Making a simple calculator using C

#include <stdio.h>
#include<math.h>

void add(float n1 , float n2);
void subtract(float n1 , float n2);
void product(float n1 , float n2);
void division(float n1 , float n2);
void modulus(float n1 , float n2);
void power(float n1 , float n2);

int main(){
    int choice;
    int running = 1;
    float num1, num2;

    while (running)
    {
        printf("\n--------------------------------------------------\n");
        printf("WELCOME TO CALCULATOR\n");
        printf("MENU:\n1.Add\n2.Subtract\n3.Product\n4.Divide\n5.Modulus\n6.Power\n7.Exit\n");
        printf("Choose: ");
        scanf("%d",&choice);

        if(choice>7 || choice<1){
            printf("Please enter a valid choice.");
        }
        else{
            switch (choice)
            {
            case 1:
                printf("You chose Addition.\n");
                printf("Enter first number: ");
                scanf("%f",&num1);
                printf("Enter second number: ");
                scanf("%f",&num2);
                add(num1,num2);
                break;

            case 2:
                printf("You chose Subtraction.\n");
                printf("Enter first number: ");
                scanf("%f",&num1);
                printf("Enter second number: ");
                scanf("%f",&num2);
                subtract(num1,num2);
                break;
            
            case 3:
                printf("You chose Product.\n");
                printf("Enter first number: ");
                scanf("%f",&num1);
                printf("Enter second number: ");
                scanf("%f",&num2);
                product(num1,num2);
                break;

            case 4:
                printf("You chose Division.\n");
                printf("Enter the number you want to divide: ");
                scanf("%f",&num1);
                printf("Enter the number with which you want to divide: ");
                scanf("%f",&num2);
                division(num1,num2);
                break;

            case 5:
                printf("You chose Modulus.\n");
                printf("Enter the number whose modulus you want to find: ");
                scanf("%f",&num1);
                printf("Enter the number with which you want to find the modulus: ");
                scanf("%f",&num2);
                modulus(num1,num2);
                break;

            case 6:
                printf("You chose Power.\n");
                printf("Enter the number to find its power: ");
                scanf("%f",&num1);
                printf("Enter the power: ");
                scanf("%f",&num2);
                power(num1,num2);
                break;

            case 7:
                printf("Exiting the program...");
                running=0;
                break;

            default:
                break;
            }
        }
    }
}

void add(float n1 , float n2){
    printf("Addition of %.2f and %.2f is %.2f",n1,n2,n1+n2);
}

void subtract(float n1 , float n2){
    printf("Subtraction of %.2f and %.2f is %.2f",n1,n2,n1-n2);
}

void product(float n1 , float n2){
    printf("Product of %.0f and %.0f is %.2f",n1,n2,n1*n2);
}

void division(float n1 , float n2){
    if(n2==0){
        printf("The denominator cannot be zero.");
    }
    else{
        printf("The Division of %.2f with %.2f is %.2f",n1,n2,n1/n2);
    }
}

void modulus(float n1 , float n2){
    if(n2==0){
        printf("The denominator cannot be zero.");
    }
    else{
        printf("The modulus of %.2f divided by %.2f is %.2f",n1,n2,fmod(n1,n2));
    }
}

void power(float n1 , float n2){
    printf("%.0f power by %.0f is %.2f",n1,n2,pow(n1,n2));
}