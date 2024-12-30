#include "ft_printf.h"

// Função auxiliar para imprimir ponteiros no formato hexadecimal
int ft_putptr_fd(void *ptr, int fd)
{
    unsigned long long addr;
    char *base = "0123456789abcdef";
    int len = 0;

    addr = (unsigned long long)ptr;
    if (!ptr)
    {
        ft_putstr_fd("(nil)", fd);
        return 5; 
    }

    // Imprime o prefixo "0x" apenas uma vez
    ft_putstr_fd("0x", fd);
    len += 2; // Incrementa o comprimento pelo prefixo

    // Imprime o valor hexadecimal do ponteiro
    if (addr >= 16)
        len += ft_putnbr_hex_fd(addr, 'x', fd); 
    {
        ft_putchar_fd(base[addr], fd);
        len++;
    }

    return len;
}

// Função auxiliar para números unsigned
int ft_putnbr_unsigned_fd(unsigned int n, int fd)
{
    int len = 0;

    if (n >= 10)
        len += ft_putnbr_unsigned_fd(n / 10, fd);
    ft_putchar_fd((n % 10) + '0', fd);
    len++;
    return len;
}

// Função auxiliar para números hexadecimais
int ft_putnbr_hex_fd(unsigned int n, char format, int fd)
{
    char *base;
    int len = 0;

    if (format == 'x')
        base = "0123456789abcdef";
    else
        base = "0123456789ABCDEF";

    if (n >= 16)
        len += ft_putnbr_hex_fd(n / 16, format, fd);
    ft_putchar_fd(base[n % 16], fd);
    len++;
    return len;
}

// Processamento de formatos
static int ft_process_format(va_list args, const char format)
{
    int len = 0;

    if (format == 'c')
    {
        ft_putchar_fd((char)va_arg(args, int), 1);
        len++;
    }
    else if (format == 's')
    {
        char *str = va_arg(args, char *);
        if (str)
        {
            len += ft_strlen(str);
            ft_putstr_fd(str, 1);
        }
        else
        {
            ft_putstr_fd("(null)", 1);
            len += 6;
        }
    }
    else if (format == 'd' || format == 'i')
    {
        int num = va_arg(args, int);
        char *num_str = ft_itoa(num);
        len += ft_strlen(num_str);
        ft_putstr_fd(num_str, 1);
        free(num_str);
    }
    else if (format == 'u')
    {
        unsigned int num = va_arg(args, unsigned int);
        len += ft_putnbr_unsigned_fd(num, 1);
    }
    else if (format == 'x' || format == 'X')
    {
        unsigned int num = va_arg(args, unsigned int);
        len += ft_putnbr_hex_fd(num, format, 1);
    }
    else if (format == 'p')
    {
        void *ptr = va_arg(args, void *);
        len += ft_putptr_fd(ptr, 1);
    }
    else if (format == '%')
    {
        ft_putchar_fd('%', 1);
        len++;
    }
    return len;
}

// Função principal ft_printf
int ft_printf(const char *format, ...)
{
    va_list args;
    int i = 0;
    int len = 0;

    va_start(args, format);
    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            len += ft_process_format(args, format[i]);
        }
        else
        {
            ft_putchar_fd(format[i], 1);
            len++;
        }
        i++;
    }
    va_end(args);
    return len;
}

