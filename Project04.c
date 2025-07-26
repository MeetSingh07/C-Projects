// Student Grade Management System

#include<stdio.h>

typedef struct student_details{
    char name[50];
    int roll_no;
    int marks[3];
}data;

int main(){
    int n;
    printf("How many students data you want to store? ");
    scanf("%d",&n);

    data students[n];
  
    // Takes Input
     for(int i=0;i<n;i++){
        printf("Enter the name of student %i : ",i+1);
        fgets(students[i].name, sizeof(students[i].name), stdin);
        
        // Remove newline character from fgets
        students[i].name[strcspn(students[i].name,"\n")]="\0";

        printf("Enter roll number of student %i : ",i+1);
        scanf("%d",&students[i].roll_no);

        for(int j=0;j<3;j++){
             printf("Enter marks of subject %d : ",j+1);
             scanf("%d",&students[i].marks[j]);
        }
    }

    int total_marks[n];
    int average_marks[n];

    // Calculating Total Marks
    for(int i=0;i<n;i++){
        total_marks[i]=0;
        for(int j=0;j<3;j++){
            total_marks[i]+=students[i].marks[j];
        }
    }

    // Calculating Average Marks
    for(int i=0;i<n;i++){
        average_marks[i]=total_marks[i]/3;
    }

    char grade[n];
    
    // Assigning Grades Based On Average Marks
    for(int i=0;i<n;i++){
        if(average_marks[i]>=80){
            grade[i]='A';
        }
        else if(average_marks[i]>=60 && average_marks[i]<80){
            grade[i]='B';
        }
        else if(average_marks[i]>=40 && average_marks[i]<60){
            grade[i]='C';
        }
        else{
            grade[i]='F';
        }
    }

    // Dislay Report Card
    printf("|---------------------------------------------------------------------|\n");
    printf("|Roll No.|Name      |Subject 1|Subject 2|Subject 3|Total|Average|Grade|\n");
    printf("|---------------------------------------------------------------------|\n");
    for(int i=0;i<n;i++){
        printf("|%-8d|%-10s|%-9d|%-9d|%-9d|%-5d|%-7d|%-5c|\n",
            students[i].roll_no,
            students[i].name,
            students[i].marks[0],
            students[i].marks[1],
            students[i].marks[2],
            total_marks[i],
            average_marks[i],
            grade[i]);
    }
    printf("|---------------------------------------------------------------------|\n");

    return 0;
}
