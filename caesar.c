#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{

    if (argc < 2) 
    {
        printf("missing command-line argument\n");
        return 1;
    }
    if (argc > 2) 
    {
        printf("provide only one command-line argument\n");
        return 1;
    }
    if (atoi(argv[1]) < 0) 
    {
        printf("a value of your command-line argument can not be a negative number\n");
        return 1;
    }
        
    
    int key = atoi(argv[1]); // integer value of a command-line argument stored in a variable named key
    
    printf("plaintext: ");
    char text[100];
    fgets(text, 100, stdin);  // string value stored in a variable named text
    
    printf("ciphertext: ");
    
    for (int i = 0, n = strlen(text); i < n; i++) 
    {
        int input_sign_in_ascii = text[i]; // declaration of a local variable consisting of the ASCII value of an input sign
        int converted_upper_ascii = input_sign_in_ascii - 65 + key; // this variable stores the ASCII number converted to upper case alphabetical index number plus the argv value
        int converted_lower_ascii = input_sign_in_ascii - 97 + key; // this variable stores the ASCII number converted to lower case alphabetical index number plus the argv value
        
        if  (input_sign_in_ascii < 65 || (90 < input_sign_in_ascii && input_sign_in_ascii < 97) || (122 < input_sign_in_ascii && input_sign_in_ascii < 128)) // this if statement provides that non-alphabetical characters are unchanged
        {
            printf("%c", input_sign_in_ascii);
        }
        else if (64 < input_sign_in_ascii && input_sign_in_ascii < 91) // wrapping around upper case letters from Z to A
        {
            printf("%c", (converted_upper_ascii % 26 + 65));
        }
        else if (96 < input_sign_in_ascii && input_sign_in_ascii < 123) // wrapping around lower case letters from z to a
        {
            printf("%c", (converted_lower_ascii % 26 + 97));
        };
    }
    
    printf("");
    return 0;
    
}
