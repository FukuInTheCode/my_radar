/*
** EPITECH PROJECT, 2024
** setup.c
** File description:
** setup.c
*/

#include "my.h"



int setup_qtree(my_obj_t *head, my_container_t *con)
{
    my_qtree_t *qtree = NULL;

    if (!con->data)
        printf("hi\n");
    qtree->is_leaf = true;
    qtree->len = 0;
    qtree->top_left = (sfVector2f){0., 0.};
    qtree->bot_right = (sfVector2f){1920., 1080.};
    qtree->top_l = NULL;
    qtree->top_r = NULL;
    qtree->bot_l = NULL;
    qtree->bot_r = NULL;
    return 0;
}
