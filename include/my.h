/*
** EPITECH PROJECT, 2023
** MY_H
** File description:
** Placeholder
*/

#ifndef MY_H
    #define MY_H
    #define  _GNU_SOURCE
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

    #define GETNBR_CHECK (is_int_stred(str[i]) || is_sign_stred(str[i]))

typedef int(*func)();

typedef enum {
    MENU_ST,
    GAME_ST,
} my_status_t;

typedef struct {
    sfEventType type;
    func f;
} my_evt_t;

typedef struct {
    bool show_hitbox;
    bool show_texture;
} my_flags_t;

typedef struct obj {
    sfSprite *sprite;
    bool is_plane;
    union {
        struct {
            bool is_flying;
            bool is_dead;
            sfVector2f velocity;
            sfVector2f to;
            sfVector2f from;
            uint64_t depart_time;
            double time_alive;
            sfFloatRect bounds;
            bool is_safe;
        };
        struct {
            sfCircleShape *zone;
            struct obj *next_tower;
        };
    };
    struct obj *next;
} my_obj_t;

typedef struct {
    func setup_f;
    func check_f;
    void *data;
} my_container_t;

int get_global_bounds(my_obj_t *);
int my_getnbr(char const *);
size_t my_strlen(char const *);
int my_strncmp(char const *, char const *, int);
int my_strcmp(char const *, char const *);
int open_file(char const *);
int display_usage(void);
int game_loop(my_obj_t *);
int update_plane(sfRenderWindow *, my_obj_t *, my_container_t *, sfClock *);
int draw_plane(sfRenderWindow *, my_obj_t *, my_flags_t *);
int draw_tower(sfRenderWindow *, my_obj_t *, my_flags_t *);
int do_events_loop(sfRenderWindow *, my_flags_t *);
char **my_str_to_word_array(char const *);
char *my_strdup(char const *);
char *my_strcpy(char *, char const *);
int handle_close(sfRenderWindow *);
int add_plane(my_obj_t **, char **);
int add_tower(my_obj_t **, char **);
bool inside_tower(my_obj_t *, sfFloatRect);
int check_linear(my_obj_t *, void *);
int setup_linear(my_obj_t *, my_container_t *);
bool rect_intersect(sfFloatRect, sfFloatRect);

static my_evt_t const my_events[] = {
    {sfEvtClosed, handle_close},
    {sfEvtCount, NULL},
};

static char const *paths[] __attribute__((unused)) =
    {"./assets/plane.png", "./assets/tower.png",
    "./assets/planisphere.jpg"};

static inline __attribute__((unused)) int word_array_len(char **arr)
{
    int i = 0;

    for (; arr[i]; i++);
    return i;
}

#endif
