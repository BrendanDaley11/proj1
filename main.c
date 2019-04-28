#include <stdio.h>
char rotationEncryption(char *string);
char rotationDecryption(char *string);
char substitutionEncryption(char *string);

int main()
{
    int option; //an integer variable storing the choice inputted by the user for the switch case.
    char str[1024]; //the char array is created and given the value of 1024
    printf("Firstly, enter your message to be encrypted/decrypted: \n"); //the message is entered by the user.
    scanf("%[^\n]s", str); //allows for a full sentence to be read ("without [^'\n'] whitespace isn't read and the string is cut off")
    
    printf("Please choose an option, you may select from the following:\n"); //text printed to the user to show them the menu options they have
    printf("[1] Encryption of a message with a rotation cipher given the message text and rotation amount\n"); //number in brackets showing which number to enter to select that option
    printf("[2] Decryption of a message encrypted with a rotation cipher given cipher text and rotation amount\n");
    printf("[3] Encryption of a message with a substitution cipher given message text and alphabet substitution\n");
    printf("[4] Decryption of a message encrypted with a substitution cipher given cipher text and substitutions\n");
    printf("[0] Exit\n");
    printf("Your choice? ");
    scanf("%d", &option); //scanf to allow the user to enter their option (using numbers 1 through 6. 0 terminates the program.)
    switch(option)
    {
        case 0: printf("Thank you for running the program, it will now shut down. \n"); break; //exits the program
        case 1: rotationEncryption(str); break;
        case 2: rotationDecryption(str); break;
        case 3: substitutionEncryption(str); break;
        default: printf("Unknown option %d , \n Please try again. \n", option);
    }
}

char rotationEncryption(char *string)
{
    char newStr[1024]; //a new char array to store the encrypted message
    char c; //char variable used to store values to be put into newStr array
    int rotationAmount; //an int variable that the user inputs to rotate the encrypted message
    
    printf("Please enter your rotation amount: \n");
    scanf("%d", &rotationAmount);
    
    for (int i = 0; i < 1024; i++) //this for loop will convert any lower case characters into upper case before encryption
    {
        
        if (string[i] >= 97 && string[i] <= 122)
        {
            string[i] = (string[i] - 32);
        }
    }
    
    for (int i = 0; i < 1024; i++)
    {
        if(string[i] < 65)
        {
            c = string[i];
            newStr[i] = c;
        }
        else if(string[i] == 65) //if the index is A, it will rotate around to Z (or whatever the rotation amount is)
        {
            c = 91 - rotationAmount;
            newStr[i] = c;
        }
        else if (string[i] > 90 && string[i] < 97)
        {
            c = string[i];
            newStr[i] = c;
        }
        else if (string[i] > 122)
        {
            c = string[i];
            newStr[i] = c;
        }
        else if (string[i] == 97)
        {
            c = 91 - rotationAmount;
            newStr[i] = c; 
        }
        else
        {
            c = string[i] - rotationAmount;
            newStr[i] = c;
        }

    }
    
    printf("%s \n", newStr); //prints the new encrypted message
    printf("Thank you for running the program. It will now shut down. \n"); //displays a message to the user letting them know the program is ending
    return *newStr; //returns the newStr array (not actually used, it's just so there's absolutely no errors in the console)
}

char rotationDecryption(char *string)
{
    char newStr[1024]; //a new char array to store the encrypted message
    char c; //char variable used to store values to be put into newStr array
    int rotationAmount; 
    
    printf("Please enter your rotation amount: \n");
    scanf("%d", &rotationAmount);
    
    for (int i = 0; i < 1024; i++)
    {
        if(string[i] < 65)
        {
            c = string[i];
            newStr[i] = c;
        }
        else if(string[i] == 90) //if the index is A, it will rotate around to Z (or whatever the rotation amount is)
        {
            c = 64 + rotationAmount;
            newStr[i] = c;
        }
        else if (string[i] > 90 && string[i] < 97)
        {
            c = string[i];
            newStr[i] = c;
        }
        else if (string[i] > 122)
        {
            c = string[i];
            newStr[i] = c;
        }
        else if (string[i] == 97)
        {
            c = 91 - rotationAmount;
            newStr[i] = c; 
        }
        
        else
        {
            c = string[i] + rotationAmount;
            newStr[i] = c;
        }

    }
    
    printf("%s \n", newStr); //prints the new encrypted message
    printf("Thank you for running the program. It will now shut down. \n"); //displays a message to the user letting them know the program is ending
    return *newStr; //returns the newStr array (not actually used, it's just so there's absolutely no errors in the console)
}

