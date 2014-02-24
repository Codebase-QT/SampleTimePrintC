#include <stdio.h>
#include <string.h>
#include <time.h>
#define URL_LOGIN "https://www.google.com"
#include "Sample.h"
int main(void)
{
    char buffer[25];
    timer_t time_in_long;
    struct tm* tm_info;
    time(&time_in_long);
    tm_info = localtime(&time_in_long);

    strftime(buffer, 25, "%Y:%m:%d - %I:%M:%S %p", tm_info);
    puts(buffer);

    return 0;

}

