// PATH: FINAL PROJECT/DATA/INPUT.C

#include "dataheader.h"
void input(char choice[100]) // TAKE INPUT FROM THE USER
{
    fgets(choice, 100, stdin); // IT WILL WORK AS SCANF
    choice[strlen(choice) - 1] = 0;
    input_check(choice);
}

int input_check(char choice[100])
{
    if (choice[0] == '\0')
    {
        printf("Invalid Input\n"); // IF USER ENTER WITHOUT ANY INPUT
        printf("Please enter a valid input\n");
        input(choice);
    }
    else
    {
        return 0;
    }
}