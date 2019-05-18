/*
** EPITECH PROJECT, 2019
** player_turn
** File description:
** player_turn
*/

#include "include/matchstick.h"

int player_turn(all_t *all)
{
    int state = 0;
    char *line = NULL;
    char *matches = NULL;

    my_putstr("\nYour turn:\n");
    while (state == 0) {
        state = get_input(all, &line, &matches);
        if (state == -1)
            return (0);
    }
    display_matches_rem_on_line(1, my_getnbr(matches), my_getnbr(line));
    remove_sticks(all, my_getnbr(line), my_getnbr(matches));
    return (1);
}