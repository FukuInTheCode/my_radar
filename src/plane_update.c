/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"

bool check_safety(my_obj_t *first, my_obj_t *current)
{
    current->is_safe = false;
    for (; first; first = first->next)
        if (!first->is_plane && inside_tower(first, current->bounds))
            return true;
    return false;
}

static int inside_loop(my_obj_t *head, sfVector2f pos, my_obj_t *first)
{
    if (!head->is_plane)
        return 0;
    pos = sfSprite_getPosition(head->sprite);
    head->time_alive += .2;
    if (head->is_flying) {
        sfSprite_move(head->sprite, head->velocity);
        get_global_bounds(head);
    }
    head->is_safe = check_safety(first, head);
    if (head->time_alive >= head->depart_time)
        head->is_flying = true;
    if ((head->from.x >= head->to.x && head->to.x >= pos.x) ||
        (head->from.y >= head->to.y && head->to.y >= pos.y) ||
        (pos.x >= head->to.x && head->to.x >= head->from.x) ||
        (pos.y >= head->to.y && head->to.y >= head->from.y)) {
        head->is_flying = false;
        remove_plane(head);
    }
    return 0;
}

int update_plane(sfRenderWindow *w, my_obj_t *head, my_container_t *con,
    sfClock *clock)
{
    for (my_obj_t *tmp = head; tmp; tmp = tmp->next)
        inside_loop(tmp, (sfVector2f){0., 0.}, head);
    con->setup_f(head, con);
    for (; head; head = head->next)
        head->is_plane && !head->is_dead && head->is_flying &&
            con->check_f(head, con->data);
    sfClock_restart(clock);
    return 0;
}
