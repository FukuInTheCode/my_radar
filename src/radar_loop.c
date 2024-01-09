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
    *w = sfRenderWindow_create((sfVideoMode){1920, 1080, 32}, "my_radar",
        sfClose | sfTitlebar, NULL);
    sfSprite_setTexture(bg, sfTexture_createFromFile(paths[2],
        NULL), sfTrue);
    if (!sfSprite_getTexture(bg))
        return 84;
    return 0;
}

int free_txt(sfText *text)
{
    if (!text)
        return 0;
    if (sfText_getFont(text))
        sfFont_destroy((void *)sfText_getFont(text));
    sfText_destroy(text);
    return 0;
}

static int free_all(sfRenderWindow *w, sfClock *clock,
    void **arr, my_obj_t *head)
{
    sfSprite *bg = *arr;

    free_txt(arr[1]);
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

static int inside_loop(my_obj_t **head, sfRenderWindow *w,
    sfText *text, char *fps)
{
    sfText_setString(text, fps);
    sfRenderWindow_drawText(w, text, NULL);
    sfRenderWindow_display(w);
    if (check_end(*head))
        sfRenderWindow_close(w);
    free(fps);
    return 0;
}

sfText *create_text(void)
{
    sfFont *font = sfFont_createFromFile("assets/Delfino.ttf");
    sfText *text = sfText_create();

    if (!text || !font)
        return NULL;
    sfText_setFont(text, font);
    sfText_setFillColor(text, sfRed);
    sfText_setCharacterSize(text, 42);
    sfText_setString(text, "0");
    return text;
}

int reset_clock(sfClock *clock)
{
    sfClock_restart(clock);
    return 0;
}

int game_loop(my_obj_t **head)
{
    sfClock *clock = sfClock_create();
    my_container_t con = {LINEAR, setup_linear, check_linear, NULL};
    sfRenderWindow *w = NULL;
    sfSprite *bg = sfSprite_create();
    my_flags_t flags = {false, true};
    int error = create_all(&w, bg);
    sfText *text = create_text();

    for (double time = 0; !error && sfRenderWindow_isOpen(w);) {
        if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) < 1. / 20.)
            continue;
        sfRenderWindow_clear(w, sfBlack);
        sfRenderWindow_drawSprite(w, bg, NULL);
        do_events_loop(w, &flags, &con) | 1 && draw_plane(w, *head, &flags);
        !draw_tower(w, *head, &flags) && update_plane(w, *head, &con, clock);
        inside_loop(head, w, text, my_put_nbr((int)time)) | reset_clock(clock);
        time += 1. / 20.;
    }
    return error | free_all(w, clock, (void *[2]){CV(bg), CV(text)}, *head);
}
