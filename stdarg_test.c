# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>


int bisearch(int val, char *array, size_t min, size_t max)
{
    if ( max < min ) return -1;
    size_t midpoint = ( min + max ) / 2;  
    if ( (int)array[midpoint] > val ) return bisearch(val, array, min, midpoint - 1 );
    if ( (int)array[midpoint] < val ) return bisearch(val, array, midpoint + 1, max);
    if ( val == (int)array[midpoint] ) return midpoint;
    return -1;
}

char *ft_s(va_list args)
{
	char *a;

	printf("PPP %s\n", (va_arg(args, char *)));
	return(va_arg(args, char *));
}

int ft_flags(const char format)
{
    printf("FT_FLAGS: %c\n", format);
    char *array = "%AEFGXabcdefgiknoprsux\0";
    return bisearch(format, array, 0, 20);
}

int ft_printf(const char *format, ...)
{
    va_list args;
    long int i;
    char buff[2000];
	void *flgs_f[21];
	char (*vint)(va_list) = &ft_s;
	// void (*s_ptr)(int) = &ft_s; 
	
    i = 0;
    va_start(args, format);
	flgs_f[18] = vint;
    while (*format)
    {
        while (*format && *format != '%')
        {
            buff[i] = *format;
            format++;
            i++;
        }
        if (*format == '%')
        {
            format++;
			buff[i] = (*vint)(args);
            //buff[i] = flgs_f[ft_flags(*format)];
			i++;
        }
        format++;
    }
    va_end(args);
    printf("------------------\n");
    printf("rez: %s\n", buff);
    printf("------------------\n");
    return(0);
}

int main()
{
	char *pin;

   ft_printf("123 Hi lady %%s\n\0", "p");
    //printf(" 123 Hi lady %z\n", "pin");
    return(0);
}
