/*
** EPITECH PROJECT, 2019
** init_fill_tray
** File description:
** init_fill_tray
*/

#include "include/matchstick.h"

void init_tray(char ***tray, int nb_line, int width)
{
    *tray = malloc(sizeof(char *) * nb_line + 2);
    for (int i = 0; i < nb_line + 2; i++)
        (*tray)[i] = malloc(sizeof(char) * (width + 2));
    for (int i = 0; i < nb_line + 1; i++)
        for (int j = 0; j < width + 2; j++)
            (*tray)[i][j] = 0;
}

void fill_line_stars(char ***tray, int width, int line)
{
    for (int i = 0; i < width + 2; i++)
        (*tray)[line][i] = '*';
}

void fill_sticks(char ***tray, int nb_line, int width)
{
    int stick_print = 1;

    for (int i = 1; i <= nb_line; i++) {
        (*tray)[i][0] = '*';
        (*tray)[i][width + 1] = '*';
        for (int j = 0; j < (width - stick_print) / 2; j++)
            (*tray)[i][j + 1] = ' ';
        for (int j = (width - stick_print) / 2;
            j < (width - stick_print) / 2 + stick_print; j++)
            (*tray)[i][j + 1] = '|';
        for (int j = ((width - stick_print) / 2) + stick_print;
            j < width; j++)
            (*tray)[i][j + 1] = ' ';
        stick_print += 2;
    }
}

void fill_tray(int nb_line, all_t *all)
{
    all->max_width = 1;

    for (int i = 1; i < nb_line; i++)
        all->max_width += 2;
    init_tray(&all->tray, nb_line, all->max_width);
    fill_line_stars(&all->tray, all->max_width, 0);
    fill_line_stars(&all->tray, all->max_width, nb_line + 1);
    fill_sticks(&all->tray, nb_line, all->max_width);
}

void fill_nb_sticks(int nb_line, int **nb_sticks)
{
    int stick_print = 1;

    *nb_sticks = malloc(sizeof(int) * nb_line);
    for (int i = 0; i < nb_line; i++) {
        (*nb_sticks)[i] = stick_print;
        stick_print += 2;
    }
}