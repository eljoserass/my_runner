/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** in this file, the game loop lives
*/

#include <SFML/Graphics.h>
#include <stdio.h>

#include "my_hunter.h"

int count_obstacles(char *map)
{
    int i = 0;
    int o = 0;
    while (map[i] != '\0') {
        if (map[i] == 'o')
            o++;
        i++;
    }
    return (o);
}

int *get_coordinates(char *map)
{
    int i = 0;
    int o = 1;
    int size = count_obstacles(map);
    int x = 0;
    int *obstacles = malloc(sizeof(int) * size + 2); // + 1 for the size that will be in 0 // add the cordinates of the finishing line +1 for the pipe

    if (!obstacles)
        return (NULL);
    obstacles[0] = size;
    while (map[i] != '\0') {
        if (map[i] == ' ' || map[i] == 'o')
            x += 16;
        if (map[i] == 'o') {
            obstacles[o] = x;
            o++;
            i++;
        }
        if (map[i] == '|') {
            obstacles[size + 2] = x;
            o++;
        }
        i++;
    }
    return (obstacles);
}

void destroy_everything(info *my_info)
{
    sfTexture_destroy(my_info->background->texture);
    sfTexture_destroy(my_info->rocks->texture);
    sfTexture_destroy(my_info->ground_front->texture);
    sfTexture_destroy(my_info->rocks_two->texture);
    sfTexture_destroy(my_info->ground_two->texture);
    sfTexture_destroy(my_info->ground_front_two->texture);
    sfTexture_destroy(my_info->obstacles->texture);
    sfTexture_destroy(my_info->shadow_man->texture);
    sfRenderWindow_destroy(my_info->window);
    sfMusic_destroy(my_info->f_p_c_d);
}

void put_music(info *my_info, float volume)
{
    sfMusic_setLoop(my_info->f_p_c_d, sfTrue);
    sfMusic_setVolume(my_info->f_p_c_d, volume);
    sfMusic_play(my_info->f_p_c_d);
}


int my_do_game_loop(char *file)
{
    info *my_info = NULL;
    struct stat *stat = NULL;
    char *map = NULL;
    int *coordinates = NULL;
    my_info = my_init_struct();

    if (my_info == NULL)
        return (84);
    stat = malloc(sizeof(struct stat));
    if (!stat)
        return (84); 
    map = my_open_n_read_file(file, stat);
    if (!map)
        return (84);
    coordinates = get_coordinates(map);
    if (!coordinates)
        return (84);
    put_music(my_info, 10);
    while (sfRenderWindow_isOpen(my_info->window)) {
        sfRenderWindow_clear(my_info->window, sfBlack);
        my_handle_event(my_info);
        refresh_game(my_info);
        if (draw_game(my_info, coordinates) == -1)
            sfRenderWindow_close(my_info->window);
        sfRenderWindow_display(my_info->window);
    }
    destroy_everything(my_info);
    return (0);
}