// PATH: FINAL PROJECT/EC_DC_INTERFACE/UPDATE_USERNAME.C

#include "utilheader.h"

void change_username()
{
    struct user you;
    FILE *details;
    FILE *details2;
    char choice[100];
    int oper, init;
    char new_username[100];
    char current_filename[100] = ADRESS;
    // ABSOLUTE PATH DEFINED FOR THE FOLDER SYSTEM USER DEFINED IN UTILHEADER.H
    char filename[100] = ADRESS;
    printf("\nPlease Enter Your Current Username: ");
    input(you.username); // TAKING USERNAME INPUT FOR FILE NAME DECLARATION
    // A FILE WILL WRITE IN SYSTEM USER WITH NAME (USERNAME).TXT
    strcat(current_filename, you.username);
    strcat(current_filename, ".txt");
    details = fopen(current_filename, "r"); // OPEN CURRENT FILE
    if (details == NULL)
    {
        printf("Invalid input!\n"); // ERROR MASSAGE
        printf("Press any Key if You want to Retry\n");
        init = getch();
        change_username();
    }
    else
    {
        fread(&you, sizeof(struct user), 1, details);
        details = freopen(current_filename, "w", details); // REOPENUNG OLD FILE IN WRITE MODE WILL CLEAR OLD CONTENTS
        printf("\nPlease Enter Your New Username: ");
        input(new_username); // TAKING USERNAME INPUT FOR FILE NAME DECLARATION
        // A FILE WILL WRITE IN SYSTEM USER WITH NAME (USERNAME).TXT
        strcat(current_filename, new_username);
        strcat(current_filename, ".txt");
        strcpy(you.username, new_username); // NEW USERNAM WILL BE WRITTEN IN STRUCT

        int c = fgetc(details); // CURRENT FILE DETAILS WILL BE WIPED OUT
        if (c == EOF)           // NEW DETAILS WILL BE WRITTEN
        {

            printf("\nSuccessful Updatation\n"); // NEW USERNAME CREATED
            printf("Your New Username : %s\n", new_username);
        }
        fclose(details);
        strcat(filename, new_username);
        strcat(filename, ".txt");        // NEW FILE CREATION
        details2 = fopen(filename, "w"); // OPEN FILE IN WRITE MODE
        c = fgetc(details2);
        if (c == EOF) // IN CASE FILE IS EMPTY MEANS USERNAME HASN'T ALREADY TAKEN
        {
            fwrite(&you, sizeof(struct user), 1, details2);
        }
        else
        {
            printf("\nUsername Can't be Duplicated, Its alredy taken by another User\n");
            printf("Enter any Key if You want to Retry\n"); // USERNAME ALREADY TAKEN
            init = getch();
            change_username(); // FUNCTION WILL CALL IT SELF IF USERNAME HAS ALREADY TAKEN
        }
    }
    fclose(details2);
    printf("\n");
    system("cls");
    sec_menu(oper); // IT WILL CALL SEC MENU FUNCTION
}
