// PATH: FINAL PROJECT/DATA/PASS.C

#include "dataheader.h"
void takepass(char password[100]) // TAKE INPUT OF PASSWORD
{
    int alpha = 0, c = 0;
    char character; // AND PRINT '*'
    while (1)
    {
        character = getch();                        // GETCH TAKE INPUT CHARACTER BY CHARACTER
        if (character == ENTER || character == TAB) // AND STORE IN CHARACTER VARIABLE
        {
            password[alpha] = '\0';
            break;
        }
        else if (character == BACKSPACE) // DELETE LETTER OF PASSWORD
        {
            if (alpha > 0)
            {
                alpha--;   // DECREMENT
                printf("\b \b");
            }
        }
        else
        {
            password[alpha] = character;  // FOR EACH LETTER PRINT '*'
            printf("*");
        }
        alpha++;
    }
    pass_check(password); // CALLING FUNCTION OF PASS CHECK
}
void pass_check(char password[100]) // CHECK REQUIREMENTS OF PASSWORD
{
    int c = 0, capital = 0, punct = 0, digit = 0, small = 0;
    int len = strlen(password); // CALCULATE LENGTH OF PASSWORD
    if (len < 8)                // IF PASSWORD HAS LESS THAN 8 CHARACTERS
    {
        printf("\nPassword must contain 8 Characters\n");
        printf("\nPlease reenter your password\n");
        takepass(password); // IN CASE OF THIS ERROR RECALL TAKEPASS
    }
    for (int alpha = 0; alpha < len; alpha++) // LOOP FOR CHECKING DIFFERENT REQUIREMENTS
    {
        if (password[alpha] >= 65 && password[alpha] <= 90)
        {
            capital++; // IF IT HAS CAPITAL LETTER
        }
        if (password[alpha] >= 48 && password[alpha] <= 57)
        {
            digit++; // IF IT HAS DIGIT
        }
        if ((password[alpha] >= 97 && password[alpha] >= 122))
        {
            small++; // IF IT HAS SMALL LETTER
        }
        else
        {
            punct++;
        }
    }
    // CHECK CONDITIONS FOR EACH REQUIREMENT
    if (capital == 0)    // CAPITAL LETTER ERROR MASSAGE
    {
        printf("\nPassword Must contain a Capital Letter");
        printf("\nPlease reenter your password\n");
        takepass(password);
    }
    if (digit == 0)     // DIGIT ERROR MASSAGE
    {
        printf("\nPassword Must contain a Digit");
        printf("\nPlease reenter your password\n");
        takepass(password);
    }
    if (punct == 0)        // SPECIAL CHARACTER ERROR MASSAGE
    {
        printf("\nPassword Must contain a Special Character");
        printf("\nPlease reenter your password\n");
        takepass(password);
    }
}