/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"

static int check_env(char **envp)
{
    for (int i = 0; env[i]; i++)
        if (my_strncmp(env[i], "DISPLAY", 6))
            return 0;
    return 84;
}

int main(int argc, char **argv, char **envp)
{
    if (check_env(envp))
        return 84;
    if (argc == 2 && my_strlen(argv[2]) == 2 && !my_strncmp(argv[1], "-h", 2))
        return display_usage();
    if (argc == 2)
        return open_file(argv[1]);
    return 84;
}
