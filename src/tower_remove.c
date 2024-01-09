/*
** EPITECH PROJECT, 2024
** tower_remove.c
** File description:
** tower_remove.c
*/

#include "my.h"

int remove_tower(my_obj_t *tower)
{
    if (tower->is_plane)
        return 84;
    if (tower->zone)
        sfCircleShape_destroy(tower->zone);
    if (tower->sprite)
        sfSprite_destroy(tower->sprite);
    if (tower->previous)
        tower->previous->next = tower->next;
    if (tower->next)
        tower->next->previous = tower->previous;
    free(tower);
    return 0;
}
