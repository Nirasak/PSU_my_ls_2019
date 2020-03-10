/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main
*/

#include "my.h"

int main(int ac, char **av)
{
    ls_t ls_s;

    if (init_struct(ac, av, &ls_s) == false)
        return (84);
    return (check_ls(&ls_s));
}
