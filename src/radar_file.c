/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** c
*/

#include "my.h"

static int check_line2(char **arr, int j)
{
    int i = 0;

    if ((!my_strcmp(arr[0], "T") && word_array_len(arr) != 6) || arr[5][j])
        return 84;
    if (!my_strcmp(arr[0], "A") && word_array_len(arr) != 7)
        return 84;
    for (; '0' <= arr[6][i] && arr[6][i] <= '9'; i++);
    if (arr[6][i])
        return 84;
    return 0;
}

static int check_line(char **arr)
{
    int i = 0;

    if (!(!my_strcmp(arr[0], "T") || !my_strcmp(arr[0], "A")) ||
        !*arr || !arr[2])
        return 84;
    for (i = 0; '0' <= arr[1][i] && arr[1][i] <= '9'; i++);
    if (arr[1][i] || !arr[2])
        return 84;
    for (i = 0; '0' <= arr[2][i] && arr[2][i] <= '9'; i++);
    if (arr[2][i] || !arr[3])
        return 84;
    for (i = 0; '0' <= arr[3][i] && arr[3][i] <= '9'; i++);
    if (arr[3][i] || !arr[4])
        return 84;
    for (i = 0; '0' <= arr[4][i] && arr[4][i] <= '9'; i++);
    if (arr[4][i] || !arr[5])
        return 84;
    for (i = 0; '0' <= arr[5][i] && arr[5][i] <= '9'; i++);
    return check_line2(arr, i);
}


static int check_file(FILE *fd, size_t n, my_obj_t *head)
{
    char *line = NULL;
    size_t line_n = 0;
    char **arr = NULL;

    for (; getline(&line, &line_n, fd) >= 0;) {
        if ((line[0] != 'A' && line[0] != 'T') || line[1] != ' ')
            return 0;
        arr = my_str_to_word_array(line);
        if (check_line(arr))
            return 84;
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
    my_obj_t head;

    if (!fd || stat(path, &s))
        error |= 84;
    if (error == 84)
        return 44 + write(2, "./my_radar: bad arguments\nretry with -h\n", 40)
            + fclose(fd);
    error |= check_file(fd, s.st_size, &head);
    error |= game_loop(&head);
    return error;
}
