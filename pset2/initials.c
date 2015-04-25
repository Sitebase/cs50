#include <stdio.h>
#include <cs50.h>
#include <string.h>

// function to convert a lowercase letter to uppercase
char upper(char letter)
{
    if (letter >= 97)
    {
        return letter - 32;
    }
    return letter;
}

int main(int argc, string argv[])
{
    char* name;

    // ask user for a name
    do 
    {
        name = GetString(); 
    } while(strlen(name) <= 0); 

    char initials[5];
    bool space_found = false;
    int index = 1;

    // already add the first character to the initials
    initials[0] = upper(name[0]);

    for (int i=0 ; i < strlen(name) ; i++)
    {
        // if space was detected in previous itteration
        // add this character to the initials
        if (space_found)
        {
            initials[index] = upper(name[i]);
            space_found = false;
            index++;
        }

        // mark that a space was detected
        // this way we know in the next itteration that the 
        // character is part of the initials
        char check = name[i];
        if (check == ' ')
        {
            space_found = true;
        }

    }

    printf("%s\n", initials);

}
