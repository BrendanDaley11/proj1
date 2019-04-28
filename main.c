//Programmer name: Brendan Daley
//Student number: c3305879
//Purpose of code: Performs both rotation and substitution encryptions and decryptions based on a given message. The user
//                 can choose which encryption/decryption method they'd like using a menu system.
//                 This program does not use file I/O, but rather stdin and stdout methods

#include <stdio.h>
char rotationEncryption(char *string); //function definitions
char rotationDecryption(char *string);
char substitutionEncryption(char *string);
char substitutionDecryption(char *string);

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
    scanf("%d", &option); //scanf to allow the user to enter their option (using numbers 1 through 4. 0 terminates the program.)
    switch(option)
    {
        case 0: printf("Thank you for running the program, it will now shut down. \n"); break; //exits the program
        case 1: rotationEncryption(str); break; //if option 1 is selected, run the rotationEncryption function
        case 2: rotationDecryption(str); break; //if option 2 is selected, run the rotationDecryption function
        case 3: substitutionEncryption(str); break; //if option 3 is selected, run the substitutionEncryption function
        case 4: substitutionDecryption(str); break; //if option 4 is selected, run the substitutionDecryption function
        default: printf("Unknown option %d , \n Please try again. \n", option); //this error message will print if the user inputs an option outside of the range 1-4
    }
}

