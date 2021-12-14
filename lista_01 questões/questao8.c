#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 1000

typedef struct
{
    int *v, i;
}Vetor;

void toUpperCase(Vetor * a)
{
    char b[MAX];
    scanf("%[^\n]s", &b);
    for (a->i = 0; a->i < strlen(b); a->i ++)
    {
        b[a->i] = toupper(b[a->i]);
    }
    for (a->i = 0; a->i < strlen(b); a->i ++)
    {
        printf("%c", b[a->i]);
    }
}

int main()
{
    Vetor a;
    toUpperCase(&a);
    return 0;
}

