/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** strdup
*/

#include "tools.h"

char* my_strdup(char* str)
{
    size_t len = my_strlen(str);
    char* dup = (char*)malloc(len + 1);
    if (dup != NULL) {
        my_memcpy(dup, str, len + 1);
    }
    return dup;
}

int contain(char *str, char c)
{
    int i = 0;
    int count = 0;
    while (str[i] != '\0') {
        if (str[i] == c)
            count++;
        i++;
    }
    return count;
}
