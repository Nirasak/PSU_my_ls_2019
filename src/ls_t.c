/*
** EPITECH PROJECT, 2020
** ls_t.c
** File description:
** flag t
*/

#include <dirent.h>
#include <errno.h>
#include "my.h"

void swap_elems_nodes(list_t **list)
{
    struct stat st = (*list)->st;
    char *file = (*list)->file;

    (*list)->st = (*list)->next->st;
    (*list)->file = (*list)->next->file;
    (*list)->next->st = st;
    (*list)->next->file = file;
}

void add_to_list(list_t **list, char *path)
{
    DIR *dir;
    struct dirent *sd;

    if ((dir = opendir(path)) == NULL)
        return;
    while ((sd = readdir(dir)) != NULL) {
        if (sd->d_name[0] != '.')
            add_node_end_list(
                list, concate_files(path, sd->d_name), sd->d_name);
        if (*list != NULL && (*list)->next != NULL)
            *list = (*list)->next;
    }
}

void flag_t(char *path)
{
    list_t *list = NULL;

    add_to_list(&list, path);
    for (; list->prev != NULL; list = list->prev);
    while (list->next != NULL) {
        if (list->st.st_mtime > list->next->st.st_mtime) {
            swap_elems_nodes(&list);
            for (; list->prev != NULL; list = list->prev);
        } else
            list = list->next;
    }
    for (; list->prev != NULL; list = list->prev)
        my_printf("%s\n", list->file);
    my_printf("%s\n", list->file);
}

int send_dir_ls_t_flag(ls_t *ls_s)
{
    for (int i = 0; ls_s->path[i] != NULL; i++)
        if (opendir(ls_s->path[i]) == NULL && errno == 20)
            no_flags(ls_s->path[i]);
    for (int i = 0; ls_s->path[i] != NULL; i++)
        if (opendir(ls_s->path[i]) != NULL) {
            (ls_s->file > 0 || ls_s->dir > 0) ? my_printf("\n") : 0;
            ls_s->i > 1 ? my_printf("%s:\n", ls_s->path[i]) : 0;
            flag_t(ls_s->path[i]);
            ls_s->dir++;
        }
    if (ls_s->not_found != 0)
        return (84);
    return (0);
}
