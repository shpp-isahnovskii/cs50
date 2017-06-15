#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * v.beta
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


//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * v1.0
// void print_initials(string user_name)
// {
//     int n = 0;
//     while(user_name[n] !='\0')
//     {
//         if(isalpha(user_name[n]) && (isblank(user_name[n -1]) || n ==0))
//         {
//             printf("%c.",toupper(user_name[n]));
//         }
//         n++;
//     }
//     printf("\n");
// }



// int main(void) 
// {
//     print_initials(get_string());
// }


//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * v2.0
//=================================================== condition 1 (if char)
int alpha_check(string user_name, int char_position)
{
    if(isalpha(user_name[char_position]))
    {
        return true;    
    }
    else
    {
        return false;    
    }
}
//=================================================== condition 2 (if have space before char || if this is first char)
int blank_check(string user_name, int char_position)
{
    if(isblank(user_name[char_position -1]) || char_position == 0) // (-1) - checking previous char for space; 0 - first char.
    {
        return true;    
    }
    else
    {
        return false;    
    }
}
//=================================================== print if conditions 1,2 are true
void print_initials(string user_name)
{
    int n = 0;
    while(user_name[n] !='\0')
    {
        if(alpha_check(user_name, n) && blank_check(user_name, n))
        {
            printf("%c.",toupper(user_name[n]));
        }
        n++;
    }
    printf("\n");
}
//===================================================    
int main(void) 
{
    print_initials(get_string());
}