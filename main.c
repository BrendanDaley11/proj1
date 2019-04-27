#include <stdio.h>
char rotationEncryption(char *string);
char rotationDecryption(char *string);
char substitutionEncryption(char *string);

int main()
{
    int option; //an integer variable storing the choice inputted by the user for the switch case.
    char str[1024]; //the char array is created and given the value of arraySize
    printf("Firstly, enter your message to be encrypted/decrypted: \n"); //the message is entered by the user.
    scanf("%[^\n]s", str); //allows for a full sentence to be read ("without [^'\n'] whitespace isn't read and the string is cut off")
    
    printf("Please choose an option, you may select from the following:\n"); //text printed to the user to show them the menu options they have
    printf("[1] Encryption of a message with a rotation cipher given the message text and rotation amount\n"); //number in brackets showing which number to enter to select that option
    printf("[2] Decryption of a message encrypted with a rotation cipher given cipher text and rotation amount\n");
    printf("[3] Encryption of a message with a substitution cipher given message text and alphabet substitution\n");
    printf("[0] Exit\n");
    printf("Your choice? ");
    scanf("%d", &option); //scanf to allow the user to enter their option (using numbers 1 through 6. 0 terminates the program.)
    switch(option)
    {
        case 0: printf("Thank you for running the program, it will now shut down. \n"); break; //exits the program
        case 1: rotationEncryption(str); break;
        case 2: rotationDecryption(str); break;
        case 3: substitutionEncryption(str); break;
        default: printf("Unknown option %d \n Please try again. \n", option);
    }
}

char rotationEncryption(char *string)
{
    char newStr[1024];
    char c;
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
        else if (string[i] >= 97 && string[i] <=122)
        {
            c = (string[i] - 32) - rotationAmount;
            newStr[i] = c;
        }
        
        else
        {
            c = string[i] - rotationAmount;
            newStr[i] = c;
        }

    }
    
    printf("%s \n", newStr);
    printf("Thank you for running the program. It will now shut down. \n");
    return *newStr;
}

char rotationDecryption(char *string)
{
    char newStr[1024];
    char c;
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
        else if (string[i] >= 97 && string[i] <=122)
        {
            c = (string[i] - 32) + rotationAmount;
            newStr[i] = c;
        }
        
        else
        {
            c = string[i] + rotationAmount;
            newStr[i] = c;
        }

    }
    
    printf("%s \n", newStr);
    printf("Thank you for running the program. It will now shut down. \n");
    return *newStr;
}

char substitutionEncryption(char *string)
{
    char newStr[1024];
    char alphabetKey[] = "QWERTYUIOPASDFGHJKLZXCVBNM";
    char c;
    int y = 0;
    
    //printf("Please enter your substitution key: \n");
   // scanf("%s", alphabetKey);
    
    for (int i = 0; i < 1024; i++)
    {
        
        if (string[i] => 97 && string[i] <= 122)
        {
            c = (string[i] - 32);
            for (int x == 65; x < 90; x++)
            {
                if c = x;
                
            }
        }
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
        
    }
    
    return *newStr;
    
    
}