#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

/*to decode your Vigenere: change LOWER, UPPER cases from 'A','a' to 'Z','z'; change makeVigenereCode (symbol + (tolower(key)) to - */

const int UPPERCASE_A = 'A';
const int LOWERCASE_A = 'a';
const int ACII_LITTLE_A ='a'; //use it for decoding
const int CHARS_IN_ALPHABET = 26;
const int VALID_INPUTS = 2;
//=======================================================================
int checkValidation(int count, string cipher_word)
{
    int answer = 0;

    if (count != VALID_INPUTS)
    {
        answer = 1;
    }
    else
    {
        int i = 0;
        while(cipher_word[i] !=0)
        {
            if(!isalpha(cipher_word[i++]))
            {
                answer = 1;
            }
        }
    }
    return answer;
}
//=======================================================================
string getPlainText()
{
    printf("plaintext: ");
    return get_string();
}
//=======================================================================
int checkCase(char symbol)
{
    int answer;
    if(isupper(symbol))
    {
        answer = UPPERCASE_A;
    }
    else
    {
        answer = LOWERCASE_A;
    }
    return answer;
}
//======================================================================= formula
//TODO: switch from '97, 99' to '0, 1..', next % 26 then return to ASCII.
int makeVigenereCode(char symbol, char key)
{
    return ( (symbol + (tolower(key) - ACII_LITTLE_A) - checkCase(symbol) ) % CHARS_IN_ALPHABET + checkCase(symbol) );
}
//=======================================================================
void printVigenere(string text, string key)
{
    printf("ciphertext: ");
    int i = 0, n = 0;
    while(text[i] != 0)
    {
        if(isalpha(text[i]))
        {
            printf("%c", makeVigenereCode(text[i], key[n %strlen(key)])); //change all key inputs to LOWERCASE_A
            n++;
        }
        else
        {
            printf("%c", text[i]);
        }
        i++;
    }
    printf("\n");
}
//=======================================================================
int main(int argc, string argv[])
{
    if(checkValidation(argc, argv[1]))
    {
        printf("Usage: ./vigenere k \n");
        return 1;
    }
    printVigenere(getPlainText(), argv[1]);
    return 0;
}