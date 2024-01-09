/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** c
*/

#include "my.h"

static int check_line2(char **arr)
{
    int i = 0;

    for (i = 0; '0' <= arr[4][i] && arr[4][i] <= '9'; i++);
    if (arr[4][i] || !arr[5])
        return 84;
    for (i = 0; '0' <= arr[5][i] && arr[5][i] <= '9'; i++);
    if (arr[5][i] || !arr[6])
        return 84;
    for (i = 0; '0' <= arr[6][i] && arr[6][i] <= '9'; i++);
    if (arr[6][i])
        return 84;
    return 0;
}

static int check_line(char **arr)
{
    int i = 0;

    if (!word_array_len(arr) ||
        (word_array_len(arr) != 4 && !my_strcmp("T", arr[0])) ||
        (word_array_len(arr) != 7 && !my_strcmp("A", arr[0])) ||
        (my_strcmp("A", arr[0]) && my_strcmp("T", arr[0])))
        return 84;
    for (i = 0; '0' <= arr[1][i] && arr[1][i] <= '9'; i++);
    if (arr[1][i] || !arr[2])
        return 84;
    for (i = 0; '0' <= arr[2][i] && arr[2][i] <= '9'; i++);
    if (arr[2][i] || !arr[3])
        return 84;
    for (i = 0; '0' <= arr[3][i] && arr[3][i] <= '9'; i++);
    if (arr[3][i] || (!arr[4] && my_strcmp("T", arr[0])))
        return 84;
    if (!my_strcmp("T", arr[0]))
        return 0;
    return check_line2(arr);
}

static int check_file(FILE *fd, size_t n, my_obj_t **head)
{
    char *line = NULL;
    size_t line_n = 0;
    char **arr = NULL;

    for (int i = 0; getline(&line, &line_n, fd) >= 0; i++) {
        arr = my_str_to_word_array(line);
        if (check_line(arr))
            return 84;
        if (!my_strcmp(arr[0], "T"))
            add_tower(head, arr);
        if (!my_strcmp(arr[0], "A"))
            add_plane(head, arr);
        free(arr);
    }
    free(line);
    return 0;
}

int open_file(char const *path)
{
    FILE *fd = fopen(path, "r");
    struct stat s;
    int error = 0;
    my_obj_t *head = NULL;

    if (!fd || stat(path, &s))
        error |= 84;
    if (error == 84)
        return 44 + write(2, "./my_radar: bad arguments\nretry with -h\n", 40);
    if (check_file(fd, s.st_size, &head))
        return 84;
    error |= game_loop(head);
    return error;
}
