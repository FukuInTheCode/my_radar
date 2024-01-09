/*
** EPITECH PROJECT, 2023
** MY_H
** File description:
** Placeholder
*/

#ifndef MY_H
    #define MY_H
    #include <SFML/Window/Event.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <stdint.h>
    #include <time.h>
    #include <limits.h>
    #include <stdarg.h>
    #include <errno.h>
    #include <fcntl.h>
    #include <math.h>
    #include <stdlib.h>
    #include <sys/stat.h>

    #include <criterion/criterion.h>
    #include <criterion/redirect.h>

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/Config.h>
    #include <SFML/GPUPreference.h>
    #include <SFML/Network.h>
    #include <SFML/OpenGL.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>


typedef int(*func)();

typedef enum {
    MENU_ST,
    GAME_ST,
} my_status_t;

typedef struct {
    sfEventType type;
    func f;
} my_evt_t;

typedef struct plane {
    sfSprite *sprite;
    bool is_flying;
    struct plane *next;
} my_plane_t;

size_t my_strlen(char const *);
int my_strncmp(char const *, char const *, int);
int open_file(char const *);
int display_usage(void);
int game_loop(sfRenderWindow *, my_plane_t *);

static my_evt_t const my_events[] = {
//    {sfEvtClosed, handle_close},
//    {sfEvtKeyPressed, handle_close}
    {sfEvtCount, NULL},
};

static char const *paths[] __attribute__((unused)) =
    {"./assets/plane.png", "./assets/tower.png",
    "./assets/planisphere.jpg"};

#endif
