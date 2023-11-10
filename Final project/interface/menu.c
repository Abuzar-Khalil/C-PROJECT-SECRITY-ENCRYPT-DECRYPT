// PATH: FINAL PROJECT/INTERFACE/MENU.C

// WHEN PROGRAM START THIS SCREEN WILL APPEAR
#include "utilheader.h"
// THIS FUNCTION IS BEING CALLED BY MAIN
void menu(int choice) // FUNCTION DECLARATION
{
    system("color 0b"); // TERMINAL FONT COLOR CHANGE 
    // FUNCTION BODY
    system("cls");
    printf("|---------------------------------------------------------------|\n");
    printf("|\t\t\t\t\t\t\t\t|\n");
    printf("|\t\t\t\t\t\t\t\t|\n");
    printf("|           Welcome to Verification System                      |\n");
    printf("|\t\tPress 1 to Signup        \t\t\t|\n");
    printf("|\t\tPress 2 to Login         \t\t\t|\n");
    printf("|\t\tPress -1 to exit         \t\t\t|\n");
    printf("|\t\t\t\t\t\t\t\t|\n");
    printf("|\t\t\t\t\t\t\t\t|\n");
    printf("|---------------------------------------------------------------|\n");
    printf("\n\n");
    fflush(stdin); // CLEAR INPUT BUFFER
    printf("Enter your choice\n");
    scanf("%d", &choice);
    struct user you; // CREATING A STRUCT
    FILE *fptr;      // FILE POINTER
    system("cls");
    switch (choice) // APPLYING SWITCH STATEMENT
    {
    case 1:
        signup(); // TAKING USER CREDENTIALS AND CREATING A CREDENTIALS FILE
        break;
    case 2:
        login(); // LOGIN OPTION FOR A EXISTING USER
        break;
    case -1:
        printf("Exitting the Program\n"); // WHEN USER WANT TO EXIT THIS WILL PRINT
        Sleep(800);
        system("cls");
        break;
    default:
        printf("Incorrect choice\n"); // IN CASE OF INPUT OTHER THAN SWITCH CASES
        break;
    }
}