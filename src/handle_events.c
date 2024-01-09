/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"

int do_events_loop(sfRenderWindow *w, my_flags_t *flags, my_container_t *con)
{
    for (sfEvent evt; sfRenderWindow_pollEvent(w, &evt);)
        for (int i = 0; my_events[i].f; i++)
            (my_events[i].type == evt.type) && my_events[i].f(w, evt,
                flags, con);
    return 0;
}
