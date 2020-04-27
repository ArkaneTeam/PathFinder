#ifndef RACE04_MINILIB_H
#define RACE04_MINILIB_H

/* Includes */
#include <stdio.h> // TODO Delete this
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>
#include <unistd.h>

/* Enums */
enum e_error
{
    USAGE_ERROR,
    MAP_NOT_EXIST,
    MAP_ERROR,
    POINT_OUT_RANGE,
    POINT_IS_OBSTACLE,
    EXIT_IS_OBSTACLE,
    ROUT_NOT_FOUND,
    ERROR
};

/* Prototypes */
void raise_error(enum e_error err_id);
int mx_atoi(const char *str);

#endif // RACE04_MINILIB_H
