/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"
#include <SFML/Graphics/Types.h>

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

static int free_all(sfRenderWindow *w, sfClock *clock,
    sfSprite *bg, my_obj_t *head)
{
    if (w)
        sfRenderWindow_destroy(w);
    if (bg && sfSprite_getTexture(bg))
        sfTexture_destroy((void *)sfSprite_getTexture(bg));
    if (bg)
        sfSprite_destroy(bg);
    if (clock)
        sfClock_destroy(clock);
    head->is_first = false;
    for (; head; head = head->next) {
        if (head->is_plane)
            remove_plane(head);
        if (!head->is_plane)
            remove_tower(head);
    }
    return 0;
}

static bool check_end(my_obj_t *head)
{
    bool has_plane_first = head->is_plane && head->is_dead;
    int i = 0;

    for (; head; head = head->next)
        i += head->is_plane;
    i -= has_plane_first;
    if (i == 0)
        return true;
    return false;
}

int game_loop(my_obj_t **head, size_t elasped)
{
    sfClock *clock = sfClock_create();
    my_container_t con = {LINEAR, setup_linear, check_linear, NULL};
    sfRenderWindow *w = NULL;
    sfSprite *bg = sfSprite_create();
    my_flags_t flags = {false, true};
    int error = create_all(&w, bg);

    for (sfClock *c = sfClock_create(); !error && sfRenderWindow_isOpen(w);) {
        sfRenderWindow_clear(w, sfBlack);
        sfRenderWindow_drawSprite(w, bg, NULL);
        do_events_loop(w, &flags, &con) | 1 && draw_plane(w, *head, &flags);
        !draw_tower(w, *head, &flags) && update_plane(w, *head, &con, clock);
        sfRenderWindow_display(w);
        if (check_end(*head))
            sfRenderWindow_close(w);
    }
    return error | free_all(w, clock, bg, *head);
}
