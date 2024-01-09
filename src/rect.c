/*
** EPITECH PROJECT, 2024
** rect.c
** File description:
** rect.c
*/

#include "my.h"

bool rect_intersect(sfFloatRect a, sfFloatRect b)
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
