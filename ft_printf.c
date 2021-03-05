#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"
#include "ft_strchr.c"
#include "ft_isdigit.c"
#include "ft_putchar.c"

int				put_width(int width, int len, int zero)
{
	int			rnt;

	rnt = 0;
	while (++len < width)
	{
		if (zero == 1)
			ft_putchar('0');
		else 
			ft_putchar(' ');
		rnt++;
	}
}

int				printf_char(int c, t_info *info)
{
	int			rnt;

	rnt = 0;
	if (info->type == '%' && info->minus == 1)
		info->zero = 0;
	if (info->minus == 1)
		rnt += ft_putchar(c);
	rnt += put_width(info->width, 0, info->zero);
	if (info->minus == 0)
		rnt += ft_putchar(c);
	return (rnt);
}



int				put_type(va_list ap, t_info *info)
{
	int			rnt;
	int			va_int;
	char		type;

	if (type == 'd' || type == 'i')
		rnt = print_nbr(va_arg(ap, int), info);
	else if (type == '%')
		rnt = printf_char('%', info);
	else if (type == 'c')
		rnt = printf_char(va_arg(ap, int), info);
	else if (type == 's')
		rnt = printf_string(va_arg(ap, char *), info);
	else if (type == 'x' || type == 'X' || type == 'u')
		rnt = printf_nbr(va_arg(ap, unsigned int), info);
	else if (type == 'p')
		rnt = printf_nbr(va_arg(ap, unsigned long long), info);

}

void			fill_isdigit_wid_pre(va_list ap, char *format, t_info *info, int i)
{
	if (info->precis == -1)
		info->width = info->width * 10 + format[i] - 48;
	else
	{
		info->precis = info->precis * 10 + format[i] - 48;
	}
}

void			fill_star_wid_pre(va_list ap, char *format, t_info *info, int i)
{
	if(info->precis == -1)
	{
		info->width = va_arg(ap, int);
		if (info->width < 0)
		{
			info->minus = 1;
			info->width *=-1;
		}
	}
	else
	{
		info->precis = va_arg(ap, int);
	}
}

void			fill_info(va_list ap, t_info *info, char *format, int i)
{
	if (format[i] == '0' && info->precis == -1 && info->width == 0)
		info->zero = 1;
	else if (format[i] == '-')
		info->minus = 1;
	else if (format[i] == '.')
		info->precis = 0;
	else if (ft_isdigit(format[i]))
		fill_isdigit_wid_pre(ap, format, info, i);
	else if (format[i] == '*')
		fill_star_wid_pre(ap, format, info, i);
}


void			put_info(t_info *info)
{
	info->zero = 0;
	info->minus = 0;
	info->width = 0;
	info->precis = -1;
	info->type = 0;
	info->nbr_base = 10;
}

int				what_is_this(va_list ap, char *format)
{
	int			i;
	int			rnt;
	t_info		*info;

	i = 0;
	rnt = 0;
	if (!(info = malloc(sizeof(t_info) * 1)))
		return (-1);
	while (format[i] != '\0')
	{
		while (format[i] != '\0' && format[i] != '%')
			{
				rnt += ft_puchar(format[i]);
				i++;
			}
		if (format[i] == '%')
		{
			put_info(info);
			while(format[++i] != '\0' && !(ft_strchr("csdiupxX%%", format[i])))
				fill_info(ap, info, format, i);
			info->type = format[i];
			i++;
			if((info->minus == 1 ||info->type != '%' ||info->precis > -1))
				info->zero = 0;
			rnt += put_type(ap, info);
		}
	}
}

int 	        ft_printf(const char *format, ...)
{
	int			rnt;
	va_list		ap;

	va_start(ap, format);
	va_end(ap);
	return (rnt);
}
