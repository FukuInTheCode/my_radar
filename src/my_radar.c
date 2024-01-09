/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"

int main(int argc, char **argv, char **envp)
{
    if (argc == 2 && !my_strcmp(argv[1], "-h"))
        return display_usage();
    return 84;
}
