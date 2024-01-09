/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"

int do_events_loop(sfRenderWindow *w, my_obj_t *head, void **tree)
{
    for (sfEvent evt; sfRenderWindow_pollEvent(w, &evt);)
        for (int i = 0; my_events[i].f; i++)
            (my_events[i].type == evt.type) && my_events[i].f(w, head, tree);
    return 0;
}
