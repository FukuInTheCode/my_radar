/*
** EPITECH PROJECT, 2024
** handle_key.c
** File description:
** handle_key.c
*/

#include "my.h"

int handle_key(sfRenderWindow *w, sfEvent evt, my_flags_t *flags,
    my_container_t *con)
{
    if (evt.key.code == sfKeyEscape)
        sfRenderWindow_close(w);
    if (evt.key.code == sfKeyS)
        flags->show_texture = !flags->show_texture;
    if (evt.key.code == sfKeyL)
        flags->show_hitbox = !flags->show_hitbox;
    return 0;
}
