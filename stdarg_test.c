#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Header for variable numbers of arguments */
// man stdarg
#include <stdarg.h>

int ft_flags(const char format)
{
    printf("FT_FLAGS: %c\n", format);
    return(0);
}

int ft_printf(const char *format, ...)
{
    va_list args;
    long int i;
    char buff[2000];
    
    i = 0;
    va_start(args, format);
    while(*format)
    {
        //
        while (*format && *format != '%')
        {
            buff[i] = *format;
            format++;
            i++;
        }
        format++;
        ft_flags(*format);
        format++;
    }
    va_end(args);
    return(0);
}

int main()
{
	char *pin;

   ft_printf("123 Hi lady %s\n\0", "pin");
    //printf(" 123 Hi lady %z\n", "pin");
    return(0);
}
