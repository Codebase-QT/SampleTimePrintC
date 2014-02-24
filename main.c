#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>

int kbhit (void)
{
  struct timeval tv;
  fd_set rdfs;

  tv.tv_sec = 0;
  tv.tv_usec = 0;

  FD_ZERO(&rdfs);
  FD_SET (STDIN_FILENO, &rdfs);

  select(STDIN_FILENO+1, &rdfs, NULL, NULL, &tv);
  return FD_ISSET(STDIN_FILENO, &rdfs);

}
int main(void)
{

    char buffer[25],c;
    timer_t time_in_long;
    struct tm* tm_info;
    time(&time_in_long);
    tm_info = localtime(&time_in_long);

    while(!kbhit())
    {
//        system("clear");
        sleep(1);
        time(&time_in_long);
        tm_info = localtime(&time_in_long);
        strftime(buffer, 25, "%Y:%m:%d - %I:%M:%S %p", tm_info);
        puts(buffer);



    }
    return 0;

}



/*
%a	Abbreviated weekday name *											   Thu
%A	Full weekday name *												 Thursday
%b	Abbreviated month name *												 Aug
%B	Full month name *													 August
%c	Date and time representation *					  Thu Aug 23 14:55:02 2001
%d	Day of the month (01-31)												  23
%H	Hour in 24h format (00-23)												  14
%I	Hour in 12h format (01-12)												  02
%j	Day of the year (001-366)												 235
%m	Month as a decimal number (01-12)										  08
%M	Minute (00-59)															  55
%p	AM or PM designation													  PM
%S	Second (00-61)															  02
%U	Week number with the first Sunday as the first day of week one (00-53)	  33
%w	Weekday as a decimal number with Sunday as 0 (0-6)						  4
%W	Week number with the first Monday as the first day of week one (00-53)	  34
%x	Date representation *												08/23/01
%X	Time representation *												14:55:02
%y	Year, last two digits (00-99)											  01
%Y	Year																	2001
%Z	Timezone name or abbreviation											 CDT
%%	A % sign

    * The above specifiers whose description is marked
      with an asterisk (*) are locale-dependent.

    See ... (ref.)
    http://www.cplusplus.com/reference/clibrary/ctime/strftime.html

    Or ... (me)
    http://www.geocities.com/dwzavitz/
    http://securejoules.googlepages.com/
    http://developers-heaven.net/forum/index.php/topic,46.0.html

*/



