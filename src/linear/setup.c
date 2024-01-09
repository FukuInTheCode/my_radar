/*
** EPITECH PROJECT, 2024
** setup.c
** File description:
** setup.c
*/

#include "my.h"

int setup_linear(my_obj_t *head, my_container_t *con)
{
    con->data = (void *)head;
    return 0;
}
