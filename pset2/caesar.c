#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(int argc, string argv[])
{

    // make sure the user provided a rotation to use
    if ( argc < 2 )
    {
        printf("Usage: caesar <key>\n");
        return 1;
    }

    char* text = GetString();
    int rotation = atoi(argv[1]);

    // loop over each character of the text and rotate it
    int i;
    int letter;
    int n = strlen(text);
    for(i = 0; i < n; i++)
    {
        // get the decimal representation of letter i
        letter = (int) text[i];

        // uppercase letters
        if ( letter >= 65 && letter <= 90 )
        {
            letter = ((letter - 65) + rotation) % 26;
            letter += 65;

        }
        // lowercase letters
        if ( letter >= 97 && letter <= 122 )
        {
            letter = ((letter - 97) + rotation) % 26;
            letter += 97;
        }

        // convert the decimal rotated character back to a normal character
        text[i] = (char) letter;
    }

    printf("%s\n", text);

    return 0;

}
