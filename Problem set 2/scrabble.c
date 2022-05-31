#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    int length = strlen(word);
    int score = 0;
    char letter;
    int position;
    for (int i = 0; i < length; i++)
    {
        //convierto todo a minúsculas
        letter = tolower(word[i]);
        if (letter >= 'a' && letter <= 'z')
        {
            position = (letter - 96) - 1; // el valor ascii de la letra - 96 y todo eso menos 1, porque en un array se cuenta desde 0
            score = score + POINTS[position];
        }
    }
    return score;
}
