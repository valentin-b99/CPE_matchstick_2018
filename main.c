/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include "include/matchstick.h"

int matchstick(all_t *all)
{
    display_tray(all);
    while (1) {
        if (!player_turn(all))
            return (0);
        display_tray(all);
        if (test_win(all, 1))
            return (2);
        ai_turn(all);
        display_tray(all);
        if (test_win(all, 0))
            return (1);
    }
}

int main(int ac, char **av)
{
    all_t *all = malloc(sizeof(all_t));

    if (errors(ac, av))
        return (84);
    all->max_stick = my_getnbr(av[2]);
    all->max_line = my_getnbr(av[1]);
    fill_tray(my_getnbr(av[1]), all);
    fill_nb_sticks(my_getnbr(av[1]), &all->line_sticks);
    return (matchstick(all));
}