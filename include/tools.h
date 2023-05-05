/*
** EPITECH PROJECT, 2023
** prot.h
** File description:
** Prototypes for all functions
*/


#ifndef PROT_H_
    #define PROT_H_

    #include <unistd.h>
    #include <stdlib.h>

int my_strlen(char *str);
void my_putstr(char *str);
void my_putchar(char c);
void my_put_nbr(int nb);
int my_getnbr(char *str);
int my_strncmp(char *str1, char *str2, int n);
int my_strcmp(char *str1, char *str2);
void *my_memset(void *s, int c, size_t n);
char *my_strcat(char *dest, const char *src);
char * restrcat(char *dest, char *str);
char *my_strncpy(char *dest, char *src, size_t n);
char *my_strchr(char *str, int c);
void *my_memcpy(void *dest, void *src, size_t n);
char* my_strcpy(char* dest, char* src);
char *my_strstr(char *str, char *substr);
char* my_strdup(char* str);
int contain(char *str, char c);
int is_num(char str);
int is_char(char *str);
char *nb_to_str(int nb);

#endif /* !PROT.H\_H_ */
