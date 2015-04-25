#include <stdio.h>
#include <cs50.h>

int main(void)
{

    // declare variables
    int height;
    int i; 
    int j;
    char* question = "Height";

    // ask user for a height
    do 
    {
        printf("%s: ", question);

        // get the input from the user
        height = GetInt(); 
    } while( height < 0 || height > 23 ); 

    // draw piramid
    // horizontal line by horizontal line
    for(i = 0 ; i < height ; i++) 
    {
        // draw line
        for(j = 1 ; j < (height) ; j++) 
        {
            if ( j >= (height - i)) 
            {
                printf("#");
            } else 
            {
                printf(" ");
            }
        }

        // draw the last two columns of the piramid
        // these are the same for every line
        printf("##\n"); 
    }

    return 0;
}
