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
    my_container_t con = {LINEAR, setup_linear, check_linear, NULL};
    sfRenderWindow *w = NULL;
    sfSprite *bg = sfSprite_create();
    my_flags_t flags = {true, true};

    sfClock_restart(clock);
    for (error |= create_all(&w, bg); !error && sfRenderWindow_isOpen(w);) {
        sfRenderWindow_clear(w, sfBlack);
        sfRenderWindow_drawSprite(w, bg, NULL);
        do_events_loop(w, &flags);
        draw_plane(w, head, &flags);
        draw_tower(w, head, &flags);
        update_plane(w, head, &con, clock);
        int i = 0;
        for (my_obj_t *tmp = head; tmp; tmp = tmp->next)
            i++;
        sfRenderWindow_display(w);
    }
    return error;
}
