#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main(void)
{
    FILE *ft;
    char const *name = "abc.txt";
    int ch;

    ft = fopen(name, "a");
    if (ft == NULL)
    {
        fprintf(stderr, "cannot open target file %s\n", name);
        exit(1);
    }

    while((ch = getchar()) != EOF)
    {
        fputc(ch,ft);
    }
    fclose(ft);

// reading
    ft = fopen(name, "r");
    if (ft == NULL)
    {
        fprintf(stderr, "cannot open target file %s\n", name);
        exit(1);
    }
    while ((ch = fgetc(ft)) != EOF)
    {
        printf("%c",ch);
    }
    fclose(ft);

    // modifying
    ft = fopen(name, "r+");
    if (ft == NULL)
    {
        fprintf(stderr, "cannot open target file %s\n", name);
        exit(1);
    }
    while ((ch = fgetc(ft)) != EOF)
    {
        if (ch == 'i')
        {
            fseek(ft, -1, SEEK_CUR);
            fputc('I',ft);
            fseek(ft, 0, SEEK_CUR);
        }
    }
    fclose(ft);

// updated
    ft = fopen(name, "r");
    if (ft == NULL)
    {
        fprintf(stderr, "cannot open target file %s\n", name);
        exit(1);
    }
    while ((ch = fgetc(ft)) != EOF)
    {
        printf("%c",ch);
    }
    fclose(ft);


    return 0;
}