/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** macro for the all the functions of the game
*/

#ifndef MY_HUNTER_H_
#define MY_HUNTER_H_

#include <SFML/Graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>

#include "render_info.h"
#include "image.h"

sfRenderWindow *open_window(int width, int height, char *name);
void move_rect(sfIntRect *rect, int offset, int max_value);
void my_handle_event(info *my_info);
int draw_game(info *my_info, int *coordinates);
void refresh_game(info *my_info);
int my_do_game_loop(char *file);
void my_kill_duck(info *my_info);
void reset_position(info *my_info);
int calculate_random_num(int min, int max);
void my_putstr(char const *str);
void my_putchar(char c);
int my_put_nbr(int nb);

char *my_open_n_read_file(char const *file, struct stat *info);

void move_rect(sfIntRect *rect, int offset, int max_value);

#endif /* !MY_HUNTER_H_ */
