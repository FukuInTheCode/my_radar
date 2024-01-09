/*
** EPITECH PROJECT, 2024
** check.c
** File description:
** check.c
*/

#include "my.h"

int check_linear(my_obj_t *head, void *data)
{
    my_obj_t *tmp = NULL;

    for (my_obj_t *other = head->next; other; other = tmp) {
        tmp = other->next;
        if (!other->is_plane || !other->is_flying || other->is_dead)
            continue;
        if (other->is_safe && head->is_safe)
            continue;
        if (!rect_intersect(head->bounds, other->bounds))
            continue;
        remove_plane(other);
        head->is_dead = true;
    }
    if (head->is_dead)
        remove_plane(head);
    return 0;
}
