#include <cs50.h>
#include <stdio.h>

const int PYRAMID_MAX_HEIGHT = 23;
const int BLOKS_AT_TOP = 1;  //changeable
const int ADD_WALL_MIRROR = 2; //changeable 1 or 2

int getHeight()
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
void buildRow(int static_pyramide_height, int local_pyramide_height)
{
    for (int i = 0; i < local_pyramide_height - 1; i++) // -1 to clear one top section for a brick
    {
        printf(" ");
    }
    for(int n = 0; n < (static_pyramide_height - local_pyramide_height + BLOKS_AT_TOP) * ADD_WALL_MIRROR ; n++)
    {
        printf("#");
        if(ADD_WALL_MIRROR == 2 && n == static_pyramide_height - local_pyramide_height + BLOKS_AT_TOP -1)
        {
            printf("  ");
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
        buildRow(static_pyramide_height, local_pyramide_height);
        local_pyramide_height--;
    }  
}
//====================================================================== 
int main()
{
    printPyramide(getHeight());
    return 0;
}