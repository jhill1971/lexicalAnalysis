#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// Function Prototypes
int count_letters(const char *text);
int count_words(const char *text);
int count_sentences(const char *text);
int get_index(int letters, int words, int sentences);

int main(void)
{
    // prompt the user for a string of text using fgets.
    char text[1000];
    printf("Text: ");
    fgets(text, sizeof(text), stdin);
    
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    int index = get_index(letters, words, sentences);
    
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }
    return 0;
}

// This function gets the number of letters in the target text.
int count_letters(const char *text)
{
    int len = strlen(text);
    int num_letters = 0;
    for (int i = 0; i < len; i++)
    {
        if (isalpha(text[i]))
        {
            num_letters++;
        }
    }
    return num_letters;
}

// This function gets the number of words in the target text
int count_words(const char *text)
{
    int num_words = 0;
    int len = strlen(text);
    for (int j = 0; j < len; j++)
    {
        if (isspace(text[j]))
        {
            num_words++;
        }
    }
    return num_words + 1;
}

// This function counts the number of sentences in the target text
int count_sentences(const char *text)
{
    int len = strlen(text);
    int num_sentences = 0;
    for (int k = 0; k < len; k++)
    {
        if (text[k] == '.' || text[k] == '?' || text[k] == '!')
        {
            num_sentences++;
        }
    }
    return num_sentences;
}

// This function calculates the readability index of the target text
int get_index(int letters, int words, int sentences)
{
    float l = ((float)letters / (float)words) * 100.0;
    float s = ((float)sentences / (float)words) * 100.0;
    int coleman_liao = round(0.0588 * l - 0.296 * s - 15.8);
    return coleman_liao;
}
