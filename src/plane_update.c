/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"

static bool inside_tower(my_obj_t *tower, sfFloatRect a)
{
    double bot_a = a.top + a.height;
    double right_a = a.left + a.width;
    sfVector2f c = sfCircleShape_getPosition(tower->zone);
    double r = sfCircleShape_getRadius(tower->zone);

    c.x += r;
    c.y += r;
    if (sqrt(pow(c.x - a.left, 2) + pow(c.y - a.top, 2)) <= r ||
        sqrt(pow(c.x - a.left, 2) + pow(c.y - bot_a, 2)) <= r ||
        sqrt(pow(c.x - right_a, 2) + pow(c.y - a.top, 2)) <= r ||
        sqrt(pow(c.x - right_a, 2) + pow(c.y - bot_a, 2)) <= r)
        return true;
    return false;
}
static bool rect_intersect(sfFloatRect a, sfFloatRect b)
{
    double bot_a = a.top + a.height;
    double right_a = a.left + a.width;
    double right_b = b.left + b.width;
    double bot_b = b.top + b.height;

    if (a.top <= b.top && b.top <= bot_a &&
        a.left <= b.left && b.left <= right_a)
        return true;
    if (a.top <= b.top && b.top <= bot_a &&
        a.left <= right_b && right_b <= right_a)
        return true;
    if (a.top <= bot_b && bot_b <= bot_a &&
        a.left <= b.left && b.left <= right_a)
        return true;
    if (a.top <= bot_b && bot_b <= bot_a &&
        a.left <= right_b && right_b <= right_a)
        return true;
    return false;
}

static int check_collision(my_obj_t *head, void *tree)
{
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

static bool check_safety(my_obj_t *first, my_obj_t *current)
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
    for (my_obj_t *tmp = head; tmp; tmp = tmp->next)
        inside_loop(tmp, pos, head);
    for (; head; head = head->next)
        head->is_plane && !head->is_dead && head->is_flying &&
            check_collision(head, tree);
    sfClock_restart(clock);
    return 0;
}
