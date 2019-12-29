#include "libft.h"

void	ft_printerr(const char *fmt, ...)
{
	va_list	ap;

	va_start(ap, fmt);
	ft_vdprintf(2, fmt, ap);
	va_end(ap);
}
