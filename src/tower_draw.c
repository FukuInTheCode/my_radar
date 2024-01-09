/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"

int draw_tower(sfRenderWindow *w, my_obj_t *head, my_flags_t *flags)
{
    for (; head; head = head->next) {
        if (head->is_plane)
            continue;
        if (flags->show_texture)
            sfRenderWindow_drawSprite(w, head->sprite, NULL);
        if (flags->show_hitbox) {
            sfRenderWindow_drawCircleShape(w, head->zone, NULL);
        }
    }
    return 0;
}
