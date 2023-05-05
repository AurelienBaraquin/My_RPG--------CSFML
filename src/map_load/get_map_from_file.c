/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-louis.rollet
** File description:
** get_map_from_file
*/

#include "my.h"

char **get_map_from_file(char *filename)
{
    struct stat st;
    stat(filename, &st);
    int fd = open(filename, O_RDONLY);
    char *file_contents = (char*) malloc(st.st_size);
    read(fd, file_contents, st.st_size);
    close(fd);
    char **lines = (char**) malloc(sizeof(char*) * st.st_size);
    int curr_line = 0, curr_char = 0;
    while (curr_char < st.st_size) {
        int line_length = 0;
        while (curr_char + line_length < st.st_size &&
        file_contents[curr_char + line_length] != '\n')
            line_length++;
        lines[curr_line] = (char*) malloc(sizeof(char) * (line_length + 1));
        my_strncpy(lines[curr_line], &file_contents[curr_char], line_length);
        lines[curr_line][line_length] = '\0';
        curr_line++; curr_char += line_length + 1;
    }
    free(file_contents);
    return lines;
}

char **create_random_array(char min_char, char max_char,
size_t size, size_t str_len)
{
    char **array = malloc(size * sizeof(char*));
    if (array == NULL) {
        return NULL;
    }
    for (size_t i = 0; i < size; i++) {
        char *str = malloc((str_len + 1) * sizeof(char));
        if (str == NULL) {
            free(array);
            return NULL;
        }
        for (size_t j = 0; j < str_len; j++) {
            str[j] = mlrand(min_char, max_char);
        }
        str[str_len] = '\0';
        array[i] = str;
    }
    return array;
}
