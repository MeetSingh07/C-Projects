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
    char final_password[20];
    char account_number[11];
    long long int account_balance;
}pm;

typedef struct deposit{
    char user_account_number[11];
    char user_account_password[20];
}dp;

typedef struct withdraw{
    char user_account_number_withdraw[11];
    char user_account_password_withdraw[20];
}wd;

typedef struct check_balance{
    char user_account_number_balance[11];
    char user_account_password_balance[20];
}cb;

int main(){
    int choice;
    int loop=1;
    int i=0;
    int unique=0;   // 0 means not unique // 1 means unique
    pm account_holder[100];
    dp deposit_money[100];
    wd withdraw_money[100];
    cb check_balance[100];
    int d=0;
    int w=0;
    int b=0;
    int correct=0; // 0 means not correct // 1 means correct
    int account_index=-1;
    srand(time(0));

    printf("<----WELCOME TO PM BANK SERVICES---->\n");

    while(loop){
        printf("\nChoose your service:");
        printf("\n0. Exit\n1. Create Account\n2. Deposit Money\n3. Withdraw Money\n4. Check Current Balance\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        getchar();
        printf("\n");

        switch (choice)
        {
        case 0:
            loop=0;
            printf("<---- THANK YOU FOR VISITING , PM BANK SERVICES EXITED ---->");
            break;

        case 1:
            printf("\n<---- LETS'S CREATE YOUR BANK ACCOUNT STEP BY STEP ---->\n");

            printf("\nEnter your name: ");
            fgets(account_holder[i].name,100,stdin);
            account_holder[i].name[strcspn(account_holder[i].name,"\n")]='\0';
            
            while(1){
                printf("\nEnter your phone number: ");
                fgets(account_holder[i].phone,11,stdin);
                account_holder[i].phone[strcspn(account_holder[i].phone,"\n")]='\0';
                if(strlen(account_holder[i].phone)!=10){
                    printf("\nEnter a valid phone number ( 10 digits only )\n");
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
                    strcpy(account_holder[i].final_password,account_holder[i].temp_password);
                    printf("\nPassword Accepted\n");
                    break;
                }
            }

            unique=0;
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

            account_holder[i].account_balance = 0;
            printf("\n<---- CONGRATULATIONS YOUR ACCOUNT IS SUCCESSFULLY CREATED , HERE IS YOUR ACCOUNT NUMBER - %s ---->\n",account_holder[i].account_number);

            i++;
            break;

        case 2:
            printf("\n<---- LET'S DEPOSIT YOUR MONEY STEP BY STEP ---->\n");

            account_index=-1;
            while(account_index==-1){
                printf("\nEnter your account number: ");
                fgets(deposit_money[d].user_account_number,11,stdin);
                getchar();
                // deposit_money[d].user_account_number[strcspn(deposit_money[d].user_account_number,"\n")]='\0';

                for(int p=0;p<i;p++){
                    if(strcmp(deposit_money[d].user_account_number,account_holder[p].account_number)==0){
                        account_index=p;
                        printf("\nUser Found\n");
                        break;
                    }
                }
                if(account_index==-1){
                    printf("\nUser Not Found. Try Again\n");
                }
            }
            
            correct=0;
            while(!correct){
                printf("\nPlease enter your password: ");
                fgets(deposit_money[d].user_account_password,20,stdin);
                // getchar();
                deposit_money[d].user_account_password[strcspn(deposit_money[d].user_account_password,"\n")]='\0';

                correct=1;

                if(strcmp(deposit_money[d].user_account_password,account_holder[account_index].final_password)==0){
                    printf("\nPassword Matched\n");
                }else{
                    printf("\nWrong Password Access Denied\n");
                    correct=0;
                }
            }

            long long int deposit_amount;
            int value=0;
            while(!value){
                printf("\nEnter the amount you want to deposit: ");
                scanf("%lld",&deposit_amount);
                value=1;

                if(deposit_amount<=0){
                    printf("\nEnter Valid Amount\n");
                    value=0;
                }
                else{
                    break;
                }
            }
            getchar();
            account_holder[account_index].account_balance+=deposit_amount;
            printf("\nRs.%lld Deposited Successfully to %s's Account\n",deposit_amount,account_holder[account_index].name);
            d++;
            break;

        case 3:
            printf("\n<---- LET'S WITHDRAW YOUR MONEY STEP BY STEP ---->\n");

            account_index=-1;
            while(account_index==-1){
                printf("\nEnter your account number: ");
                fgets(withdraw_money[w].user_account_number_withdraw,11,stdin);
                getchar();

                for(int p=0;p<i;p++){
                    if(strcmp(withdraw_money[w].user_account_number_withdraw,account_holder[p].account_number)==0){
                        account_index=p;
                        printf("\nUser Found\n");
                        break;
                    }
                }
                if(account_index==-1){
                    printf("\nUser Not Found\n");
                }
            }

            correct=0;
            while(!correct){
                printf("\nEnter your password: ");
                fgets(withdraw_money[w].user_account_password_withdraw,20,stdin);
                withdraw_money[w].user_account_password_withdraw[strcspn(withdraw_money[w].user_account_password_withdraw,"\n")]='\0';

                correct=1;

                if(strcmp(withdraw_money[w].user_account_password_withdraw,account_holder[account_index].final_password)==0){
                    printf("\nPassword Matched\n");
                }else{
                    printf("\nWrong Password Access Denied\n");
                    correct=0;
                }
            }

            long long int withdraw_amount;
            int value1=0;
            while(!value1){
                printf("\nEnter the amount you want to withdraw: ");
                scanf("%lld",&withdraw_amount);
                value1=1;
                if(withdraw_amount<=0){
                    printf("\nEnter Valid Amount\n");
                    value1=0;
                }else{
                    break;
                }
            }

            getchar();
            account_holder[account_index].account_balance-=withdraw_amount;
            printf("\nRs.%lld Successfully Withdrawed from %s's Account\n",withdraw_amount,account_holder[account_index].name);
            w++;
            break;

        case 4:
            printf("\n<---- LET'S CHECK YOUR CURRENT BALANCE STEP BY STEP ---->\n");

            account_index=-1;
            while(account_index==-1){
                printf("\nEnter your account number: ");
                fgets(check_balance[b].user_account_number_balance,11,stdin);
                getchar();
                
                for(int p=0;p<i;p++){
                    if(strcmp(check_balance[b].user_account_number_balance,account_holder[p].account_number)==0){
                        account_index=p;
                        printf("\nUser Found\n");
                        break;
                    }
                }
                if(account_index==-1){
                    printf("\nUser Not Found. Try Again\n");
                }
            }
            
            correct=0;
            while(!correct){
                printf("\nPlease enter your password: ");
                fgets(check_balance[b].user_account_password_balance,20,stdin);
                
                check_balance[b].user_account_password_balance[strcspn(check_balance[b].user_account_password_balance,"\n")]='\0';

                correct=1;

                if(strcmp(check_balance[b].user_account_password_balance,account_holder[account_index].final_password)==0){
                    printf("\nPassword Matched\n");
                }else{
                    printf("\nWrong Password Access Denied\n");
                    correct=0;
                }
            }

            printf("\nAccount Number - %s\n",account_holder[account_index].account_number);
            printf("Account Holder - %s\n",account_holder[account_index].name);
            printf("Phone Number - %s\n",account_holder[account_index].phone);
            printf("Email - %s\n",account_holder[account_index].email);
            printf("Account Balance - %lld\n",account_holder[account_index].account_balance);
            b++;
            break;

        default:
            printf("\nEnter a valid choice\n");
            break;
        }
    }

    return 0;
}