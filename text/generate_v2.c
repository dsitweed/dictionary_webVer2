#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char split = '\t';

int cut(char *string, char *word, char *mean)
{
    int count = 0;
    //mean
    for (int i = 0; i < strlen(string); i++)
    {
        if (string[i] == '/')
            count++;
        if ((string[i] == '/') && ((count % 2) == 0))
        {
            strcpy(mean, string + i + 2);
            if (mean[strlen(mean) - 1] == '\n')
                mean[strlen(mean) - 1] = '\0';
            //printf("%s\n", mean);
        }
    }
    //word
    for (int i = 0; i < strlen(string); i++)
    {
        if ((string[i] == ' '))
        {
            strcpy(word, string);
            word[i] = '\0';
            printf("%s\n", word);
            return 1;
        }
    }
}

int main()
{
    FILE *a, *b, *c;
    char word[125], mean[125];
    char string[125];
    if ((a = fopen("3000word.txt", "r")) == NULL)
    {
        printf("ERROR INPUT\n");
    }
    if ((b = fopen("raw1.txt", "r")) == NULL)
    {
        printf("ERROR INPUT\n");
    }
    if ((c = fopen("result.txt", "w")) == NULL)
    {
        printf("ERROR INPUT\n");
    }

    while (fgets(string, 126, b) != NULL)
    {
        cut(string, word, mean);
        fprintf(c, "%s\t%s\n", word, mean);
    }

    fclose(a);
    fclose(b);
    fclose(c);
}
