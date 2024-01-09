/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"

int get_global_bounds(my_obj_t *new)
{
    sfTransform trs = sfSprite_getTransform(new->sprite);
    sfFloatRect rect = {0, 0, 20., 20.};

    new->bounds = sfTransform_transformRect(&trs, rect);
    return 0;
}

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
    new->is_flying = false;
    new->is_plane = true;
    new->to = (sfVector2f){my_getnbr(arr[3]), my_getnbr(arr[4])};
    new->from = sfSprite_getPosition(new->sprite);
    new->velocity = (sfVector2f){my_getnbr(arr[5]) * cos(get_angle(arr)) / 20.,
        my_getnbr(arr[5]) * sin(get_angle(arr)) / 20.};
    sfSprite_setRotation(new->sprite, 180. / M_PI * get_angle(arr) + 90.);
    get_global_bounds(new);
    new->time_alive = 0;
    new->depart_time = my_getnbr(arr[6]);
    new->is_dead = false;
    new->is_first = false;
    return 0;
}

static int append(my_obj_t **head, my_obj_t *new)
{
    if (*head)
        (*head)->previous = new;
    new->next = *head;
    new->previous = NULL;
    *head = new;
    return 0;
}

int add_plane(my_obj_t **head, char **arr)
{
    my_obj_t *new = malloc(sizeof(my_obj_t));
    static sfTexture *t = NULL;
    static int id = 0;

    id++;
    if (id > 3500) {
        free(new);
        return 0;
    }
    t = sfTexture_createFromFile(paths[0], NULL);
    if (!new || !t)
        return 84;
    new->sprite = sfSprite_create();
    if (!new->sprite)
        return 84;
    sfSprite_setTexture(new->sprite, t, sfTrue);
    if (plane_info(new, arr))
        return 84;
    return append(head, new);
}
