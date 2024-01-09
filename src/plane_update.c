/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"

int update_plane(sfRenderWindow *w, my_obj_t *head, void *tree,
    sfClock *clock)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) < 1. / 20.)
        return 0;
    for (; head; head = head->next)
        sfSprite_move(head->sprite, head->velocity);
    sfClock_restart(clock);
    return 0;
}
