#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

/*to decode your Ceasar text change LOWER and UPPER cases from 'A','a' to 'Z', 'z' and change caesar_cipher (symbol + key) to -*/

const int LOWERCASE_ABC = 'a'; //in ASCII it from 97 to 122
const int UPPERCASE_ABC = 'A'; //..65 - 90
const int ALPHABET = 26; //sumbols in dictionary
const int VALID_INPUTS = 2;

//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * v.beta
// int check_case(char symbol)
// {
//     if(isupper(symbol))
//     {
//         return UPPERCASE_ABC;
//     }
//     else
//     {
//         return LOWERCASE_ABC;
//     }
// }

// int input_validation(int count)
// {
//     if (count != 2)
//     {
//         printf("invalid value \n");
//         return false;    
//     }
//     else
//     {
//         return true;
//     }
// }

// int main(int argc, string argv[])
// {
//     if(input_validation(argc) == true){
//     int key = atoi(argv[1]);
//     printf("crypt-key(%i), plaintext: ",key);
//     string p = get_string();
//     for (int i = 0, n = strlen(p); i < n; i++)
//     {
//         if(isalpha(p[i]))
//         {
//             printf("%c", (p[i] + key - check_case(p[i])) % ALPHABET + check_case(p[i]));
//         }
//         else
//         {
//             printf("%c", p[i]);
//         }
//     }
//     printf("\n");
//     return 0;
//     }
// }

//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * v 1.0
//===================================================================
int validation(int count, string number)
{
    int answer = 0;
    if (count != VALID_INPUTS)
    {
        answer = 1;    
    }
    else
    {
        int i = 0;
        while(number[i] != 0)
        {
            if (!isdigit(number[i++]))
            {
                answer = 1;
            }  
        }
    //     for(int i = 0, n = strlen(number); i < n; i++)
    //     {
    //         if(!isdigit(number[i]))
    //         {
    //             answer = 1;
    //         }
    //     }
    // }
    }
    return answer;
}
//===================================================================
int check_case(char symbol)
{
    if(isupper(symbol))
    {
        return UPPERCASE_ABC;
    }
    else
    {
        return LOWERCASE_ABC;
    }
}
//===================================================================
string plain_text(int key)
{
    printf("crypt-key(%i), plaintext: ",key);

    return get_string();
}
//=================================================================== formula
int caesar_cipher(char symbol, int key)
{
    if(isalpha(symbol))
    {
    return ((symbol + key - check_case(symbol)) % ALPHABET + check_case(symbol));
    }
    else
    {
    return symbol;    
    }
}
//===================================================================
void print_encrypted_text(string input_text, int key)
{
    printf("ciphertext: ");
    for (int i = 0, n = strlen(input_text); i < n; i++)
    {
        printf("%c", caesar_cipher(input_text[i], key));
    }
    printf("\n");
}
//===================================================================
//to pass cs50 validation: delete crypt-key(%i) in plain_text
int main(int argc, string argv[])
{
    if(validation(argc, argv[1]))
    {
        printf("Usage: ./caesar key \n");
        return 1;
    }
    else
    {
        int key = atoi(argv[1]);
        print_encrypted_text(plain_text(key), key);
}
        return 0;
}