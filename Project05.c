// Banking system

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

typedef struct PM_banking_system{
    char name[100];
    char phone[11];
    char email[100];
    char temp_password[15];
    char password[20];
    char account_number[11];
}pm;

int main(){
    int choice;
    int loop=1;
    int i=0;
    int unique=0;
    pm account_holder[100];
    srand(time(0));

    printf("<----WELCOME TO PM BANK SERVICES---->");

    while(loop){
        printf("Choose your service:");
        printf("\n0. Exit\n1. Create Account\n2. Deposit Money\n3. Withdraw Money\n4. Check Current Balance\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        getchar();
        printf("\n");

        switch (choice)
        {
        case 0:
            loop=0;
            printf("<----THANK YOU FOR VISITING , PM BANK SERVICES EXITED---->");
            break;

        case 1:
            printf("<----LETS'S CREATE YOUR BANK ACCOUNT STEP BY STEP---->\n");

            printf("Enter your name: ");
            fgets(account_holder[i].name,100,stdin);
            account_holder[i].name[strcspn(account_holder[i].name,"\n")]='\0';
            
            while(1){
                printf("\nEnter your phone number: ");
                fgets(account_holder[i].phone,11,stdin);
                account_holder[i].phone[strcspn(account_holder[i].phone,"\n")]='\0';
                if(strlen(account_holder[i].phone)!=10){
                    printf("Enter a valid phone number ( 10 digits only )\n");
                }
                else{
                    break;
                }
            }

            getchar();

            printf("\nEnter your email id: ");
            fgets(account_holder[i].email,100,stdin);
            account_holder[i].email[strcspn(account_holder[i].email,"\n")]='\0';
            
            while(1){
                printf("\nMake a strong password of 8 characters: ");
                fgets(account_holder[i].temp_password,15,stdin);
                account_holder[i].temp_password[strcspn(account_holder[i].temp_password,"\n")]='\0';
                if(strlen(account_holder[i].temp_password)!=8){
                    printf("\nPlease use exactly 8 characters\n");
                }
                else{
                    strcpy(account_holder[i].password,account_holder[i].temp_password);
                    printf("\nPassword Accepted\n");
                    break;
                }
            }
            int unique=0;
            while(!unique){
                for(int j=0;j<10;j++){
                    account_holder[i].account_number[j] = '0' + rand() % 10;
                }
                account_holder[i].account_number[10]='\0';

                unique=1;

                for(int k=0;k<i;k++){
                    if(strcmp(account_holder[k].account_number,account_holder[i].account_number)==0){
                        unique=0;
                        break;
                    }
                }
            }
            printf("<----CONGRATULATIONS YOUR ACCOUNT IS SUCCESSFULLY CREATED , HERE IS YOUR ACCOUNT NUMBER - %s---->\n",account_holder[i].account_number);

            i++;
            break;
        case 2:
            printf("<----LET'S DEPOSIT YOUR MONEY STEP BY STEP---->");
            break;

        case 3:
            printf("<----LET'S WITHDRAW YOUR MONEY STEP BY STEP---->");
            break;

        case 4:
            printf("<----LET'S CHECK YOUR CURRENT BALANCE STEP BY STEP---->");
            break;

        default:
            break;
        }
    }

    return 0;
}