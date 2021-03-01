/*
** EPITECH PROJECT, 2020
** my
** File description:
** my
*/

#ifndef IMAGE_H_
#define IMAGE_H_

#include <SFML/Graphics.h>

typedef struct image_s
{
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f pos;
    int offset;
    int max_value;
} image_t;

image_t *init_image(char *path, sfIntRect rect, sfVector2f pos, int max_value);

#endif
