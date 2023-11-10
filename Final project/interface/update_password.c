// PATH: FINAL PROJECT/EC_DC_INTERFACE/UPDATE_PASSWORD.C

#include "utilheader.h"
void change_password(char username[100])
{
    struct user you;           // STRUCT
    FILE *details = NULL;
    char choice[100];
    int oper, init;
    char current_password[100];    // VARIBLE DECLARATION
    char password[100];
    char filename[100] = ADRESS;
    fflush(stdin);
    printf("Please Enter Your Username\t\t");
    input(username);
    printf("\nEnter the Current Password:\n"); // TAKE PASSWORD
        printf("(must includes 8 charachters , 1 Capital letter & 1 special letter:)\n");
    takepass(current_password); 
    strcat(filename, username);       // USSE OF STRCAT TO MERGE STRINGS
    strcat(filename, ".txt");
    details = fopen(filename, "r");  // FILE WILL BE OPEN
    fread(&you, sizeof(struct user), 1, details); // FREAD TO READ DETAILS FROM FILE

    if (details == NULL)
    {
        printf("\nWrong Input, Please Try Again\n");  // ERROR MASSAGE
        Beep(750,300);
    }
    if (strcmp(you.password, current_password) == 0)
    {
        fflush(stdin);
        printf("\nEnter the New Password\n");
        printf("(must includes 8 charachters , 1 Capital letter & 1 special letter:)\n");
        takepass(password);  // TAKEPASS FUNCTION CALL
        strcpy(you.password, password);    // COPY NEW PASSWORD IN STRUCT
        strcpy(you.c_pass, password);      // OPEN FILE 
        details = freopen(filename, "w", details);     // DETAILS OF OLD FILE WIPED OUT
        fwrite(&you, sizeof(struct user), 1, details); // WRITING STRUCT WITH NEW CREDENTIALS
        if (fwrite != 0)
        {
            printf("\nSuccessful Updatation\n");  // PASSSWORD CHANGE MASSAGE
            fclose(details);
        }
        else
        {
            printf("\nTry Again\n"); // ERROR MASSAGE
            fclose(details);
            printf("Press any Key if You want to Retry\n");  // CONTINUE MASSAGE
            init = getch();
            change_password(username); // RECURSION
        }
    }
    else
    {
        printf("\nPassword Don't Match!\n");  // ERROR
    }
    fclose(details);
    printf("Press any Key to Continue\n");
    init = getch();
    system("cls");
    sec_menu(oper);
}