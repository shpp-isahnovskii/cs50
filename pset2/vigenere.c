#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

/*to decode your Vigenere: change LOWER, UPPER cases 'A','a' to 'Z', 'z' and change vigenereCode (symbol + (tolower(key)) to - */

const int UPPERCASE = 'A';
const int LOWERCASE = 'a';
const int ACII_KEY_A ='a'; //use it for decoding (useles in normal version)
const int ALPHABET = 26;
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
        answer = UPPERCASE;
    }
    else
    {
        answer = LOWERCASE;
    }
    return answer;
}
//======================================================================= formula
//TODO: switch from '97, 99' to '0, 1..', next % 26 then return to ASCII.
int vigenereCode(char symbol, char key)
{
    return ( (symbol + (tolower(key) - ACII_KEY_A) - checkCase(symbol) ) % ALPHABET + checkCase(symbol) );
}
//=======================================================================
void vigenerePrint(string text, string key)
{
    printf("ciphertext: ");
    int i = 0, n = 0;
    while(text[i] != 0)
    {
        if(isalpha(text[i]))
        {
            printf("%c", vigenereCode(text[i], key[n %strlen(key)])); //change all key inputs to lowercase
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
    vigenerePrint(getPlainText(), argv[1]);
    return 0;
}

/*$ ./vigenere bacon
plaintext: Meet me at the park at eleven am
ciphertext: Negh zf av huf pcfx bt gzrwep oz*/