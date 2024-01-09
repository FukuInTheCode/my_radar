/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"

static int create_all(sfRenderWindow **w, sfSprite *bg)
{
    *w = sfRenderWindow_create((sfVideoMode){1920, 1080, 32}, "9/11",
        sfClose | sfTitlebar, NULL);
    sfSprite_setTexture(bg, sfTexture_createFromFile(paths[2],
        NULL), sfTrue);
    if (!sfSprite_getTexture(bg))
        return 84;
    return 0;
}

int game_loop(my_obj_t *head)
{
    int error = 0;
    sfClock *clock = sfClock_create();
    void *tree = NULL;
    sfRenderWindow *w = NULL;
    sfSprite *bg = sfSprite_create();

    sfClock_restart(clock);
    for (error |= create_all(&w, bg); !error && sfRenderWindow_isOpen(w);) {
        sfRenderWindow_clear(w, sfBlack);
        sfRenderWindow_drawSprite(w, bg, NULL);
        do_events_loop(w, head, &tree);
        update_plane(w, head, tree, clock);
        draw_plane(w, head);
        sfRenderWindow_display(w);
    }
    return error;
}
