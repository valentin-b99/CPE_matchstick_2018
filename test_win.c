/*
** EPITECH PROJECT, 2019
** test_win
** File description:
** test_win
*/

#include "include/matchstick.h"

int test_win(all_t *all, int player)
{
    for (int i = 0; i < all->max_line; i++)
        if (all->line_sticks[i] > 0)
            return (0);
    if (player)
        my_putstr("You lost, too bad...\n");
    else
        my_putstr("I lost... snif... but I'll get you next time!!\n");
    return (1);
}