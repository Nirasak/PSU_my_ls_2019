/*
** EPITECH PROJECT, 2020
** get_total.c
** File description:
** get total
*/

#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "my.h"

int get_total(char *path)
{
    DIR *dir;
    struct dirent *sd;
    struct stat st;
    int tot = 0;

    dir = opendir(path);
    while ((sd = readdir(dir)) != NULL) {
        if (sd->d_name[0] != '.')
            lstat(concate_files(path, sd->d_name), &st);
        if (sd->d_name[0] != '.')
            tot = tot + st.st_blocks;
    }
    return (tot / 2);
}
