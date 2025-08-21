#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

static size_t ft_strlen(const char *s)
{
    size_t i = 0;
    while (s && s[i])
        i++;
    return i;
}

static int ft_putchar(char c)
{
    return write(1, &c, 1);
}

static int ft_putstr(char *s)
{
    if (!s)
        return write(1, "(null)", 6);
    return write(1, s, ft_strlen(s));
}

static int ft_putnbr(long n)
{
    char buf[12];
    int i = 0;
    int count = 0;

    if (n == 0)
        return write(1, "0", 1);
    if (n < 0)
    {
        count += write(1, "-", 1);
        n = -n;
    }
    while (n > 0)
    {
        buf[i++] = '0' + (n % 10);
        n /= 10;
    }
    while (i--)
        count += write(1, &buf[i], 1);
    return count;
}

int ft_printf(const char *fmt, ...)
{
    va_list ap;
    int i = 0;
    int count = 0;

    va_start(ap, fmt);
    while (fmt[i])
    {
        if (fmt[i] == '%' && fmt[i + 1])
        {
            i++;
            if (fmt[i] == 's')
                count += ft_putstr(va_arg(ap, char *));
            else if (fmt[i] == 'c')
                count += ft_putchar((char)va_arg(ap, int));
            else if (fmt[i] == 'd' || fmt[i] == 'i')
                count += ft_putnbr((long)va_arg(ap, int));
            else if (fmt[i] == '%')
                count += write(1, "%", 1);
        }
        else
            count += write(1, &fmt[i], 1);
        i++;
    }
    va_end(ap);
    return count;
}
