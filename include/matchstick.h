/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** matchstick
*/

#ifndef MATCHSTICK_H_
#define MATCHSTICK_H_

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

typedef struct all_s
{
    char **tray;
    int *line_sticks;
    int max_stick;
    int max_line;
    int max_width;
} all_t;

/**
*? ai_turn.c
**/
int remaining_lines(all_t *);
void find_remain_lines(all_t *, int *, int *);
void rem_line(all_t *, int);
void ai_intelligence(all_t *);
void ai_turn(all_t *);

/**
*? display_tray_rem_line.c
**/
void display_tray(all_t *);
void display_matches_rem_on_line(int, int, int);

/**
*? errors.c
**/
int errors(int, char **);
int error_line(all_t *, char **);
int error_matches(all_t *, char **, char **);

/**
*? get_input.c
**/
int get_input(all_t *, char **, char **);

/**
*? init_fill_tray.c
**/
void init_tray(char ***, int, int);
void fill_line_stars(char ***, int, int);
void fill_sticks(char ***, int, int);
void fill_tray(int, all_t *);
void fill_nb_sticks(int, int **);

/**
*? main.c
**/
int matchstick(all_t *);

/**
*? player_turn.c
**/
int player_turn(all_t *);

/**
*? remove_sticks.c
**/
void remove_sticks(all_t *, int, int);

/**
*? test_win.c
**/
int test_win(all_t *, int);

#endif /* !MATCHSTICK_H_ */
