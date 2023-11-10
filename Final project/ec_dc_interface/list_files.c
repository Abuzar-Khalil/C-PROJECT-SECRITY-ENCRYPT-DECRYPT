// PATH: FINAL PROJECT/EC_DC_INTERFACE/LIST_FILES.C

#include "ec_dc_header.h"
void list_files() // FUNCTION DECLARATION
{
    DIR *directory;
    struct dirent *dir;
    char filename[100];
    int i = 1, number, in;
    directory = opendir(ABS_ADRESS);  // DEFINED DIRECTORY PATH
    while ((dir = readdir(directory)) != NULL)
    {
        printf("%d. %s\n", i, dir->d_name); // SHOWING FILE NAME WITH INDEX
        i++;       
    }
    closedir(directory);    // CLOSING THE DIRECTORY
    fflush(stdin);
    int oper;
    char choice[100];
    printf("Press any key to continue\n");
    in = getch();
    system("cls");
    sec_menu(oper);
}