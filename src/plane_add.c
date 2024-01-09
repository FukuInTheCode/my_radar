/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"

static double get_angle(char **arr)
{
    int x0 = my_getnbr(arr[1]);
    int y0 = my_getnbr(arr[2]);
    int x1 = my_getnbr(arr[3]);
    int y1 = my_getnbr(arr[4]);
    int x2 = x1 - x0;
    int y2 = y1 - y0;
    double angle = atan2(y2, x2);
    return angle;
}

static int plane_info(my_obj_t *new, char **arr)
{
    sfSprite_setPosition(new->sprite, (sfVector2f){my_getnbr(arr[1]),
        my_getnbr(arr[2])});
    new->is_flying = true;
    new->is_plane = true;
    new->to = (sfVector2f){my_getnbr(arr[3]), my_getnbr(arr[4])};
    new->velocity = (sfVector2f){my_getnbr(arr[5]) * cos(get_angle(arr)) / 20.,
        my_getnbr(arr[5]) * sin(get_angle(arr)) / 20.};
    sfSprite_setRotation(new->sprite, 180. / M_PI * get_angle(arr) + 90.);
    return 0;
}

int add_plane(my_obj_t **head, char **arr)
{
    my_obj_t *new = malloc(sizeof(my_obj_t));

    if (!new)
        return 84;
    new->sprite = sfSprite_create();
    if (!new->sprite)
        return 84;
    sfSprite_setTexture(new->sprite,
        sfTexture_createFromFile(paths[0], NULL), sfTrue);
    if (!sfSprite_getTexture(new->sprite))
        return 84;
    if (plane_info(new, arr))
        return 84;
    new->next = *head;
    *head = new;
    return 0;
}
