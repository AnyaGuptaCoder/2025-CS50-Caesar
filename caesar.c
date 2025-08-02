#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    string in = argv[1];
    int e = 0;
    if (in[0] == '-' || in[0] == '+')
    {
        e = 1;
    }
    for (; in[e] != '\0'; e++)
    {
        if (!isdigit(in[e]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    int k = atoi(in);
    if (!(k >= 0))
    {
        printf("Usage: ./caesar key\n");
        return 2;
    }
    char lowers[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                     'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char uppers[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                     'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    string str = get_string("Plaintext: ");
    int index = 0;
    string new = "";
    for (int i = 0; i < strlen(str); i++)
    {
        if (isupper(str[i]))
        {
            index = str[i] - 'A';
            index = index + k;
            index = index % 26;
            str[i] = uppers[index];
        }
        else if (islower(str[i]))
        {
            index = str[i] - 'a';
            index = index + k;
            index = index % 26;
            str[i] = lowers[index];
        }
        else
        {
            new = new + str[i];
        }
    }
    printf("Ciphertext: %s\n", str);
}
