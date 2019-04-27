#include <stdio.h>
int main()
{
    char str[10];
    char newStr[10];
    char c;
    printf("Enter a string: \n");
    scanf("%s", str);
    printf("Read: %s\n", str);
    
    for (int i = 0; i < 4; i++)
    {
        c = str[i] + 1;
        newStr[i] = c;
    }
    
    printf("New string: %s\n", newStr);
}
