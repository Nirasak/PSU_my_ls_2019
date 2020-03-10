/*
** EPITECH PROJECT, 2020
** ls_d.c
** File description:
** flag d
*/

#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <dirent.h>
#include "my.h"

int ls_d(ls_t *ls_s)
{
    for (int i = 0; ls_s->path[i] != NULL; i++)
        if (opendir(ls_s->path[i]) != NULL || errno != 2)
            my_printf("%s\n", ls_s->path[i]);
    if (ls_s->not_found != 0)
        return (84);
    return (0);
}
