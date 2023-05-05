/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** strcpy
*/

#include "tools.h"

char *my_strncpy(char *dest, char *src, size_t n)
{
    size_t i;
    for (i = 0; i < n && src[i] != '\0'; i++)
        dest[i] = src[i];
    for ( ; i < n; i++)
        dest[i] = '\0';
    return dest;
}

char *my_strchr(char *str, int c)
{
    while (*str != (char)c) {
        if (!*str++)
            return NULL;
    }
    return (char *)str;
}

void *my_memcpy(void *dest, void *src, size_t n)
{
    unsigned char *d = dest;
    const unsigned char *s = src;
    while (n--)
        *d++ = *s++;
    return dest;
}

char* my_strcpy(char* dest, char* src)
{
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

char *my_strstr(char *str, char *substr)
{
    if (!str || !substr)
        return NULL;
    size_t len_sub = my_strlen(substr);
    if (!len_sub)
        return (char *)str;
    char *p = (char *)str;
    size_t len_remaining = my_strlen(p);
    while ((p = my_strchr(p, *substr)) != NULL) {
        if (len_remaining < len_sub)
            break;
        if (my_strncmp(p, substr, len_sub) == 0)
            return p;
        len_remaining -= p - str;
        p++;
    }
    return NULL;
}
