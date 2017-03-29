#include <cs50.h>
#include <stdio.h>

const int PYRAMID_MAX_HEIGHT = 23;
const int N_BLOKS_AT_TOP = 2;


int get_height()
{
    int height;
    do
    {
        printf("Height: ");
        height = get_int();
    }
    while (height < 0 || height > PYRAMID_MAX_HEIGHT);
    return (height);
}

// void bloks_and_spaces(int pyramid_height, int n_row)   /*first version*/
// {
//     int pyramid_spaces = pyramid_height - N_BLOKS_AT_TOP;
//     int pyramid_bloks = pyramid_height - pyramid_spaces;
    
//     for(int h = 0; h < n_row +1; h++)
//     {
//         for (int i = 0; i < pyramid_spaces; i++)
//         {
//             printf("-");
//         }
//         pyramid_spaces--;
        
//         for(int n = 0; n < pyramid_bloks; n++)
//         {
//             printf("#");
//         }
//         pyramid_bloks++;
//         printf("\n");
//     }
//}
//====================================================================== patern
void row_builder(int pyramid_spaces, int pyramid_bloks)
{
    for (int i = 0; i < pyramid_spaces - 1 + N_BLOKS_AT_TOP; i++)
    {
        printf(" ");
    }
    for(int n = 0; n < pyramid_bloks + pyramid_bloks; n++) //more comfortable, add "..+ pyramid_bloks;"
    {
        printf("#");
        if(n == pyramid_bloks - 1)  //more comfortable, add "if()"
        {
            printf("  ");
        }
    }

    printf("\n");
}
//====================================================================== builder
void calculation(int X) //row_builder inside
{
    
}
//====================================================================== green flag
int main(void)
{
    int pyramid_height = get_height();
    //bloks_and_spaces(pyramid_height, pyramid_height - N_BLOKS_AT_TOP); /*first version*/
    
    int pyramid_bloks = N_BLOKS_AT_TOP;
    int pyramid_spaces = pyramid_height - pyramid_bloks;
    
    for(int h = 0; h < pyramid_height; h++)
    {
        row_builder(pyramid_spaces, pyramid_bloks);
        pyramid_bloks++;
        pyramid_spaces--;
    }
}