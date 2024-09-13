#include <stdio.h>

void print_list(char **rand_list, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", rand_list[i]);
    }
}