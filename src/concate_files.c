/*
** EPITECH PROJECT, 2020
** concat_files.c
** File description:
** concate files
*/

#include <stdlib.h>
#include "my.h"

char *concate_files(char *src, char *str)
{
    int j = 0;
    char *dest = malloc(sizeof(char) * (my_strlen(src) + my_strlen(str) + 2));

    if (dest == NULL)
        return (NULL);
    for (int i = 0; src[i] != '\0'; i++)
        dest[j++] = src[i];
    if (dest[j - 1] != '/')
        dest[j++] = '/';
    for (int i = 0; str[i] != '\0'; i++)
        dest[j++] = str[i];
    dest[j] = '\0';
    return (dest);
}
