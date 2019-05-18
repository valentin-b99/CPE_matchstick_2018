/*
** EPITECH PROJECT, 2019
** display_tray_rem_line
** File description:
** display_tray_rem_line
*/

#include "include/matchstick.h"

void display_tray(all_t *all)
{
    for (int i = 0; i <= all->max_line + 1; i++) {
        my_putstr(all->tray[i]);
        my_putstr("\n");
    }
}

void display_matches_rem_on_line(int player, int matches, int line)
{
    if (player)
        my_putstr("Player removed ");
    else
        my_putstr("AI removed ");
    my_putnbr(matches);
    my_putstr(" match(es) from line ");
    my_putnbr(line);
    my_putstr("\n");
}