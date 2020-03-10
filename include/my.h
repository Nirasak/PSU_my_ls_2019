/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdbool.h>

typedef struct ls_s
{
    bool flag_l;
    bool flag_rmaj;
    bool flag_d;
    bool flag_rmin;
    bool flag_t;
    int i;
    char **path;
    int file;
    int dir;
    int not_found;
} ls_t;

typedef struct list
{
    struct stat st;
    char *file;
    struct list *next;
    struct list *prev;
} list_t;

int my_printf(char const *str, ...);
void no_flags(char *path);
int my_strlen(char const *str);
char *my_strdup(char const *src);
bool init_struct(int ac, char **av, ls_t *ls_s);
int check_ls(ls_t *ls_s);
char *concate_files(char *src, char *str);
void flag_l(char *path);
void flag_rmaj(char *path);
int get_total(char *path);
int ls_d(ls_t *ls_s);
void flag_lrmaj(char *path);
void my_right(char *path, char *file);
int send_dir_ls_t_flag(ls_t *ls_s);
void add_node_end_list(list_t **list, char *path, char *file);

#endif
