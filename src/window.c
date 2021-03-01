/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** window managment file
*/

#include <SFML/Graphics.h>
#include "my_hunter.h"

sfRenderWindow *open_window(int width, int height, char *name)
{
    sfRenderWindow *window;
    sfVideoMode video_mode;

    video_mode.width = width;
    video_mode.height = height;
    video_mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(video_mode, name, sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(window, 30);
    return (window);
}