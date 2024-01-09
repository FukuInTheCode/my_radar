/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** c
*/

#include "my.h"

static int check_file(FILE *fd)
{
    return 0;
}

int open_file(char const *path)
{
    FILE *fd = fopen(path, "r");

    if (!fd)
        return 84;
    return 0;
}
