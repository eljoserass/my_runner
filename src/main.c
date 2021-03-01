/*
** EPITECH PROJECT, 2020
** main
** File description:
** MAIN
*/

#include <SFML/Graphics.h>
#include "my_hunter.h"

void print_usage(void)
{
    my_putstr("USAGE\n");
    my_putstr("\t./my_runner map\n\t(the map has to be an executable).\n\n");
    my_putstr("\tBUGS\n");
    my_putstr("\t\tSometimes it doesnt start the game at the first try\n");
    my_putstr("\tMAP(IMPORTANT)\n");
    my_putstr("\t\tput the obstacles in the sixth line\n");
    my_putstr("\t\t'o' for obstacles\n\t\t'|' for the end\n\t\tg for ground\n");
    my_putstr("\t\tyou have to put it two 'o' after the '|'\n");
    my_putstr("\t\t(please do it how its said, if not you will break it jeje).\n");
    my_putstr("\n\t\tEXAMPLE MAP\n");
    my_putstr("\t\t                      o         |           oo\n");
    my_putstr("\t\tggggggggggggggggggggggggggggggggggggggggggggggg\n\n");
    my_putstr("USER INTERACTIONS\n");
    my_putstr("\tSPACE BAR for jumping");
    my_putstr("\n\tSuper + M for full screen mode (recommended)");
    my_putstr("\n\tYou can turn up or down the volume normally.");
    my_putstr("\nHISTORY");
    my_putstr("\t\n Just a cozzy vibe game :)");
    my_putstr("\n\n\nsong: G-Eazy - 'Free Porn, Cheap Drugs'");
}

int my_strcmp(char *one, char *two)
{
    int i = 0;

    while (one[i] != '\0') {
        if (one[i] != two[i])
            return (0);
        else
            i++;
    }
    return (1);
}

int check_arguments(int ac, char **av)
{
    if ((ac == 2) && (my_strcmp("-h", av[1]) == 1)) {
        print_usage();
        return (0);
    }
    if ((ac > 2) || ac < 2) {
        my_putstr("-h for usage\n");
        return (84);
    }
    return (-1);
}

int main(int ac, char **av)
{
    int output = check_arguments(ac, av);

    if (output == 0 || output == 84)
        return (output);
    return (my_do_game_loop(av[1]));
}