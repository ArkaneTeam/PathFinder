#include "minilib.h"

bool mx_isspace(char c)
{
    if ((c >= 9 && c < 14) || (c == 32))return 1;
    else return 0;
}

bool mx_isdigit(int c)
{
    if (c >= 48 && c < 58)return 1;
    else return 0;
}

int mx_atoi(const char *str)
{
    int i = 0;
    int sum = 0;
    int sign = 1;
    char *s = (char *)str;

    while (mx_isspace(s[i]) == true) i++;

    if (s[i] == '-')
    {
        sign = -1;
        i++;
    }
    if (s[i] == '+')
    {
        sign = 1;
        i++;
    }
    while (mx_isdigit(s[i]) == true)
    {
        sum = sum * 10 + (s[i] - '0');
        i++;
    }

    return sum * sign;
}