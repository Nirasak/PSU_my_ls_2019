/*
** EPITECH PROJECT, 2020
** ls_l.c
** File description:
** ls_l
*/

#include <stdlib.h>
#include <errno.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <sys/sysmacros.h>
#include "my.h"

void my_size_and_time(struct stat st)
{
    char *time_s;

    time_s = ctime(&st.st_mtime);
    if ((st.st_mode & S_IFMT) == S_IFCHR)
        my_printf("%d, %d ", major(st.st_rdev), minor(st.st_rdev));
    else
        my_printf("%d ", st.st_size);
    time_s += 4;
    time_s[12] = '\0';
    my_printf("%s ", time_s);
}

void my_nb_links_and_name(struct stat st)
{
    struct passwd *pwd;
    struct group *grp;

    my_printf("%d ", st.st_nlink);
    pwd = getpwuid(st.st_uid);
    grp = getgrgid(st.st_gid);
    my_printf("%s ", pwd->pw_name);
    my_printf("%s ", grp->gr_name);
    my_size_and_time(st);
}

void my_right2(struct stat st)
{
    if ((st.st_mode & S_IFMT) == S_IFREG)
        my_printf("-");
    if ((st.st_mode & S_IFMT) == S_IFDIR)
        my_printf("d");
    if ((st.st_mode & S_IFMT) == S_IFBLK)
        my_printf("b");
    if ((st.st_mode & S_IFMT) == S_IFCHR)
        my_printf("c");
    if ((st.st_mode & S_IFMT) == S_IFIFO)
        my_printf("p");
    if ((st.st_mode & S_IFMT) == S_IFLNK)
        my_printf("l");
    if ((st.st_mode & S_IFMT) == S_IFSOCK)
        my_printf("s");
}

void my_right(char *path, char *file)
{
    struct stat st;

    lstat(path, &st);
    my_right2(st);
    my_printf("%c", (st.st_mode & S_IRUSR) ? 'r' : '-');
    my_printf("%c", (st.st_mode & S_IWUSR) ? 'w' : '-');
    my_printf("%c", (st.st_mode & S_IXUSR) ? 'x' : '-');
    my_printf("%c", (st.st_mode & S_IRGRP) ? 'r' : '-');
    my_printf("%c", (st.st_mode & S_IWGRP) ? 'w' : '-');
    my_printf("%c", (st.st_mode & S_IXGRP) ? 'x' : '-');
    my_printf("%c", (st.st_mode & S_IROTH) ? 'r' : '-');
    my_printf("%c", (st.st_mode & S_IWOTH) ? 'w' : '-');
    if ((st.st_mode & S_IXOTH) && (st.st_mode & __S_ISVTX))
        my_printf("t. ");
    else if (st.st_mode & S_IXOTH)
        my_printf("x. ");
    else
        st.st_mode & __S_ISVTX ? my_printf("T. ") : my_printf("-. ");
    my_nb_links_and_name(st);
    my_printf("%s\n", file);
}

void flag_l(char *path)
{
    DIR *dir;
    struct dirent *sd;

    if ((dir = opendir(path)) == NULL && errno == 2)
        return;
    else if (errno == 20 && dir == NULL) {
        my_right(path, path);
        return;
    }
    my_printf("total %d\n", get_total(path));
    while ((sd = readdir(dir)) != NULL)
        if (sd->d_name[0] != '.')
            my_right(concate_files(path, sd->d_name), sd->d_name);
}
