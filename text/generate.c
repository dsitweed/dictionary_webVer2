#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char split = '\t';
int cut(char *string, char *word, char *mean)
{
    for (int i = 0; i < strlen(string); i++)
    {
        if (string[i] == split)
        {
            //printf("%d\n", i);
            strcpy(mean, string + i + 1);
            mean[strlen(mean) - 1] = '\0';
            string[i] = '\0';
            strcpy(word, string);
            return 1;
        }
    }
}

int main()
{
    FILE *a, *b;
    char word[125], mean[125];
    char string[125];
    if ((a = fopen("3000word.txt", "r")) == NULL)
    {
        printf("ERROR INPUT\n");
    }
    if ((b = fopen("data.json", "w")) == NULL)
    {
        printf("ERROR INPUT\n");
    }
    fprintf(b, "[\n");
    while (fgets(string, 126, a) != NULL)
    {
        cut(string, word, mean);
        printf("%s %s\n", word, mean);
        fprintf(b, "{\n \"word\":\"%s\",\n \"mean\":\"%s\"  },\n", word, mean);
    }
    fprintf(b, "]");

    fclose(a);
    fclose(b);
}