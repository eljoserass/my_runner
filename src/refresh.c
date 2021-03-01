/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** all the functon to refresh
*/

#include <SFML/Graphics.h>
#include "my_hunter.h"

/*
void draw_cursor(info *my_info)
{
    sfRenderWindow_setMouseCursorVisible(my_info->window, sfFalse);
    move_rect(&my_info->mouse->rect, my_info->mouse->offset, my_info->mouse->max_value);
    sfSprite_setTextureRect(my_info->mouse->sprite, my_info->mouse->rect);
    my_info->mouse->pos.x = my_info->vector.x;
    my_info->mouse->pos.y = my_info->vector.y;
    sfSprite_setPosition(my_info->mouse->sprite, my_info->mouse->pos);
}
*/

int calculate_random_num(int min, int max)
{
    int r_num = rand() % (max + 1 - min) + min;

    return (r_num);
}

void check_positions(info *my_info)
{
    if (my_info->rocks_two->pos.x <= 0) {
        my_info->rocks_two->pos.x = 480;
        my_info->rocks->pos.x = 0;
    }
    if (my_info->ground_two->pos.x <= 0) {
        my_info->ground_two->pos.x = 480;
        my_info->ground->pos.x = 0;
    }
    if (my_info->ground_front_two->pos.x == 0) {
        my_info->ground_front_two->pos.x = 480;
        my_info->ground_front->pos.x = 0;
    }
}

void move_map(info *my_info)
{
    check_positions(my_info);
    my_info->rocks->pos.x -= 2;
    my_info->rocks_two->pos.x -= 2;
    my_info->ground->pos.x -= 4;
    my_info->ground_two->pos.x -= 4;
    my_info->ground_front->pos.x -= 6;
    my_info->ground_front_two->pos.x -= 6;
}

void put_map(info *my_info)
{
    sfSprite_setPosition(my_info->background->sprite, my_info->background->pos);
    sfSprite_setPosition(my_info->rocks->sprite, my_info->rocks->pos);
    sfSprite_setPosition(my_info->ground->sprite, my_info->ground->pos);
    sfSprite_setPosition(my_info->ground_front->sprite, my_info->ground_front->pos);
        //
    sfSprite_setPosition(my_info->rocks_two->sprite, my_info->rocks_two->pos);
    sfSprite_setPosition(my_info->ground_two->sprite, my_info->ground_two->pos);
    sfSprite_setPosition(my_info->ground_front_two->sprite, my_info->ground_front_two->pos);
}

void put_player(info *my_info)
{
    move_rect(&my_info->shadow_man->rect, my_info->shadow_man->rect.width, my_info->shadow_man->max_value);
    sfSprite_setTextureRect(my_info->shadow_man->sprite, my_info->shadow_man->rect);
    sfSprite_setPosition(my_info->shadow_man->sprite, my_info->shadow_man->pos);
    //missig fixing the jump // add hitbox // have the end when reach the end or when it dies //
    my_info->shadow_man->pos.y = 170;
}

void get_score(info *my_info)
{
    int i = 5;
    int tmp = my_info->points;

    while (i >= 0) {
        if (tmp != 0) {
            my_info->str[i] = (tmp % 10) + 48;
            tmp = tmp / 10;
        } else
            my_info->str[i] = '0';
        i--;
    }
}

void put_score(info *my_info)
{
    my_info->points += 1;
    get_score(my_info);
    sfText_setString(my_info->score, my_info->str);
}

void refresh_game(info *my_info)
{
    my_info->time = sfClock_getElapsedTime(my_info->clock);
    my_info->seconds = my_info->time.microseconds / 1000000.0;
    if (my_info->seconds > 0.1) {
        put_map(my_info);
        put_player(my_info);
        move_map(my_info);
        put_score(my_info);
        sfClock_restart(my_info->clock);
    }
}

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    rect->left += offset;
    if (rect->left >= max_value)
        rect->left = 0;
}