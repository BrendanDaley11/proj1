#include <stdio.h>
int main()
{
    char str[1024];
    char newStr[1024];
    char c;
    int rotationAmount;
    printf("Enter a string: \n");
    scanf("%[^'\n']s", str); //allows for a full sentence to be read ("without [^'\n'] whitespace isn't read and the string is cut off")
    printf("Enter a rotation amount: \n");
    scanf("%d", &rotationAmount);
    printf("Read: %s\n", str);
    
    for (int i = 0; i < 1024; i++)
    {
        if(str[i] < 65)
        {
            c = str[i];
            newStr[i] = c;
        }
        else if(str[i] == 65) //if the index is A, it will rotate around to Z (or whatever the rotation amount is)
        {
            c = 91 - rotationAmount;
            newStr[i] = c;
        }
        else if (str[i] > 90 && str[i] < 97)
        {
            c = str[i];
            newStr[i] = c;
        }
        else if (str[i] > 122)
        {
            c = str[i];
            newStr[i] = c;
        }
        else if (str[i] == 97)
        {
            c = 91 - rotationAmount;
            newStr[i] = c; 
        }
        else if (str[i] >= 97 && str[i] <=122)
        {
            c = (str[i] - 32) - rotationAmount;
            newStr[i] = c;
        }
        
        else
        {
            c = str[i] - rotationAmount;
            newStr[i] = c;
        }

    }
    
    printf("New string: %s\n", newStr);
}
