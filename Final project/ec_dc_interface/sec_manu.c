// PATH: FINAL PROJECT/EC_DC_INTERFACE/SEC_MENU.C

// ITS EC DC INTERFACE MENU
#include "ec_dc_header.h"

int sec_menu(int oper)
{
    int star;
    system("cls");
    printf("|---------------------------------------------------------------|\n");
    printf("|                                                               |\n");
    printf("|                                                               |\n");
    printf("|         Lets Start Encyption and Decryption of Files          |\n");
    printf("|\t\tPress 1 to Encrypt Files         \t\t|\n");
    printf("|\t\tPress 2 to List Files            \t\t|\n");
    printf("|\t\tPress 3 to Decrypt Files         \t\t|\n");
    printf("|\t\tPress 4 to Update Username       \t\t|\n");
    printf("|\t\tPress 5 to Update User Password  \t\t|\n");
    printf("|\t\tPress -1 to exit                 \t\t|\n");
    printf("|                                                               |\n");
    printf("|                                                               |\n");
    printf("|---------------------------------------------------------------|\n\n");
    fflush(stdin);
    printf("Enter your choice\n");
    scanf("%d", &star); // AFTER CHOSING THE FUCNTION CALL EC DC INTERFACE
    system("cls");
    ec_dc_interface(star);
    return 0;
}