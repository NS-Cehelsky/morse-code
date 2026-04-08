#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "morse.h"

// Prevod jednej znakovej jednotky na Morseho
void transistor(char c, char morse[])
{
    switch (c)
    {
        case 'a': strcpy(morse, ".-"); break;
        case 'b': strcpy(morse, "-..."); break;
        case 'c': strcpy(morse, "-.-."); break;
        case 'd': strcpy(morse, "-.."); break;
        case 'e': strcpy(morse, "."); break;
        case 'f': strcpy(morse, "..-."); break;
        case 'g': strcpy(morse, "--."); break;
        case 'h': strcpy(morse, "...."); break;
        case 'i': strcpy(morse, ".."); break;
        case 'j': strcpy(morse, ".---"); break;
        case 'k': strcpy(morse, "-.-"); break;
        case 'l': strcpy(morse, ".-.."); break;
        case 'm': strcpy(morse, "--"); break;
        case 'n': strcpy(morse, "-."); break;
        case 'o': strcpy(morse, "---"); break;
        case 'p': strcpy(morse, ".--."); break;
        case 'q': strcpy(morse, "--.-"); break;
        case 'r': strcpy(morse, ".-."); break;
        case 's': strcpy(morse, "..."); break;
        case 't': strcpy(morse, "-"); break;
        case 'u': strcpy(morse, "..-"); break;
        case 'v': strcpy(morse, "...-"); break;
        case 'w': strcpy(morse, ".--"); break;
        case 'x': strcpy(morse, "-..-"); break;
        case 'y': strcpy(morse, "-.--"); break;
        case 'z': strcpy(morse, "--.."); break;

        case '0': strcpy(morse, "-----"); break;
        case '1': strcpy(morse, ".----"); break;
        case '2': strcpy(morse, "..---"); break;
        case '3': strcpy(morse, "...--"); break;
        case '4': strcpy(morse, "....-"); break;
        case '5': strcpy(morse, "....."); break;
        case '6': strcpy(morse, "-...."); break;
        case '7': strcpy(morse, "--..."); break;
        case '8': strcpy(morse, "---.."); break;
        case '9': strcpy(morse, "----."); break;

        default: morse[0] = '\0';
    }
}

// text -> morzeovka
void text_to_morse(const char text[], char output[])
{
    int out = 0;

    for (int i = 0; text[i] != '\0'; i++)
    {
        char morse[10];
        char c = tolower(text[i]);

        transistor(c, morse);

        for (int j = 0; morse[j] != '\0'; j++)
            output[out++] = morse[j];

        if (text[i + 1] != '\0')
            output[out++] = ' ';
    }

    output[out] = '\0';
}

// naplni array morseovo abecedou
void mackopes(char arr[][6])
{
    // čísla
    strcpy(arr[0], "-----");
    strcpy(arr[1], ".----");
    strcpy(arr[2], "..---");
    strcpy(arr[3], "...--");
    strcpy(arr[4], "....-");
    strcpy(arr[5], ".....");
    strcpy(arr[6], "-....");
    strcpy(arr[7], "--...");
    strcpy(arr[8], "---..");
    strcpy(arr[9], "----.");

    // písmená
    const char *letters[] = {
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....",
        "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.",
        "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-",
        "-.--", "--.."
    };

    for (int i = 0; i < 26; i++)
        strcpy(arr[i + 10], letters[i]);
}

// porovna či existuje písmeno v morzeovke
int compare_letter(const char code[])
{
    char morse_map[36][6];
    mackopes(morse_map);

    for (int i = 0; i < 36; i++)
        if (strcmp(code, morse_map[i]) == 0)
            return 1;

    return 0;
}

// skontroluje správnosť morzeovky
int is_morse_code_valid(const char morse[])
{
    if (morse == NULL || strlen(morse) == 0)
        return 1;

    char buffer[6] = {0};
    int pos = 0;

    for (int i = 0; morse[i] != '\0'; i++)
    {
        if (morse[i] == ' ')
        {
            if (pos == 0 || pos > 5) return 0;
            if (!compare_letter(buffer)) return 0;

            memset(buffer, 0, sizeof(buffer));
            pos = 0;
            continue;
        }

        if (pos < 5)
            buffer[pos++] = morse[i];
        else
            return 0;
    }

    if (pos > 0)
        if (!compare_letter(buffer)) return 0;

    return 1;
}

// morzeovka -> text
void morse_to_text(const char morse[], char output[])
{
    if (morse == NULL || output == NULL)
        return;

    if (!is_morse_code_valid(morse))
        return;

    char map[36][6];
    mackopes(map);

    int out = 0;
    char buffer[6] = {0};
    int pos = 0;

    for (int i = 0; morse[i] != '\0'; i++)
    {
        if (morse[i] == ' ')
        {
            for (int j = 0; j < 36; j++)
            {
                if (strcmp(buffer, map[j]) == 0)
                {
                    output[out++] = (j < 10) ? (j + '0') : (j - 10 + 'A');
                    break;
                }
            }
            memset(buffer, 0, sizeof(buffer));
            pos = 0;
            continue;
        }
        buffer[pos++] = morse[i];
    }

    // posledné písmeno
    for (int j = 0; j < 36; j++)
    {
        if (strcmp(buffer, map[j]) == 0)
        {
            output[out++] = (j < 10) ? (j + '0') : (j - 10 + 'A');
            break;
        }
    }

    output[out] = '\0';
}

