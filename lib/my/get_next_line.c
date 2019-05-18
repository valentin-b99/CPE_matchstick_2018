/*
** EPITECH PROJECT, 2018
** get_next_line
** File description:
** get_next_line
*/

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != 0) {
        i = i + 1;
    }
    return (i);
}

char *my_strncat(char *dest, char const *src, int nb)
{
    int dest_len = my_strlen(dest);
    char *tmp = malloc(sizeof(char) * (my_strlen(dest) + 1));

    if (tmp == NULL)
        return (NULL);
    for (int i = 0; dest[i] != 0; i++)
        tmp[i] = dest[i];
    tmp[dest_len] = 0;
    if ((dest = malloc(sizeof(char) * (dest_len + my_strlen(src) + 1))) == NULL)
        return (NULL);
    for (int i = 0; tmp[i] != 0; i++)
        dest[i] = tmp[i];
    for (int i = 0; src[i] != 0 && i < nb; i++)
        dest[dest_len + i] = src[i];
    dest[dest_len + my_strlen(src)] = 0;
    return (dest);
}

int my_charsearch(char *str, char c)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == c)
            return (1);
    return (0);
}

int read_line(int fd, char **str, int *i_buffer)
{
    char *buffer = malloc(sizeof(char) * (READ_SIZE + 1));
    int len = 0;

    if (buffer == NULL)
        return (84);
    while ((len = read(fd, buffer , READ_SIZE)) > 0) {
        buffer[len] = '\0';
        if ((*str = my_strncat(*str, buffer, my_strlen(buffer))) == NULL)
            return (84);
        if (fd == 0 && my_charsearch(*str, '\n'))
            fd = -1;
    }
    *str = *str + *i_buffer;
    if (fd != -1) {
        *i_buffer = 0;
        if ((*str)[*i_buffer] == '\n')
            *i_buffer = 1;
    }
    while ((*str)[*i_buffer] != '\n' && (*str)[*i_buffer])
        *i_buffer += 1;
    return (0);
}

char *get_next_line(int fd)
{
    static int i_buffer = 0;
    static char *str = "";
    char *result = "";

    if (fd == -1)
        return (NULL);
    if (fd == 0) {
        str = "";
        i_buffer = 0;
    }
    if (read_line(fd, &str, &i_buffer) == 84 ||
        (result = malloc(sizeof(char) * (i_buffer + 1))) == NULL)
        return (NULL);
    result = "";
    if ((result = my_strncat(result, str, i_buffer)) == NULL)
        return (NULL);
    i_buffer++;
    if (result[0] == 0)
        return (NULL);
    return (result);
}