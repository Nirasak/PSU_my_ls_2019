/*
** EPITECH PROJECT, 2020
** my_ls.c
** File description:
** my_ls
*/

#include <errno.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include "my.h"

void no_flags(char *path)
{
    DIR *dir;
    struct dirent *sd;

    if ((dir = opendir(path)) == NULL && errno == 2)
        return;
    else if (errno == 20 && dir == NULL) {
        my_printf("%s\n", path);
        return;
    }
    while ((sd = readdir(dir)) != NULL)
        if (sd->d_name[0] != '.')
            my_printf("%s\n", sd->d_name);
    closedir(dir);
}
