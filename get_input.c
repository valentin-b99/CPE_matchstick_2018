/*
** EPITECH PROJECT, 2019
** get_input
** File description:
** get_input
*/

#include "include/matchstick.h"

int get_input(all_t *all, char **line, char **matches)
{
    size_t len = 0;

    my_putstr("Line: ");
    if (getline(line, &len, stdin) == -1)
        return (-1);
    if (error_line(all, line))
        return (0);
    my_putstr("Matches: ");
    if (getline(matches, &len, stdin) == -1)
        return (-1);
    if (error_matches(all, line, matches))
        return (0);
    return (1);
}