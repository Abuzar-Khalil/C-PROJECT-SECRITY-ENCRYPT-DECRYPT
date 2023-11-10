// PATH: FINAL PROJECT/INTERFACE/SIGNUP.C

// TAKE INPUT DETAILS AND STORE IN STRUCT USER
#include "utilheader.h"

void signup()
{
    FILE *details;
    struct user you;
    int res, c = 0, oper, init;
    char choice[100];
    fflush(stdin);
    printf("Enter your Name : \t\t\t\t");
    input(you.name); // TAKING NAME
    printf("Enter your Email : \t\t\t\t");
    input(you.email); // TAKING EMAIL
    fflush(stdin);
    printf("Enter your Username : \t\t\t\t");
    input(you.username); // TAKING USERNAME
    printf("Enter your Mobile Number : \t\t\t");
    input(you.mob_num); // TAKING MOBILE NUMBER
    printf("Enter your Password : \n");
    printf("Password must contain 8 characters,1 Capital letter,1 Digit,1 Special Character\n"); // PASSWORD CRITERIA
    takepass(you.password); // TAKING PASSWORD

    printf("\nConfirm your Password : \t\t\t");
    takepass(you.c_pass); // TAKING PASSWORD FOR CONFIRMATION
    printf("\n");
    fflush(stdin);                          // CLEAR INPUT BUFFER
    res = strcmp(you.password, you.c_pass); // COMPARE BOTH PASSWORDS
    if (res == 0)
    {
        printf("\nYour Password Matched\n"); // IF PASSWORD MATCHES
        char string[100];
        // ABSOLUTE PATH DEFINED FOR THE FOLDER SYSTEM USER DEFINED IN UTILHEADER.H
        char filename[100] = ADRESS;
        printf("Please Enter your Username: \t\t");
        input(you.username); // TAKING USERNAME INPUT FOR FILE NAME DECLARATION
        // A FILE WILL WRITE IN SYSTEM USER WITH NAME (USERNAME).TXT
        strcat(filename, you.username);
        strcat(filename, ".txt");
        details = fopen(filename, "w");
        if (c != EOF)
        {

            fwrite(&you, 1, sizeof(struct user), details); // WRITE WHOLE STRUCT DATA IN RESPECTIVE USER
            if (fwrite != 0)
            {
                printf("You have registered successfully!\n"); // REGISTRATION CONFIRMATION MASSAGE
                fclose(details);                               // CLOSE OPENED FILE
                printf("Press any Key to Continue\n");
                init = getch();
                menu(oper);
            }
            else
            {
                printf("\nSomething went wrong, Please try again\n"); // ERROR BLOCK
                printf("Press any Key if You want to Retry\n");
                init = getch();
                signup();
            }
        }
        else
        {
            printf("\nUsername is already taken\n"); // USERNAME ALREDY TAKEN
            Beep(900, 250);
            printf("Press any Key if You want to Retry\n"); // CONTINUE
            init = getch();
            signup();
        }
    }
    else
    {
        printf("\nYour Password don't Matched\n"); // PASSWORD ERROE
        Beep(750, 300);
        printf("Press any Key if You want to Retry\n");
        init = getch();
        signup();
    }
    fflush(stdin);
    printf("Press any Key to Continue\n");
    init = getch();
    menu(oper);
}