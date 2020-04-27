#include "pathfind.h"
#include "minilib.h"

/**
 * raise_error - Функция вызывает ошибку по id
 * @param err_id - ID ошибки
 *
 */
void raise_error(enum e_error err_id)
{
    /* Variable Definitions */
    char *err_msg;

    switch (err_id)
    {
        case USAGE_ERROR:
            err_msg = "usage: ./race04 [file_name] [x1] [y1] [x2] [y2]\n";
            write(2, err_msg, 48);
            exit(USAGE_ERROR);

        case MAP_NOT_EXIST:
            err_msg = "map does not exist\n";
            write(2, err_msg, 19);
            exit(MAP_NOT_EXIST);

        case MAP_ERROR:
            err_msg = "map error\n";
            write(2, err_msg, 10);
            exit(MAP_ERROR);

        case POINT_OUT_RANGE:
            err_msg = "points are out of map range\n";
            write(2, err_msg, 28);
            exit(POINT_OUT_RANGE);

        case POINT_IS_OBSTACLE:
            err_msg = "entry point cannot be an obstacle\n";
            write(2, err_msg, 34);
            exit(POINT_IS_OBSTACLE);

        case EXIT_IS_OBSTACLE:
            err_msg = "exit point cannot be an obstacle\n";
            write(2, err_msg, 33);
            exit(EXIT_IS_OBSTACLE);

        case ROUT_NOT_FOUND:
            err_msg = "route not found\n";
            write(2, err_msg, 16);
            exit(ROUT_NOT_FOUND);

        case ERROR:
            err_msg = "error\n";
            write(2, err_msg, 6);
            exit(ERROR);

        default:
            break;
    }
}

