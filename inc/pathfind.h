#ifndef RACE04_PATHFIND_H
#define RACE04_PATHFIND_H

/* Structures */
typedef struct s_map
{
    char **a;
}              t_map;

/* Prototypes */
void PathFinder(char *fn, char *x1, char *y1, char *x2, char *y2);

#endif // RACE04_PATHFIND_H
