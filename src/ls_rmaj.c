/*
** EPITECH PROJECT, 2020
** ls_rmaj.c
** File description:
** ls -R
*/

#include <sys/types.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

void flag_lrmaj2(struct stat st, struct dirent *sd, char *str)
{
    if ((st.st_mode & S_IFMT) == S_IFDIR && sd->d_name[0] != '.') {
        my_printf("\n%s:\n", str);
        my_printf("total %d\n", get_total(str));
        flag_lrmaj(str);
        free(str);
    }
}

void flag_lrmaj(char *path)
{
    DIR *dir;
    DIR *to_check;
    struct dirent *sd;
    struct stat st;
    char *str = NULL;

    if ((dir = opendir(path)) == NULL)
        return;
    to_check = opendir(path);
    while ((sd = readdir(dir)) != NULL)
        if (sd->d_name[0] != '.')
            my_right(concate_files(path, sd->d_name), sd->d_name);
    while ((sd = readdir(to_check)) != NULL) {
        str = concate_files(path, sd->d_name);
        lstat(str, &st);
        flag_lrmaj2(st, sd, str);
    }
}

void flag_rmaj(char *path)
{
    DIR *dir;
    DIR *to_check;
    struct dirent *sd;
    struct stat st;
    char *str = NULL;

    if ((dir = opendir(path)) == NULL)
        return;
    to_check = opendir(path);
    while ((sd = readdir(dir)) != NULL)
        sd->d_name[0] != '.' ? my_printf("%s\n", sd->d_name) : 0;
    while ((sd = readdir(to_check)) != NULL) {
        str = concate_files(path, sd->d_name);
        lstat(str, &st);
        if ((st.st_mode & S_IFMT) == S_IFDIR && sd->d_name[0] != '.') {
            my_printf("\n%s:\n", str);
            flag_rmaj(str);
            free(str);
        }
    }
}
