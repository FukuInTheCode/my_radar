/*
** EPITECH PROJECT, 2024
** setup.c
** File description:
** setup.c
*/

#include "my.h"

static my_qtree_t *create_leaf(double x1, double y1, double x2, double y2)
{
    my_qtree_t *qtree = malloc(sizeof(my_qtree_t));

    qtree->is_leaf = true;
    qtree->len = 0;
    qtree->top_left = (sfVector2f){x1, y1};
    qtree->bot_right = (sfVector2f){x2, y2};
    qtree->top_l = NULL;
    qtree->top_r = NULL;
    qtree->bot_l = NULL;
    qtree->bot_r = NULL;
    qtree->rect = (sfFloatRect){x1, y1, x2 - x1, y2 - y1};
    for (uint32_t i = 0; i < QUADTREE_SIZE; i++)
        qtree->arr[i] = NULL;
    return qtree;
}

static int switch_to_branch(my_qtree_t *qtree, my_obj_t *obj)
{
    sfVector2f topl = qtree->top_left;
    sfVector2f botr = qtree->bot_right;

    qtree->is_leaf = false;
    qtree->top_l = create_leaf(topl.x, topl.y, botr.x / 2., botr.y / 2.);
    qtree->top_r = create_leaf(botr.x / 2., topl.y, botr.x, botr.y / 2.);
    qtree->bot_l = create_leaf(topl.x, botr.y / 2., botr.x / 2., botr.y);
    qtree->bot_r = create_leaf(botr.x / 2., botr.y / 2., botr.x, botr.y);
    if (obj->is_plane)
        return add_plane_qtree(qtree, obj);
    return 0;
}

int add_plane_qtree(my_qtree_t *qtree, my_obj_t *plane)
{
    if (qtree == NULL)
        return 84;
    if (!qtree->is_leaf)
        return add_plane_qtree(qtree->top_l, plane) |
            add_plane_qtree(qtree->top_r, plane) |
            add_plane_qtree(qtree->bot_l, plane) |
            add_plane_qtree(qtree->bot_r, plane);
    if (qtree->len + 1 >= QUADTREE_SIZE)
        return switch_to_branch(qtree, plane);
    if (rect_intersect(qtree->rect, plane->bounds))
        qtree->arr[qtree->len++] = plane;
    return 0;
}

int setup_qtree(my_obj_t *head, my_container_t *con)
{
    my_qtree_t *qtree = NULL;

    if (con->data)
        return 0;
    qtree = create_leaf(0., 0., 1920., 1080.);
    con->data = (void *)qtree;
    return 0;
}
