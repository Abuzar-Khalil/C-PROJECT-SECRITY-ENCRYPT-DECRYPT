// PATH: FINAL PROJECT/EC_DC_INTERFACE/EC_DC_INTERFACE.C

/*THIS IS CALLED BY SEC_MENU CHOICE FUNCTIONS*/
#include "ec_dc_header.h"

int ec_dc_interface(int oper)
{
    struct user you;    // STRUCT DEFINED IN UTILHEADER
    FILE *fptr;         // FILE POINTER
    system("color 0b"); // TERMINAL FONT COLOR CHANGE
    char username[100];
    fflush(stdin); // BUFFER OF PREVIOUS INPUTS IS CLEANED
    switch (oper)  // SWITCH STATEMENT
    {
    case 1:
        encrypt(); // CALL THE FUNCTION OF ENCRYPTION OF NEW FILE
        break;
    case 2:
        list_files(); // LIST ALL THE EXISTING FILES IN ENCRYPTION FILES FOLDER
        break;
    case 3:
        decrypt(); // DECRYPT THE ENCRYTPED FILE
        break;
    case 4:
        change_username(); // IF USER WANNA CHANGE HIS USERNAME
        break;
    case 5:
        change_password(username); // IF USER WANNA CHANGE HIS PASSWORD
        break;
    case -1:
        printf("Exitting the Program\n"); // IF USER EXIT THE PROGRAM
        Sleep(800);
        system("cls");
        break;
    default:
        printf("Incorrect choice\n"); // USER CHOOSE OTHER THAN SWITCH CASES
        break;
    }
}