char rotationEncryption(char *string)
{
    char newStr[1024]; //a new char array to store the encrypted message
    char c; //char variable used to store values to be put into newStr array
    int rotationAmount; //an int variable that the user inputs to rotate the encrypted message
    
    printf("Please enter your rotation amount: \n"); //prompts the user to enter their rotation amount
    scanf("%d", &rotationAmount); //stores their input in the rotationAmount variable
    
    for (int i = 0; i < 1024; i++) //this for loop will convert any lower case characters into upper case before encryption
    {
        
        if (string[i] >= 97 && string[i] <= 122) //checks to see if the index value is between a = 97 and z = 122
        {
            string[i] = (string[i] - 32); //formula to convert the lower case letter into uppercase
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
    
    printf("Your new encrypted message is: %s \n", newStr); //prints the new encrypted message
    printf("Thank you for running the program. It will now shut down. \n"); //displays a message to the user letting them know the program is ending
    return *newStr; //returns the newStr array (not actually used, it's just so there's absolutely no errors in the console)
}

char rotationDecryption(char *string)
{
    char newStr[1024]; //a new char array to store the decrypted message
    char c; //char variable used to store values to be put into newStr array
    int rotationAmount; //an int variable that the user inputs to rotate the encrypted message
    
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
    
    printf("Your new decrypted message is: %s \n", newStr); //prints the new decrypted message
    printf("Thank you for running the program. It will now shut down. \n"); //displays a message to the user letting them know the program is ending
    return *newStr; //returns the newStr array (not actually used, it's just so there's absolutely no errors in the console)
}

char substitutionEncryption(char *string)
{
    char newStr[1024]; //a new char array to store the encrypted message
    char alphabetKey[26]; //a char array used to store a key. It's given a size of 26 as that is how many letters there are in the alphabet
    char c; //char variable used to store values to be put into newStr array
    
    printf("Please enter your substitution key: \n"); //prompts the user for the substitution key
    scanf("%s", alphabetKey); //stores the key in the alphabetKey variable
    
    for (int i = 0; i < 1024; i++) //this for loop will convert any lower case characters into upper case before encryption
    {
        
        if (string[i] >= 97 && string[i] <= 122) //checks to see if the index value is between a = 97 and z = 122
        {
            string[i] = (string[i] - 32); //formula to convert the lower case letter into uppercase
        }
    }

    for (int i = 0; i < 1024; i++)
    {
        if (string[i] == 65) //if the letter is A
        {
            c = alphabetKey[0]; //c becomes the first letter of the encrypted key
            newStr[i] = c;
        }
        else if (string[i] == 66) //if the letter is B
        {
            c = alphabetKey[1]; //c becomes the second letter of the encrypted key
            newStr[i] = c;
        }
        else if (string[i] == 67) //if the letter is C
        {
            c = alphabetKey[2]; //c becomes the third letter of the encrypted key
            newStr[i] = c;
        }
        else if (string[i] == 68) //and so on
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
    
    printf("Your new encrypted message is: %s \n", newStr); //prints the new encrypted message
    printf("Thank you for running the program. It will now shut down. \n"); //displays a message to the user letting them know the program is ending
    return *newStr; //returns the newStr array (not actually used, it's just so there's absolutely no errors in the console)
}

char substitutionDecryption(char *string)
{
    char newStr[1024]; //a new char array to store the decrypted message
    char alphabetKey[26]; //a char array used to store the key that is supplied by the user.
    char c; //char variable used to store values to be put into newStr array
    
    printf("Please enter your substitution key to decrypt the message: \n"); //prompts the user to enter the substitution key used to encrypt the original message
    scanf("%s", alphabetKey); //stores the key in the alphabetKey variable
    
    for (int i = 0; i < 1024; i++)
    {
        if (string[i] == alphabetKey[0]) //if the index i is equal to the first letter of the key
        {
            c = 65; //c becomes A
            newStr[i] = c;
        }
        else if (string[i] == alphabetKey[1]) //if the index i is equal to the second letter of the key
        {
            c = 66; //c becomes B
            newStr[i] = c;
        }
        else if (string[i] == alphabetKey[2]) //if the index i is equal to the third letter of the key
        {
            c = 67; //c becomes C
            newStr[i] = c;
        }
        else if (string[i] == alphabetKey[3]) //and so on
        {
            c = 68;
            newStr[i] = c;
        }
        else if (string[i] == alphabetKey[4])
        {
            c = 69;
            newStr[i] = c;
        }
        else if (string[i] == alphabetKey[5])
        {
            c = 70;
            newStr[i] = c;
        }
        else if (string[i] == alphabetKey[6])
        {
            c = 71;
            newStr[i] = c;
        }
        else if (string[i] == alphabetKey[7])
        {
            c = 72;
            newStr[i] = c;
        }
        else if (string[i] == alphabetKey[8])
        {
            c = 73;
            newStr[i] = c;
        }
        else if (string[i] == alphabetKey[9])
        {
            c = 74;
            newStr[i] = c;
        }
        else if (string[i] == alphabetKey[10])
        {
            c = 75;
            newStr[i] = c;
        }
        else if (string[i] == alphabetKey[11])
        {
            c = 76;
            newStr[i] = c;
        }
        else if (string[i] == alphabetKey[12])
        {
            c = 77;
            newStr[i] = c;
        }
        else if (string[i] == alphabetKey[13])
        {
            c = 78;
            newStr[i] = c;
        }
        else if (string[i] == alphabetKey[14])
        {
            c = 79;
            newStr[i] = c;
        }
        else if (string[i] == alphabetKey[15])
        {
            c = 80;
            newStr[i] = c;
        }
        else if (string[i] == alphabetKey[16])
        {
            c = 81;
            newStr[i] = c;
        }
        else if (string[i] == alphabetKey[17])
        {
            c = 82;
            newStr[i] = c;
        }
        else if (string[i] == alphabetKey[18])
        {
            c = 83;
            newStr[i] = c;
        }
        else if (string[i] == alphabetKey[19])
        {
            c = 84;
            newStr[i] = c;
        }
        else if (string[i] == alphabetKey[20])
        {
            c = 85;
            newStr[i] = c;
        }
        else if (string[i] == alphabetKey[21])
        {
            c = 86;
            newStr[i] = c;
        }
        else if (string[i] == alphabetKey[22])
        {
            c = 87;
            newStr[i] = c;
        }
        else if (string[i] == alphabetKey[23])
        {
            c = 88;
            newStr[i] = c;
        }
        else if (string[i] == alphabetKey[24])
        {
            c = 89;
            newStr[i] = c;
        }
        else if (string[i] == alphabetKey[25])
        {
            c = 90;
            newStr[i] = c;
        }
        else
        {
            c = string[i];
            newStr[i] = c;
        }
    }
    
    printf("Your new decrypted message is: %s \n", newStr); //prints the new decrypted message
    printf("Thank you for running the program. It will now shut down. \n"); //displays a message to the user letting them know the program is ending
    return *newStr; //returns the newStr array (not actually used, it's just so there's absolutely no errors in the console)
    
}