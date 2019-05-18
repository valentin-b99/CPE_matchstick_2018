/*
** EPITECH PROJECT, 2019
** errors
** File description:
** errors
*/

#include "include/matchstick.h"

int errors(int ac, char **av)
{
    if (ac != 3) {
        my_putstr("Bad arguments: ");
        my_putnbr(ac - 1);
        my_putstr(" given but 2 is required\n");
        return (1);
    }
    if (!my_str_isnum(av[1]) || !my_str_isnum(av[2])) {
        my_putstr("Bad arguments: They must be numbers\n");
        return (1);
    }
    if (my_getnbr(av[1]) < 1 || my_getnbr(av[1]) > 99) {
        my_putstr("Bad arguments: The game board must be between 1 and 99\n");
        return (1);
    }
    if (my_getnbr(av[2]) < 1) {
        my_putstr("Bad args: The number of matches must be greater than 1\n");
        return (1);
    }
    return (0);
}

int error_line(all_t *all, char **line)
{
    if (!my_str_isnum(*line)) {
        my_putstr("Error: invalid input (positive number expected)\n");
        return (1);
    }
    if (my_getnbr(*line) < 1 || my_getnbr(*line) > all->max_line) {
        my_putstr("Error: this line is out of range\n");
        return (1);
    }
    return (0);
}

int error_matches(all_t *all, char **line, char **matches)
{
    if (!my_str_isnum(*matches)) {
        my_putstr("Error: invalid input (positive number expected)\n");
        return (1);
    }
    if (my_getnbr(*matches) < 1) {
        my_putstr("Error: you have to remove at least one match\n");
        return (1);
    }
    if (my_getnbr(*matches) > all->max_stick) {
        my_putstr("Error: you cannot remove more than ");
        my_putnbr(all->max_stick);
        my_putstr(" matches per turn\n");
        return (1);
    }
    if (my_getnbr(*matches) > all->line_sticks[my_getnbr(*line) - 1]) {
        my_putstr("Error: not enough matches on this line\n");
        return (1);
    }
    return (0);
}