#include "pathfind.h"
#include "minilib.h"

/**
 * Function -- open file if file doesn't exits raise error MAP_NOT_EXISTS
 * @param fn File Path or File Name
 * @return File descriptor
 */
int open_file(char *fn)
{
    int file = open(fn, O_RDONLY);

    if (file == -1)
        raise_error(MAP_NOT_EXIST);

    return file;
}

/**
 * Function Check char on correction
 * @param c Char to check
 * @return bool or raise error
 */
bool check_char(char c)
{
    char possible_chars[3] = {'.', ',', '#'};

    for (int i = 0; *possible_chars; i++)

        if (c == possible_chars[i])
            return true;

    raise_error(MAP_ERROR);
    return false;
}

/**
 * Function validate points
 * @param fn
 */
void check_point_out_of_range(int map_width, int map_len, char *c, char  *r)
{
    if (map_width <= mx_atoi(c) || map_len <= mx_atoi(r))
        raise_error(POINT_OUT_RANGE);
}

/**
 * Functions Checks all input data
 * @param fn File Name or File Path
 * @param c1 Entry Column
 * @param r1 Entry Row
 * @param c2 Exit Column
 * @param r2 Exit Row
 * @return 2D array representing map
 */
char **main_check(char *fn, char *c1, char *r1, char *c2, char *r2)
{
    /* Variable Definitions */
    int temp = 0;
    int columns = 0, temp_width = 0;
    int rows = 0;
    int file = open_file(fn);
    char s[1];

    /* Validate array */
    while (read(file, &s, 1))

        if (!(check_char(s[0])))
            raise_error(MAP_ERROR);

        else if (*s == ',')
            continue;

        else if (*s == '\n')
        {
            if (columns != temp_width && temp == 1)
                raise_error(MAP_ERROR);

            temp = 1, rows++, temp_width = 0;
        }

        else if (temp == 0)
            columns++;

        else
            temp_width++;

    /* Points Checks */
    check_point_out_of_range(columns, rows, c1, r1);
    check_point_out_of_range(columns, rows, c2, r2);

    // TODO Free that memory
    char **map = malloc(rows * sizeof(char *));

    for(int i = 0; i < rows + 1; i++)
        map[i] = malloc(columns * sizeof(char));

    close(file); // TODO Possible Error Check

    /* Try to split into two functions */

    /* Make Map Array */
    file = open_file(fn);
    rows = 0;
    columns = 0;

    while (read(file, &s, 1))

        if (*s == ',')
            continue;

        else if (columns == temp_width)
            rows++, columns = 0;

        else
            map[rows][columns] = *s, columns++;

    /* Check If Point is on obstacle */
    if (map[atoi(c1)][atoi(r1)] == '#')
        raise_error(POINT_IS_OBSTACLE);

    else if(map[atoi(c2)][atoi(r2)] == '#')
        raise_error(EXIT_IS_OBSTACLE);

    return map;
}

/**
 * Main function handel all logic
 * @param fn File Name or File Path
 * @param c1 Entry point Column ↓
 * @param r1 Entry point Row →
 * @param c2 Exit point Column ↓
 * @param r2 Exit point Row →
 */
void PathFinder(char *fn, char *r1, char *c1, char *r2, char *c2)
{
    /* Variable Definitions */
    char **map = main_check(fn, c1, r1, c2, r2);  // 2D array representing map without ','

}