char substitutionEncryption(char *string)
{
    char newStr[1024]; //a new char array to store the encrypted message
    char alphabetKey[26]; //a char array used to store a key. It's given a size of 26 as that is how many letters there are in the alphabet
    char c; //char variable used to store values to be put into newStr array
    
    printf("Please enter your substitution key: \n");
    scanf("%s", alphabetKey);
    
    for (int i = 0; i < 1024; i++) //this for loop will convert any lower case characters into upper case before encryption
    {
        
        if (string[i] >= 97 && string[i] <= 122)
        {
            string[i] = (string[i] - 32);
        }
    }
    
    for (int i = 0; i < 1024; i++)
    {
        if (string[i] == 65)
        {
            c = alphabetKey[0];
            newStr[i] = c;
        }
        else if (string[i] == 66)
        {
            c = alphabetKey[1];
            newStr[i] = c;
        }
        else if (string[i] == 67)
        {
            c = alphabetKey[2];
            newStr[i] = c;
        }
        else if (string[i] == 68)
        {
            c = alphabetKey[3];
            newStr[i] = c;
        }
        else if (string[i] == 69)
        {
            c = alphabetKey[4];
            newStr[i] = c;
        }
        else if (string[i] == 70)
        {
            c = alphabetKey[5];
            newStr[i] = c;
        }
        else if (string[i] == 71)
        {
            c = alphabetKey[6];
            newStr[i] = c;
        }
        else if (string[i] == 72)
        {
            c = alphabetKey[7];
            newStr[i] = c;
        }
        else if (string[i] == 73)
        {
            c = alphabetKey[8];
            newStr[i] = c;
        }
        else if (string[i] == 74)
        {
            c = alphabetKey[9];
            newStr[i] = c;
        }
        else if (string[i] == 75)
        {
            c = alphabetKey[10];
            newStr[i] = c;
        }
        else if (string[i] == 76)
        {
            c = alphabetKey[11];
            newStr[i] = c;
        }
        else if (string[i] == 77)
        {
            c = alphabetKey[12];
            newStr[i] = c;
        }
        else if (string[i] == 78)
        {
            c = alphabetKey[13];
            newStr[i] = c;
        }
        else if (string[i] == 79)
        {
            c = alphabetKey[14];
            newStr[i] = c;
        }
        else if (string[i] == 80)
        {
            c = alphabetKey[15];
            newStr[i] = c;
        }
        else if (string[i] == 81)
        {
            c = alphabetKey[16];
            newStr[i] = c;
        }
        else if (string[i] == 82)
        {
            c = alphabetKey[17];
            newStr[i] = c;
        }
        else if (string[i] == 83)
        {
            c = alphabetKey[18];
            newStr[i] = c;
        }
        else if (string[i] == 84)
        {
            c = alphabetKey[19];
            newStr[i] = c;
        }
        else if (string[i] == 85)
        {
            c = alphabetKey[20];
            newStr[i] = c;
        }
        else if (string[i] == 86)
        {
            c = alphabetKey[21];
            newStr[i] = c;
        }
        else if (string[i] == 87)
        {
            c = alphabetKey[22];
            newStr[i] = c;
        }
        else if (string[i] == 88)
        {
            c = alphabetKey[23];
            newStr[i] = c;
        }
        else if (string[i] == 89)
        {
            c = alphabetKey[24];
            newStr[i] = c;
        }
        else if (string[i] == 90)
        {
            c = alphabetKey[25];
            newStr[i] = c;
        }
        else
        {
            c = string[i];
            newStr[i] = c;
        }   
    }
    
    printf("%s \n", newStr); //prints the new encrypted message
    printf("Thank you for running the program. It will now shut down. \n"); //displays a message to the user letting them know the program is ending
    return *newStr; //returns the newStr array (not actually used, it's just so there's absolutely no errors in the console)
    
    
}