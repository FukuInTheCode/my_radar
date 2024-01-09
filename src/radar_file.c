/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** c
*/

#include "my.h"

static int check_file(FILE *fd, size_t n)
{
    char *line = NULL;
    size_t line_n = 0;

    for (; getline(&line, &line_n, fd) >= 0;)
        printf(line);
    free(line);
    return 0;
}

int open_file(char const *path)
{
    FILE *fd = fopen(path, "r");
    struct stat s;
    int error = 0;
    my_plane_t head;

    if (!fd || stat(path, &s))
        error |= 84;
    if (error == 84)
        return 44 + write(2, "./my_radar: bad arguments\nretry with -h\n", 40)
            + fclose(fd);
    return check_file(fd, s.st_size);
    error |= game_loop(&head);
    return 0;
}
