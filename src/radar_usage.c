/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"

int display_usage(void)
{
    FILE *fd = fopen("./assets/help.txt", "r");
    char buf[1001] = {0};

    if (!fd)
        return 84;
    if (fread(buf, 1, 1000, fd) == 0)
        return 84;
    write(1, buf, my_strlen(buf));
    fclose(fd);
    return 0;
}
