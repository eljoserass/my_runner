/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** funcitons for putting obstacles
*/

#include "my_hunter.h"

char *my_open_n_read_file(char const *file, struct stat *info)
{
    int fd = open(file, O_RDONLY);
    char *map = NULL;

    if (fd == -1 || stat(file, info) == -1)
        return (NULL);
    if (((map = malloc(info->st_size + 1)) == NULL) ||
    (read(fd, map, info->st_size) == -1))
        return (NULL);
    close(fd);
    map[info->st_size] = '\0';
    return (map);
}