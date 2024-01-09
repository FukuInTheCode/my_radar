/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"

int game_loop(sfRenderWindow *w, my_plane_t *head)
{
    int error = 0;
    static sfClock clock = sfClock_create();
    void *tree = NULL;

    for (; sfRenderWindow_isOpen(w);) {
        sfRenderWindow_clear(w, sfBlack);
        do_events_loop(w, head);
        plane_update(w, head);
        sfRenderWindow_display(w);
    }
    return error;
}
