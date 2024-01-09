/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"

static int tower_info(my_obj_t *new, char **arr)
{
    new->is_plane = false;
    sfSprite_setPosition(new->sprite, (sfVector2f){my_getnbr(arr[1]),
        my_getnbr(arr[2])});
    sfSprite_scale(new->sprite, (sfVector2f){1e-1, 1e-1});
    new->zone = sfCircleShape_create();
    if (!new->zone)
        return 84;
    sfCircleShape_setRadius(new->zone, my_getnbr(arr[3]) * 1920. / 100.);
    sfCircleShape_setFillColor(new->zone, sfTransparent);
    sfCircleShape_setOutlineColor(new->zone, sfBlue);
    sfCircleShape_setOutlineThickness(new->zone, 2.);
    sfCircleShape_setPosition(new->zone, sfSprite_getPosition(new->sprite));
    sfCircleShape_move(new->zone,
        (sfVector2f){my_getnbr(arr[3]) * -1920. / 100. + 25,
        my_getnbr(arr[3]) * -1920 / 100. + 20});
    new->is_first = false;
    return 0;
}

int add_tower(my_obj_t **head, char **arr)
{
    my_obj_t *new = malloc(sizeof(my_obj_t));

    if (!new)
        return 84;
    new->sprite = sfSprite_create();
    if (!new->sprite)
        return 84;
    sfSprite_setTexture(new->sprite,
        sfTexture_createFromFile(paths[1], NULL), sfTrue);
    if (!sfSprite_getTexture(new->sprite))
        return 84;
    if (tower_info(new, arr))
        return 84;
    if (*head)
        (*head)->previous = new;
    new->next = *head;
    new->previous = NULL;
    *head = new;
    return 0;
}
