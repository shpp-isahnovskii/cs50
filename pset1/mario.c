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
//====================================================================== patern
void row_builder(int static_pyramide_height, int local_pyramide_height)

{
    for (int i = 0; i < local_pyramide_height + 1 - N_BLOKS_AT_TOP; i++)
    {
        printf("-");
    }
    for(int n = 0; n < static_pyramide_height * 2 - local_pyramide_height * 2 + N_BLOKS_AT_TOP * 2; n++) //more comfortable, add "..* 2;"
    {
        printf("#");
        if(n == static_pyramide_height - local_pyramide_height + 1)  //more comfortable, add "if()"
        {
            printf("^^");
        }
    }

    printf("\n");
}
//======================================================================
void printPyramide(int static_pyramide_height) //
{
    int local_pyramide_height = static_pyramide_height;
    
    for(int h = 0; h < static_pyramide_height; h++)
    {
        row_builder(static_pyramide_height, local_pyramide_height);
        local_pyramide_height--;
    }  
}
//====================================================================== 
int main()
{
    printPyramide(get_height());
    return 0;
}