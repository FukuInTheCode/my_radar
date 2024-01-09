/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"

static sfRectangleShape *create_rect(void)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setOutlineColor(rect, sfGreen);
    sfRectangleShape_setOutlineThickness(rect, 2);
    sfRectangleShape_setScale(rect, (sfVector2f){1, 1});
    sfRectangleShape_setSize(rect, (sfVector2f){20., 20.});
    sfRectangleShape_setFillColor(rect, sfTransparent);
    return rect;
}

int draw_plane(sfRenderWindow *w, my_obj_t *head, my_flags_t *flags)
{
    sfRectangleShape *rect = NULL;

    for (rect = create_rect(); head; head = head->next) {
        if (!head->is_plane || !head->is_flying || head->is_dead)
            continue;
        if (flags->show_texture)
            sfRenderWindow_drawSprite(w, head->sprite, NULL);
        if (flags->show_hitbox) {
            sfRectangleShape_setPosition(rect,
                sfSprite_getPosition(head->sprite));
            sfRectangleShape_setRotation(rect,
                sfSprite_getRotation(head->sprite));
            sfRenderWindow_drawRectangleShape(w, rect, NULL);
        }
    }
    sfRectangleShape_destroy(rect);
    return 0;
}
