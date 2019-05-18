/*
** EPITECH PROJECT, 2019
** remove_sticks
** File description:
** remove_sticks
*/

#include "include/matchstick.h"

void remove_sticks(all_t *all, int line, int sticks)
{
    int sticks_rem = 0;
    int counter = all->max_width;

    all->line_sticks[line - 1] -= sticks;
    while (all->tray[line][counter] == ' ')
        counter--;
    while (sticks_rem < sticks) {
        all->tray[line][counter] = ' ';
        counter--;
        sticks_rem++;
    }
}