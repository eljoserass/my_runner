/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** draw sprites
*/

#include <SFML/Graphics.h>

#include "my_hunter.h"

void draw_obstacles(info *my_info, int *coordinates)
{
    int i = 1;

    while (i <= coordinates[0]) {
        my_info->obstacles->pos.x = coordinates[i];
        sfSprite_setPosition(my_info->obstacles->sprite, my_info->obstacles->pos);
        sfRenderWindow_drawSprite(my_info->window, my_info->obstacles->sprite, NULL);
        coordinates[i] -= my_info->speed; // velocity, can be changed to a macro or inside the struct
        i++;
    }
    my_info->chest->pos.x = coordinates[i + 1] + 40;
    my_info->torch->pos.x = coordinates[i + 1] + 80;
    sfSprite_setPosition(my_info->chest->sprite, my_info->chest->pos);
    sfRenderWindow_drawSprite(my_info->window, my_info->chest->sprite, NULL);
    sfSprite_setPosition(my_info->torch->sprite, my_info->torch->pos);
    sfRenderWindow_drawSprite(my_info->window, my_info->torch->sprite, NULL);
    coordinates[i + 1] -= my_info->speed;
}

int end_game(info *my_info, int *coordinates)
{
    int i = 1;

    while (i != coordinates[0]) {
        if (my_info->shadow_man->pos.x >= coordinates[i])
            return (-1);
        i++;
    }
    if (my_info->shadow_man->pos.x == coordinates[coordinates[0] + 2])
        return (-1);
    return (0);
}

int draw_game(info *my_info, int *coordinates)
{
    sfRenderWindow_drawSprite(my_info->window, my_info->background->sprite, NULL);
    sfRenderWindow_drawSprite(my_info->window, my_info->rocks->sprite, NULL);
    sfRenderWindow_drawSprite(my_info->window, my_info->rocks_two->sprite, NULL);
    sfRenderWindow_drawSprite(my_info->window, my_info->ground->sprite, NULL);
    sfRenderWindow_drawSprite(my_info->window, my_info->ground_two->sprite, NULL);
    sfRenderWindow_drawSprite(my_info->window, my_info->ground_front->sprite, NULL);
    sfRenderWindow_drawSprite(my_info->window, my_info->ground_front_two->sprite, NULL);
    draw_obstacles(my_info, coordinates);
    sfRenderWindow_drawSprite(my_info->window, my_info->shadow_man->sprite, NULL);
    sfRenderWindow_drawText(my_info->window, my_info->score, NULL);
    return (end_game(my_info, coordinates));
}
