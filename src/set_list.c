/*
** EPITECH PROJECT, 2020
** set_list.c
** File description:
** set list
*/

#include <stdlib.h>
#include "my.h"

list_t *new_node(struct stat st, char *path, char *file)
{
    list_t *node = malloc(sizeof(list_t));

    if (node == NULL)
        return (NULL);
    lstat(path, &st);
    node->st = st;
    node->file = file;
    node->prev = NULL;
    node->next = NULL;
    return (node);
}

void add_node_end_list(list_t **list, char *path, char *file)
{
    struct stat st;
    list_t *node = new_node(st, path, file);
    list_t *tmp = *list;

    if (tmp == NULL || node == NULL) {
        tmp = node;
        *list = tmp;
        return;
    }
    node->prev = tmp;
    tmp->next = node;
    *list = tmp;
}
