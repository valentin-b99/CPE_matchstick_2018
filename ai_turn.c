/*
** EPITECH PROJECT, 2019
** ai_turn
** File description:
** ai_turn
*/

#include "include/matchstick.h"

int remaining_lines(all_t *all)
{
    int nb_remaining_lines = 0;

    for (int i = 0; i < all->max_line; i++)
        if (all->line_sticks[i] > 0)
            nb_remaining_lines++;
    return (nb_remaining_lines);
}

void find_remain_lines(all_t *all, int *line_1, int *line_2)
{
    int i_l = 0;

    for (int i = 0; i < all->max_line; i++) {
        if (all->line_sticks[i] > 0 && !i_l) {
            *line_1 = i;
            i_l++;
        } else if (all->line_sticks[i] > 0 && i_l) {
            *line_2 = i;
        }
    }
}

void rem_line(all_t *all, int line)
{
    if (all->line_sticks[line] <= all->max_stick) {
        display_matches_rem_on_line(0, all->line_sticks[line] - 1, line + 1);
        remove_sticks(all, line + 1, all->line_sticks[line] - 1);
    } else if (all->line_sticks[line] == all->max_stick + 1) {
        display_matches_rem_on_line(0, all->max_stick, line + 1);
        remove_sticks(all, line + 1, all->max_stick);
    } else {
        display_matches_rem_on_line(0, 1, line + 1);
        remove_sticks(all, line + 1, 1);
    }
}

void ai_intelligence(all_t *all)
{
    int line_1;
    int line_2;

    find_remain_lines(all, &line_1, &line_2);
    if (all->line_sticks[line_1] > 1) {
        rem_line(all, line_1);
    } else if (all->line_sticks[line_2] > 1) {
        rem_line(all, line_2);
    } else {
        if (all->line_sticks[line_1] > 0) {
            display_matches_rem_on_line(0, all->line_sticks[line_1], line_1
            + 1);
            remove_sticks(all, line_1 + 1, all->line_sticks[line_1]);
        } else if (all->line_sticks[line_2] > 0) {
            display_matches_rem_on_line(0, all->line_sticks[line_2], line_2
            + 1);
            remove_sticks(all, line_2 + 1, all->line_sticks[line_2]);
        }
    }
}

void ai_turn(all_t *all)
{
    int i_line = 1;

    my_putstr("\nAI's turn...\n");
    while (all->line_sticks[i_line - 1] == 0)
        i_line++;
    if (remaining_lines(all) > 2) {
        if (all->line_sticks[i_line - 1] <= all->max_stick) {
            display_matches_rem_on_line(0, all->line_sticks[i_line - 1],
            i_line);
            remove_sticks(all, i_line, all->line_sticks[i_line - 1]);
        } else {
            display_matches_rem_on_line(0, all->max_stick, i_line);
            remove_sticks(all, i_line, all->max_stick);
        }
    } else {
        ai_intelligence(all);
    }
}