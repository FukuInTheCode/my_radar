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
    double product = x0 * x1 + y0 * y1;
    double v0 = sqrt(pow(x0, 2) + pow(y0, 2));
    double v1 = sqrt(pow(x1, 2) + pow(y1, 2));
    double angle = acos(product / v0 / v1);
    printf("%lf\n", angle);
    return angle;
}

static int plane_info(my_obj_t *new, char **arr)
{
    sfSprite_setPosition(new->sprite, (sfVector2f){my_getnbr(arr[1]),
        my_getnbr(arr[2])});
    new->is_flying = true;
    new->is_plane = true;
    new->to = (sfVector2f){my_getnbr(arr[3]), my_getnbr(arr[4])};
    new->velocity = (sfVector2f){my_getnbr(arr[5]) * cos(get_angle(arr)),
        my_getnbr(arr[5]) * sin(get_angle(arr))};
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
        sfTexture_createFromFile("assets/plane.png", NULL), sfTrue);
    if (!sfSprite_getTexture(new->sprite))
        return 84;
    if (plane_info(new, arr))
        return 84;
    new->next = *head;
    *head = new;
    return 0;
}
