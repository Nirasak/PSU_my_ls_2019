/*
** EPITECH PROJECT, 2020
** test_my_ls.c
** File description:
** test ls
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

void redirect_stdout(void)
{
    cr_redirect_stdout();
}

Test(my_ls, test_one, .init = redirect_stdout)
{
    ls_t ls_s;
    char *av[6] = {"./my_ls", "-l", "yo", "src/", "lib", "Makefile"};

    init_struct(6, av, &ls_s);
    cr_assert_eq(check_ls(&ls_s), 84);
}

Test(my_ls, test_two, .init = redirect_stdout)
{
    ls_t ls_s;
    char *av[5] = {"./my_ls", "-l", "src/", "lib", "Makefile"};

    init_struct(5, av, &ls_s);
    cr_assert_eq(check_ls(&ls_s), 0);
}

Test(my_ls, test_three, .init = redirect_stdout)
{
    ls_t ls_s;
    char *av[5] = {"./my_ls", "-R", "src/", "lib", "Makefile"};

    init_struct(5, av, &ls_s);
    cr_assert_eq(check_ls(&ls_s), 0);
}

Test(my_ls, test_four, .init = redirect_stdout)
{
    ls_t ls_s;
    char *av[6] = {"./my_ls", "-R", "yo", "src/", "lib", "Makefile"};

    init_struct(6, av, &ls_s);
    cr_assert_eq(check_ls(&ls_s), 84);
}

Test(my_ls, test_five, .init = redirect_stdout)
{
    ls_t ls_s;
    char *av[6] = {"./my_ls", "-d", "yo", "src/", "lib", "Makefile"};

    init_struct(6, av, &ls_s);
    cr_assert_eq(check_ls(&ls_s), 84);
}

Test(my_ls, test_six, .init = redirect_stdout)
{
    ls_t ls_s;
    char *av[5] = {"./my_ls", "-d", "src/", "lib", "Makefile"};

    init_struct(5, av, &ls_s);
    cr_assert_eq(check_ls(&ls_s), 0);
}

Test(my_ls, test_seven, .init = redirect_stdout)
{
    ls_t ls_s;
    char *av[5] = {"./my_ls", "yo", "src/", "lib", "Makefile"};

    init_struct(5, av, &ls_s);
    cr_assert_eq(check_ls(&ls_s), 84);
}

Test(my_ls, test_eight, .init = redirect_stdout)
{
    ls_t ls_s;
    char *av[4] = {"./my_ls", "src/", "lib", "Makefile"};

    init_struct(4, av, &ls_s);
    cr_assert_eq(check_ls(&ls_s), 0);
}

Test(my_ls, test_nine, .init = redirect_stdout)
{
    ls_t ls_s;
    char *av[6] = {"./my_ls", "-t", "yo", "src/", "lib", "Makefile"};

    init_struct(6, av, &ls_s);
    cr_assert_eq(check_ls(&ls_s), 84);
}

Test(my_ls, test_ten, .init = redirect_stdout)
{
    ls_t ls_s;
    char *av[5] = {"./my_ls", "-t", "src/", "lib", "Makefile"};

    init_struct(5, av, &ls_s);
    cr_assert_eq(check_ls(&ls_s), 0);
}

Test(my_ls, test_eleven, .init = redirect_stdout)
{
    ls_t ls_s;
    char *av[6] = {"./my_ls", "-Rl", "yo", "src/", "lib", "Makefile"};

    init_struct(6, av, &ls_s);
    cr_assert_eq(check_ls(&ls_s), 84);
}

Test(my_ls, test_twelve, .init = redirect_stdout)
{
    ls_t ls_s;
    char *av[5] = {"./my_ls", "-Rl", "src/", "lib", "Makefile"};

    init_struct(5, av, &ls_s);
    cr_assert_eq(check_ls(&ls_s), 0);
}

Test(my_ls, test_thirteen, .init = redirect_stdout)
{
    ls_t ls_s;
    char *av[5] = {"./my_ls", "-Rdtlre", "src/", "lib", "Makefile"};

    cr_assert_eq(init_struct(5, av, &ls_s), 0);
}
