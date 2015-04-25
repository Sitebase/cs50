#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(int argc, string argv[])
{

    // check for correct number of arguments
    if (argc != 2)
    {
        printf("Usage: vigenere <key>\n");
        return 1;
    }

    // check for illegal key usage
    if (strcmp(argv[1], "Hax0r2") == 0)
    {
        printf("Illegal key Hax0r2\n");
        return 1;
    }

    // declare variables
    char* text = GetString();
    int text_length = strlen(text);
    char* key = argv[1];
    int key_length = strlen(key);
    int rotation_map[ key_length ];
    int rotation;
    int i;

    // make rotation map array
    for (i = 0 ; i < key_length ; i++) 
    {
        // convert character i to a decimal representation
        int character = (int) key[i];

        // give it a base of zero
        character -= ( character <= 90 ) ? 65 : 97;

        // store the rotation in the map
        rotation_map[i] = character;
    }

    int rot_position;
    int letter_count = 0;
    for (i = 0; i < text_length; i++)
    {
        int letter = (int) text[i];

        // calculate the rotation of the current letter based on the key
        if ((letter >= 65 && letter <= 90) || (letter >= 97 && letter <= 122))
        {
            rot_position = letter_count % key_length;
            rotation = rotation_map[rot_position]; 
            letter_count++;
        }

        // uppercase letters
        if (letter >= 65 && letter <= 90)
        {
            letter = ((letter - 65) + rotation) % 26;
            letter += 65;
        }
        // lowercase letters
        if (letter >= 97 && letter <= 122)
        {
            letter = ((letter - 97) + rotation) % 26;
            letter += 97;
        }

        text[i] = (char) letter;
        
    }

    printf("%s\n", text);

    return 0;

}
