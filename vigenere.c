#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    
    if (argc < 2) 
    {
        printf("missing command-line argument\n");
        return 1;
    }
    else if (argc > 2) 
    {
        printf("provide only one command-line argument\n");
        return 1;
    }
    else
    {
        for (int a = 0, b = strlen(argv[1]); a < b; a++)
        {
            if (!isalpha(argv[1][a]))
            {
                printf("your command-line argument can not include a number\n");
                return 1;
            }    
        }
    }
        
    int counter = 0; // a counter that increases by 1 when a non-alphabetical character is unchanged
    
    printf("plaintext: ");
    char text[100];
    fgets(text, 100, stdin);  // string value stored in a variable named text
    
    printf("ciphertext: ");
    
    for (int i = 0, n = strlen(text); i < n; i++) 
    {
        
        const char *const key = argv[1];
        int j = i; 
        int input_sign_in_ascii = text[i]; // declaration of a local variable consisting of the ASCII value of an input sign
        int string_length = strlen(key);
        
        if (counter == string_length) // reset counter to 0 when it reaches the length of argv[1]
        {
            counter = 0;
        }
        
        if (i < string_length)
        {
            j = i - counter;
        }
        else if (i % string_length == 0 && counter == 0)
        {
            j = (i - counter) % string_length;
        }
        else if (i % string_length == 0)
        {
            j = string_length - counter;
        }
        else if (i > string_length)
        {
            j = (i - counter) % string_length;
        }
        
        
        int modified_key = tolower(key[j]) - 97;
        int converted_upper_ascii = input_sign_in_ascii - 65 + modified_key; // this variable stores the ASCII number converted to upper case alphabetical index number plus modified key value
        int converted_lower_ascii = input_sign_in_ascii - 97 + modified_key; // this variable stores the ASCII number converted to lower case alphabetical index number plus modified key value
        
        
        if  (input_sign_in_ascii < 65 || (90 < input_sign_in_ascii && input_sign_in_ascii < 97) || (122 < input_sign_in_ascii && input_sign_in_ascii < 128)) // this if statement provides that non-alphabetical characters are unchanged
        {
            printf("%c", input_sign_in_ascii);
            counter++;
        }
        else if (64 < input_sign_in_ascii && input_sign_in_ascii < 91) // wrapping around upper case letters from Z to A
        {
            printf("%c", (converted_upper_ascii % 26 + 65));
        }
        else if (96 < input_sign_in_ascii && input_sign_in_ascii < 123) // wrapping around lower case letters from z to a
        {
            printf("%c", (converted_lower_ascii % 26 + 97));
        }
        
    }
    
    printf("");
    return 0;
    
}
