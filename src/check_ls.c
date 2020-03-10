/*
** EPITECH PROJECT, 2020
** check_ls.c
** File description:
** check ls
*/

#include <errno.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include "my.h"

int send_dir_ls_flag_lrmaj(ls_t *ls_s)
{
    for (int i = 0; ls_s->path[i] != NULL; i++)
        if (opendir(ls_s->path[i]) == NULL && errno == 20)
            flag_l(ls_s->path[i]);
    for (int i = 0; ls_s->path[i] != NULL; i++)
        if (opendir(ls_s->path[i]) != NULL) {
            (ls_s->file > 0 || ls_s->dir > 0) ? my_printf("\n") : 0;
            my_printf(
                "%s:\ntotal %d\n", ls_s->path[i], get_total(ls_s->path[i]));
            flag_lrmaj(ls_s->path[i]);
            ls_s->dir++;
        }
    if (ls_s->not_found != 0)
        return (84);
    return (0);
}

int send_dir_ls_flag_rmaj(ls_t *ls_s)
{
    for (int i = 0; ls_s->path[i] != NULL; i++)
        if (opendir(ls_s->path[i]) == NULL && errno == 20)
            no_flags(ls_s->path[i]);
    for (int i = 0; ls_s->path[i] != NULL; i++)
        if (opendir(ls_s->path[i]) != NULL) {
            (ls_s->file > 0 || ls_s->dir > 0) ? my_printf("\n") : 0;
            my_printf("%s:\n", ls_s->path[i]);
            flag_rmaj(ls_s->path[i]);
            ls_s->dir++;
        }
    if (ls_s->not_found != 0)
        return (84);
    return (0);
}

int send_dir_ls_flag_l(ls_t *ls_s)
{
    for (int i = 0; ls_s->path[i] != NULL; i++)
        if (opendir(ls_s->path[i]) == NULL && errno == 20)
            flag_l(ls_s->path[i]);
    for (int i = 0; ls_s->path[i] != NULL; i++)
        if (opendir(ls_s->path[i]) != NULL) {
            (ls_s->file > 0 || ls_s->dir > 0) ? my_printf("\n") : 0;
            ls_s->i > 1 ? my_printf("%s:\n", ls_s->path[i]) : 0;
            flag_l(ls_s->path[i]);
            ls_s->dir++;
        }
    if (ls_s->not_found != 0)
        return (84);
    return (0);
}

int send_dir_ls_no_flags(ls_t *ls_s)
{
    for (int i = 0; ls_s->path[i] != NULL; i++)
        if (opendir(ls_s->path[i]) == NULL && errno == 20)
            no_flags(ls_s->path[i]);
    for (int i = 0; ls_s->path[i] != NULL; i++)
        if (opendir(ls_s->path[i]) != NULL) {
            (ls_s->file > 0 || ls_s->dir > 0) ? my_printf("\n") : 0;
            ls_s->i > 1 ? my_printf("%s:\n", ls_s->path[i]) : 0;
            no_flags(ls_s->path[i]);
            ls_s->dir++;
        }
    if (ls_s->not_found != 0)
        return (84);
    return (0);
}

int check_ls(ls_t *ls_s)
{
    for (int i = 0; ls_s->path[i] != NULL; i++) {
        if (opendir(ls_s->path[i]) == NULL && errno != 20) {
            my_printf("my_ls: cannot access '%s': No such file "
                    "or directory\n", ls_s->path[i]);
            ls_s->not_found++;
        } else if (opendir(ls_s->path[i]) == NULL && errno == 20)
            ls_s->file++;
    }
    if (ls_s->flag_l == 1 && ls_s->flag_rmaj == 1)
        return (send_dir_ls_flag_lrmaj(ls_s));
    if (ls_s->flag_l == 1)
        return (send_dir_ls_flag_l(ls_s));
    if (ls_s->flag_rmaj == 1)
        return (send_dir_ls_flag_rmaj(ls_s));
    if (ls_s->flag_d == 1)
        return (ls_d(ls_s));
    if (ls_s->flag_t == 1)
        return (send_dir_ls_t_flag(ls_s));
    return (send_dir_ls_no_flags(ls_s));
}
