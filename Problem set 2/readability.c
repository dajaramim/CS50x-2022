#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*formula Coleman-Liau index => index = 0.0588 * L - 0.296 * S - 15.8
L es el promedio de las letras divididas por las palabras, todo esto multiplicado por 100
S es el promedio de las oraciones divididas  palabras, todo esto multiplicado por 100 */
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    // calculo de index
    int index = round(0.0588 * ((float)letters / (float)words) * 100 - 0.296 * ((float)sentences / (float)words) * 100 - 15.8);
    
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

}
// counting Letters
int count_letters(string text)
{
    int length = strlen(text);
    int counter = 0;

    for (int i = 0; i < length; i++)
    {
        if (isalpha(text[i]))
        {
            counter++;
        }
    }
    return counter;
}
// counting Words
int count_words(string text)
{
    int length = strlen(text);
    int counter = 0;

    for (int i = 0; i < length; i++)
    {
        if (isspace(text[i]))
        {
            counter++;
        }
    }
    // adding last word to counter
    counter += 1;

    return counter;
}
int count_sentences(string text)
{
    int length = strlen(text);
    int counter = 0;

    for (int i = 0; i < length; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            counter++;
        }
    }
    return counter;
}
