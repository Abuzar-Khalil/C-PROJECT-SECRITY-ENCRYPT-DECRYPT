// PATH: FINAL PROJECT/INTERFACE/LOGIN.C

#include "utilheader.h"

void login()
{
    struct user you;
    FILE *fptr;                        // FILE POINTER
    char username[100], password[100]; // VARIABLE NAME DECLARATION
    int res, result, oper, init;
    char choice[100];
    fflush(stdin); // CLEAR PREVIOUS INPUT BUFFER
    printf("Enter your User Name:\n");
    input(username); // TAKING USERNAME INPUT
    printf("Enter your Password:\n");
    takepass(password); // TAKING PASSWORD USING TAKEPASS FUNCTION

    FILE *data; // FILE POINTER
    char string[100];
    char filename[100] = ADRESS; // ABSOLUTE PATH DEFINED FOR THE FOLDER SYSTEM USER DEFINED IN UTILHEADER.H

    // A FILE WILL BE READ FROM SYSTEM USER WITH NAME (USERNAME).TXT
    strcat(filename, username); // MERGE USERNAME IN FILENAME
    strcat(filename, ".txt");
    data = fopen(filename, "r");
    fread(&you, sizeof(struct user), 1, data); // READ THE FILE DATA
    res = strcmp(you.username, username);      // COMPARE USERNAME WITH STRUCT DATA
    if (res == 0)
    {
        result = strcmp(you.password, password); // COMPARE PASSWORD
        if (result == 0)
        {
            // IF PASSWORD MATCH WELCOME MASSAGE
            system("cls");
            printf("\n\t\t\t\t\t\tWelcome Dear : %s\n", you.name);
            printf("|Name : %s\n|Email : %s\n|Username : %s\n|Mobile Number : %s\n", you.name, you.email, you.username, you.mob_num);
            printf("Press any Key to Continue\n");
            init = getch();
            system("cls");
            sec_menu(oper); // CONTINUE TO EC DC INTERFACE
        }
        else
        {
            printf("\nIncorrect Password\n");
            Beep(750, 300); // IN CASE OF ERROR CREAT BEEP SOUND
            printf("Press any Key if You want to Retry\n");
            init = getch();
            login();
        }
    }
    else
    {
        printf("\nUser hasn't registered\n");
        Beep(900, 250);
        printf("Press any Key if You want to Retry\n");
        init = getch();
        login();
    }
    fclose(fptr); // CLOSE THE OPENED FILE
    printf("Press any Key to Continue\n");
    init = getch();
    system("cls");
    menu(oper);
}