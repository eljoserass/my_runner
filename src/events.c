/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** functions related to handling events
*/

#include <SFML/Graphics.h>
#include "my_hunter.h"

void do_jump(info *my_info)
{
    my_info->shadow_man->pos.y = 120;
   // move_rect(&my_info->shadow_man->rect, my_info->shadow_man->rect.width, my_info->shadow_man->max_value);
   // sfSprite_setTextureRect(my_info->shadow_man->sprite, my_info->shadow_man->rect);
   // sfSprite_setPosition(my_info->shadow_man->sprite, my_info->shadow_man->pos);
   //////fix the jump
   ////// add ex
}

void my_handle_event(info *my_info)
{
    while (sfRenderWindow_pollEvent(my_info->window, &my_info->event)) {
        if (my_info->event.type == sfEvtClosed || my_info->event.key.code == sfKeyEscape)
                sfRenderWindow_close(my_info->window);
        if (my_info->event.key.code == sfKeySpace)
            //just i f the status its in the ground, this status will change when the character reach the top and its going down
            do_jump(my_info);
    }
}