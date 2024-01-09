/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"

int draw_plane(sfRenderWindow *w, my_obj_t *head)
{
    for (; head; head = head->next) {
        if (head->is_plane && !head->is_flying)
            continue;
        sfRenderWindow_drawSprite(w, head->sprite, NULL);
    }
    return 0;
}
