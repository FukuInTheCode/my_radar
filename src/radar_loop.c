/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"

static int create_window(sfRenderWindow **w)
{
    *w = sfRenderWindow_create((sfVideoMode){1920, 1080, 32}, "9/11",
        sfClose | sfTitlebar, NULL);
    return 0;
}

int game_loop(my_plane_t *head)
{
    int error = 0;
    sfClock *clock = sfClock_create();
    void *tree = NULL;
    sfRenderWindow *w = NULL;

    sfClock_restart(clock);
    for (create_window(&w); sfRenderWindow_isOpen(w);) {
        sfRenderWindow_clear(w, sfBlack);
        do_events_loop(w, head, &tree);
        update_plane(w, head, tree);
        draw_plane(w, head);
        sfRenderWindow_display(w);
    }
    return error;
}
