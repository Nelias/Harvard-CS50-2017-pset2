#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <crypt.h>
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
        
        const char *const salt = "50/.........../";
        
        for (int d = 0, n = 58; d < n; d++)  // fourth iteration for fourth row letters
        {
        for (int c = 0; c < n; c++)  // third iteration for third row letters
        {
        for (int b = 0; b < n; b++)  // second iteration for second row letters
        {
        for (int a = 0; a < n; a++)  // first iteration
        {
            
            char one_hashed_letter[3];
            char two_hashed_letters[4];
            char three_hashed_letters[5];
            char four_hashed_letters[6];
            
            if ((a > 25 && a < 32) || (b > 25 && b < 32) || (c > 25 && c < 32) || (d > 25 && d < 32))  // escaping all non-alphabetical numbers 
            {
            goto jump;
            }
            
            if (((a > -1 && a < 26) || (a > 31 && a < 58)))
            {
            one_hashed_letter[0] = 65 + a;
            }
            if (((b > -1 && b < 26) || (b > 31 && b < 58)) && (a > -1 || (a > 31 && a < 58)))
            {
            two_hashed_letters[0] = 65 + b;
            two_hashed_letters[1] = 65 + a;
            }
            if (((c > -1 && c < 26) || (c > 31 && c < 58)) && (b > -1 || (b > 31 && b < 58)) && (a > -1 || (a > 31 && a < 58)))
            {
            three_hashed_letters[0] = 65 + c;
            three_hashed_letters[1] = 65 + b;
            three_hashed_letters[2] = 65 + a;
            }
            if ((d > -1 || (d > 31 && d < 58)) && (c > -1 || (c > 31 && c < 58)) && (b > -1 || (b > 31 && b < 58)) && (a > -1 || (a > 31 && a < 58)))
            {
            four_hashed_letters[0] = 65 + d;
            four_hashed_letters[1] = 65 + c;
            four_hashed_letters[2] = 65 + b;
            four_hashed_letters[3] = 65 + a;
            }
           
            
            // ENCRYPTING ONE LETTER WORDS
            char *one_hashed_letter_key = one_hashed_letter;
            char *one_hashed_letter_encrypted = crypt(one_hashed_letter_key, salt);
            if ((b == 0 && c == 0 && d == 0) && (strcmp(one_hashed_letter_encrypted, argv[1]) == 0))
            {
            printf ("cracked hash: %s\n", one_hashed_letter);
            exit(0);
            }
            
            // ENCRYPTING TWO LETTER WORDS
            char *two_hashed_letters_key = two_hashed_letters;
            char *two_hashed_letters_encrypted = crypt(two_hashed_letters_key, salt);
            if ((c == 0 && d == 0) && strcmp(two_hashed_letters_encrypted, argv[1]) == 0)
            {
            printf ("cracked hash: %s\n", two_hashed_letters);
            exit(0);
            }
            
            // ENCRYPTING THREE LETTER WORDS
            char *three_hashed_letters_key = three_hashed_letters;
            char *three_hashed_letters_encrypted = crypt(three_hashed_letters_key, salt);
            if ((d == 0) && (strcmp(three_hashed_letters_encrypted, argv[1]) == 0))
            {
            printf ("cracked hash: %s\n", three_hashed_letters);
            exit(0);
            }
            
            // ENCRYPTING FOUR LETTER WORDS
            char *four_hashed_letters_key = four_hashed_letters;
            char *four_hashed_letters_encrypted = crypt(four_hashed_letters_key, salt);
            if ((d > -1) && (strcmp(four_hashed_letters_encrypted, argv[1]) == 0))
            {
            printf ("cracked hash: %s\n", four_hashed_letters);
            exit(0);
            }
            
            jump: {} // This is a jump statement that escapes iterations over non-alphabetical signs between upper case letters and lower case letters
        }
        }
        }
        }
            
        return 0;
    }
