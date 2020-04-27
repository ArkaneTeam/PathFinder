#include "minilib.h"
#include "pathfind.h"

int main(int argc, char *argv[]) {

    /* Check args on usage */
    if (argc != 6)
        raise_error(USAGE_ERROR);

    PathFinder(argv[1], argv[2], argv[3], argv[4], argv[5]);

    return 0;
}
