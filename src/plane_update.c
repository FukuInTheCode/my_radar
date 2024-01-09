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
    sfVector2f pos;

    if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) < 1. / 20.)
        return 0;
    for (; head; head = head->next) {
        if (!(head->is_plane && head->is_flying))
            continue;
        sfSprite_move(head->sprite, head->velocity);
        pos = sfSprite_getPosition(head->sprite);
        if ((head->from.x >= head->to.x && head->to.x >= pos.x) ||
            (head->from.y >= head->to.y && head->to.y >= pos.y))
            head->is_flying = false;
        if ((pos.x >= head->to.x && head->to.x >= head->from.x) ||
            (pos.y >= head->to.y && head->to.y >= head->from.y))
            head->is_flying = false;
    }
    sfClock_restart(clock);
    return 0;
}
