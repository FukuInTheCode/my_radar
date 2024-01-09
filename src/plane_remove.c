/*
** EPITECH PROJECT, 2024
** plane_remove.c
** File description:
** plane_remove.c
*/

#include "my.h"

int remove_plane(my_obj_t *plane)
{
    if (!plane->is_plane)
        return 84;
    plane->is_dead = true;
    if (plane->is_first)
        return 0;
    sfSprite_destroy(plane->sprite);
    if (plane->previous)
        plane->previous->next = plane->next;
    if (plane->next)
        plane->next->previous = plane->previous;
    free(plane);
    return 0;
}
