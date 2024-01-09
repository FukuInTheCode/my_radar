/*
** EPITECH PROJECT, 2024
** check.c
** File description:
** check.c
*/

#include "my.h"

int check_linear(void *data)
{
    my_obj_t *head = data;

    for (my_obj_t *other = head->next; other; other = other->next) {
        if (!other->is_plane || !other->is_flying || other->is_dead)
            continue;
        if (other->is_safe && head->is_safe)
            continue;
        if (!rect_intersect(head->bounds, other->bounds))
            continue;
        head->is_dead = true;
        other->is_dead = true;
    }
    return 0;
}
