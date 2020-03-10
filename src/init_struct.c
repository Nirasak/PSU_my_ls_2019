/*
** EPITECH PROJECT, 2020
** init_struct.c
** File description:
** init struct
*/

#include <stdlib.h>
#include "my.h"

bool check_flag_ls(char *str, ls_t *ls_s)
{
    for (int i = 1; str[i] != '\0'; i++) {
        if (str[i] != 'l' && str[i] != 'R' && str[i] != 'd'
            && str[i] != 'r' && str[i] != 't')
            return (false);
        if (str[i] == 'l')
            ls_s->flag_l = true;
        if (str[i] == 'R')
            ls_s->flag_rmaj = true;
        if (str[i] == 'd')
            ls_s->flag_d = true;
        if (str[i] == 'r')
            ls_s->flag_rmin = true;
        if (str[i] == 't')
            ls_s->flag_t = true;
    }
    return (true);
}

bool fill_struct(char **av, ls_t *ls_s, int i)
{
    if (av[i][0] != '-') {
        ls_s->path[ls_s->i] = my_strdup(av[i]);
        if (ls_s->path[ls_s->i] == NULL)
            return (false);
        ls_s->i++;
        return (true);
    }
    return (check_flag_ls(av[i], ls_s));
}

bool init_struct(int ac, char **av, ls_t *ls_s)
{
    ls_s->flag_l = false;
    ls_s->flag_rmaj = false;
    ls_s->flag_d = false;
    ls_s->flag_rmin = false;
    ls_s->flag_t = false;
    ls_s->i = 0;
    ls_s->file = 0;
    ls_s->dir = 0;
    ls_s->not_found = 0;
    ls_s->path = malloc(sizeof(char *) * (ac + 1));
    if (ls_s->path == NULL)
        return (false);
    for (int i = 1; i < ac; i++)
        if (fill_struct(av, ls_s, i) == false)
            return (false);
    ls_s->path[ls_s->i] = NULL;
    if (ls_s->i == 0)
        ls_s->path[ls_s->i] = my_strdup(".");
    ls_s->path[ls_s->i + 1] = NULL;
    return (true);
}
