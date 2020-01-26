
#include "libft.h"

char	*ft_strjoin_free(char const *s1, char const *s2, char c)
{
	char	*res;

	if ((res = ft_strjoin(s1, s2)) == NULL)
		return (NULL);
	if (c == 'b')
	{
		ft_strdel((char**)&s1);
		ft_strdel((char**)&s2);
	}
	else if (c == 'l')
		ft_strdel((char**)&s1);
	else if (c == 'r')
		ft_strdel((char**)&s2);
	return ((char*)res);
}
