/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** initialize structure
*/

#include "my_hunter.h"

sfText *init_text(sfText *var, char *file, sfColor color ,sfVector2f pos)
{   
    sfFont *font = sfFont_createFromFile(file);

    var = sfText_create();
    //sfText_setString(var, "hola");
    sfText_setColor(var, color);
    sfText_setFont(var, font);
    sfText_setPosition(var, pos);

    return (var);
}

info *my_init_struct(void)
{
    info *my_info = malloc(sizeof(info));
    
    if (my_info == NULL)
        return (NULL);

    my_info->window = open_window(480, 240, "madafreakingame");
    my_info->clock = sfClock_create();
    my_info->time = sfClock_getElapsedTime(my_info->clock);
    my_info->background = init_image("pink_purple/background.png", 
    (sfIntRect){0 , 0, 480, 240}, (sfVector2f){0, 0}, 480);
    my_info->rocks = init_image("pink_purple/rocks.png",
    (sfIntRect){0, 0, 480, 240}, (sfVector2f){0, 0}, 480);
    my_info->ground = init_image("pink_purple/ground.png",
    (sfIntRect){0, 0, 480, 240}, (sfVector2f){0, 0}, 480);
    my_info->ground_front = init_image("pink_purple/ground_front.png",
    (sfIntRect){0, 0, 480, 240}, (sfVector2f){0, 0}, 480);
    my_info->rocks_two = init_image("pink_purple/rocks.png",
    (sfIntRect){0, 0, 480, 240}, (sfVector2f){480, 0}, 480);
    my_info->ground_two = init_image("pink_purple/ground.png",
    (sfIntRect){0, 0, 480, 240}, (sfVector2f){480, 0}, 480);
    my_info->ground_front_two = init_image("pink_purple/ground_front.png",
    (sfIntRect){0, 0, 480, 240}, (sfVector2f){480, 0}, 480);
    my_info->obstacles = init_image("sprites/Background/rock.png",
    (sfIntRect){0, 0, 16, 28}, (sfVector2f){480, 200}, 16);
    my_info->shadow_man = init_image("sprites/Enemies/shadowman.png",
    (sfIntRect){0, 0, 64, 64}, (sfVector2f){0, 200}, 896);
    my_info->chest = init_image("sprites/Background/chest.png",
    (sfIntRect){0, 0, 14, 9}, (sfVector2f){480, 217}, 14);
    my_info->torch = init_image("sprites/Background/torch.png",
    (sfIntRect){0, 0, 6, 18}, (sfVector2f){500, 210}, 6);
    my_info->f_p_c_d = sfMusic_createFromFile("music/G-Eazy-Free-Porn_-Cheap-Drugs-_Official-Music-Video_.ogg");
    my_info->score = init_text(my_info->score,"fonts/typ_bold.ttf", sfWhite, (sfVector2f){0, 0});
    my_info->points = 0;
    my_info->speed = 6;
    my_info->str = malloc(sizeof(char) * 15 + 1);
    my_info->str[15] = '\0';
    if (!my_info->background || !my_info->rocks || 
    !my_info->ground || !my_info->ground_front ||
    !my_info->rocks_two || !my_info->ground_two || 
    !my_info->ground_front_two || !my_info->obstacles
    || !my_info->shadow_man || !my_info->torch 
    || !my_info->chest || !my_info->str)
        return (NULL);
    return (my_info);
}

image_t *init_image(char *path, sfIntRect rect, sfVector2f pos, int max_value)
{
    image_t *image = malloc(sizeof(image_t));
    
    if (image == NULL)
        return (NULL);

    image->texture = sfTexture_createFromFile(path, NULL);
    image->sprite = sfSprite_create();
    sfSprite_setTextureRect(image->sprite, image->rect);
    sfSprite_setTexture(image->sprite, image->texture, sfTrue);
    image->rect = rect;
    image->pos = pos;
    image->offset = rect.width;
    image->max_value = max_value;
    return (image);
}