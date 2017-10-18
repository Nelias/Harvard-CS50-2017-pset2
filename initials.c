#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{  
    char name[100];
    printf("Enter your name: ");
    fgets(name, 100, stdin);
    
    printf("Your initials are: ");
    printf("%c", toupper(name[0]));
    
    for (int i = 0, n = strlen(name); i < n; i++)
    {
        int k = name[i];
        if (k == 32)
        {
           printf("%c", toupper(name[i + 1]));
        }
    }
    
    printf("\n");
}
