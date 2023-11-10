// PATH: FINAL PROJECT/EC_DC_INTERFACE/DECRYPT.C

#include "ec_dc_header.h"
void decrypt()
{
    char character;
    int oper, init;
    FILE *specs, *crypt;
    char  choice[100];
    char src_path[100] = ABS_ADRESS, src_file[100];     // DEFINED PATH FOR ENCRYPTED FILES
    char dest_path[100] = ABSOL_ADRESS, dest_file[100]; // DEFINED PATH FOR DECRYPTED FILES
    printf("Enter the Name of Source File ");
    printf("(File of Encrypted_Files folder)\n");
    fflush(stdin);
    input(src_file);
    strcat(src_path, src_file);
    specs = fopen(src_path, "r");
    if (specs == NULL)
    {
        printf("Incorrect File Name\n");       // IF FILE NOT FOUND AT THE GIVEN PATH
        printf("Press any Key if You want to Retry\n"); // COUNTINUE MASSAGE
        init = getch();
        decrypt(); // RECURSION
    }
    else
    {
        fflush(stdin);
        printf("Enter the Name of File to be Created at Dest_Path ");
        printf("(File will be Created in Decrypted_Files Folder)\n");
        input(dest_file);
        strcat(dest_path, dest_file);

        crypt = fopen(dest_path, "w"); // OPEN FILE TO SAVE ENCRYPTED STATEMENT
        while (1)
        {
            character = fgetc(specs);
            if (character == EOF)
            {
                printf("\nSuccessful Decryption!\n");
                break;
            }
            else
            {
                character = character - 15;
                fputc(character, crypt);
            }
        }
    }
    fclose(specs);
    fclose(crypt);
    printf("Press any Key to Continue\n");
    init = getch();
    system("cls");
    sec_menu(oper);
}