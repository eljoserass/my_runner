/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** struct to save information of all the game
*/

#ifndef RENDER_INFO_H_
#define RENDER_INFO_H_

#include "image.h"
#include <SFML/Graphics.h>
#include <SFML/Audio.h>

typedef struct render_info
{
    sfRenderWindow *window;
    sfEvent event;
    sfVector2f pos_click;
    sfClock *clock;
    sfTime time;
    float seconds;
    image_t *background;
    image_t *rocks;
    image_t *ground;
    image_t *ground_front;
    image_t *rocks_two;
    image_t *ground_two;
    image_t *ground_front_two;
    image_t *obstacles;
    image_t *shadow_man;
    image_t *chest;
    image_t *torch;
    sfMusic *f_p_c_d;
    sfText *score;
    int points;
    int speed;
    int amount_obstacles;

    sfVector2i vector;
    char *str;
    int killed;
} info;

info *my_init_struct(void);

#endif /* !RENDER_INFO_H_ */
