#include <stdio.h>
#include <string.h>
#include "morse.h"

int main()
{

    char output[150];
    
    text_to_morse("Hello", output);
    puts(output);

    if (is_morse_code_valid("--. --- .-. -... .-- ..- .-. . "))
        printf("Code is valid!\n");
    else
        printf("Code is invalid!\n");

    if (is_morse_code_valid(".... . .-.--. .-.. ---"))
        printf("Code is valid!\n");
    else
        printf("Code is invalid!\n");
  
    memset(output, 0, sizeof(output));
    morse_to_text(".-- .... .- -.-- - .... .. -.", output);
    puts(output);

    return 0;
}
