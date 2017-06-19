#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//=================================================================
int checkAlpha(string user_name, int char_position)
{
    int answer = 0;
    if(isalpha(user_name[char_position]))
    {
        answer = 1;    
    }
    return answer;
}
//=================================================================
int checkBlank(string user_name, int char_position)
{
    int answer = 0;
    if(char_position == 0 || isblank(user_name[char_position -1]))
    {
        answer = 1;    
    }
    return answer;
}
//=================================================================
void printInitials(string user_name)
{
    int n = 0;
    while(user_name[n] !='\0')
    {
        if(checkAlpha(user_name, n) && checkBlank(user_name, n))
        {
            printf("%c",toupper(user_name[n]));
        }
        n++;
    }
    printf("\n");
}
//=================================================================   
int main(void) 
{
    printInitials(get_string());
}

/* 
=========================== old version
*/
// int main(void)
// {
//     string s = get_string();
//     if(s != NULL){
//         printf("%c",toupper(s[0])); //print first initial
//     }
//     int space_position = 0; //count where space is
//     int n = 0;
//     while (s[n] != '\0')
//     {

//         if (isblank(s[n]))
//         {
//             space_position = n;
//         }
//         n++;
//     }
//     printf("%c\n",toupper(s[space_position +1])); //print second initial
// }