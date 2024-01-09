/*
** EPITECH PROJECT, 2024
** tower_check.c
** File description:
** tower_check.c
*/

#include "my.h"

bool inside_tower(my_obj_t *tower, sfFloatRect a)
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
