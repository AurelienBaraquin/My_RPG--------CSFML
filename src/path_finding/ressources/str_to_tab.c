/*
** EPITECH PROJECT, 2023
** str_to_tab.c
** File description:
** find Path
*/

#include "path_finding.h"

int	my_desep(char s, char *sep)
{
    int i = 0;
    while (sep[i]) {
        if (s == sep[i])
            return (-1);
        i++;
    }
    return 0;
}

int	is_a_sep(char const *str, int i, char *sep)
{
    if (my_desep(str[i], sep) == -1) {
        while (my_desep(str[i], sep) == -1)
            i++;
        i--;
    }
    return i;
}

int words_number(char const *str, char *sep)
{
    int i = 0;
    int	nb_words = 1;
    while (str[i]) {
        i = is_a_sep(str, i, sep);
        nb_words += 1;
        i++;
    }
    return nb_words;
}

int	word_size(char *str, int i, char *sep)
{
    int	size = 0;
    while (my_desep(str[i], sep) == 0 && str[i]) {
        size++;
        i++;
    }
    return size;
}

char **my_str_to_tab(char *str, char *sep)
{
    int	nb_word = words_number(str, sep) + 2;
    int	i = 0;
    int	y = 0;
    int	x = 0;
    char **tab = malloc(sizeof(char *) * (nb_word + 1));
    while (str[i]) {
        x = 0;
        for (; (my_desep(str[i], sep) == -1 && str[i]); i++);
        tab[y] = malloc(sizeof(char) * (word_size(str, i, sep) + 1));
        for (; my_desep(str[i], sep) == 0 && str[i]; i++ , x++)
            tab[y][x] = str[i];
        tab[y][x] = '\0';
        y++;
        for (; (my_desep(str[i], sep) == -1 && str[i]); i++);
    }
    tab[y] = NULL;
    return (tab);
}
