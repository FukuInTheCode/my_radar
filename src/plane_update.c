/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"

static int inside_loop(my_obj_t *head, void *tree, sfVector2f pos)
{
    pos = sfSprite_getPosition(head->sprite);
    head->time_alive += .2;
    if (head->is_plane && head->is_flying)
        sfSprite_move(head->sprite, head->velocity);
    if (head->time_alive >= head->depart_time)
        head->is_flying = true;
    if ((head->from.x >= head->to.x && head->to.x >= pos.x) ||
        (head->from.y >= head->to.y && head->to.y >= pos.y))
        head->is_flying = false;
    if ((pos.x >= head->to.x && head->to.x >= head->from.x) ||
        (pos.y >= head->to.y && head->to.y >= head->from.y))
        head->is_flying = false;
    return 0;
}

int update_plane(sfRenderWindow *w, my_obj_t *head, void *tree,
    sfClock *clock)
{
    sfVector2f pos;

    if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) < 1. / 20.)
        return 0;
    for (; head; head = head->next)
        inside_loop(head, tree, pos);
    sfClock_restart(clock);
    return 0;
}
