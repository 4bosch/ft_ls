/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 17:52:34 by abosch            #+#    #+#             */
/*   Updated: 2019/05/10 15:55:31 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>

/*
*LIBC FUNCTIONS
*/
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *haystack, const char *needle,
				size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
long long		ft_atoll(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
/*
*NONLIBC FUNCTIONS
*/
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char*));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
char			*ft_strmap(const char *s, char (*f)(char));
char			*ft_strmapi(const char *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(const char *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char					*ft_strjoin_free(char const *s1, char const *s2,
											char c);
char			*ft_strjoin_free_d(char const *s1, char const *s2, char d);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(int n);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
/*
*ADDITIONNAL FUNCTIONS
*/
int				ft_isblank(int c);
int				ft_isspace(int c);
/*
*GET_NEXT_LINE
*/
# define OPEN_MAX 10240
# define BUF_SIZE 32
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "libft.h"

int get_next_line(const int fd, char **line);
/*
*PRINTF
*/
# include <stdint.h>
# include <wchar.h>
int				ft_abs(intmax_t *n);
size_t			ft_count_digits(intmax_t n, uint8_t base);
void			ft_getnbr_base(size_t value, uint8_t base, char *str, size_t *index);
int				ft_isprint(int c);
char			*ft_llitoa(int64_t n);
char			*ft_llitoa_base(int64_t value, uint8_t base);
char			*ft_llitosa_base(int64_t value, int8_t base, char *tab);
char			*ft_lluitoa(uint64_t n);
char			*ft_lluitoa_base(uint64_t value, uint8_t base);
char			*ft_lluitosa_base(size_t value, int8_t base, char *tab);
char			*ft_make_printable(char *str);
void			ft_puterr(const char *s, int fd);
void			ft_utfecut(char *str, size_t len);
size_t			ft_utfecut_index(char *str, size_t len);
char			*ft_wchar_utfe(wchar_t c);
int8_t			ft_wchar_utfelen(wchar_t c);
size_t			ft_count_udigits(size_t n, uint8_t base);
char			*ft_wstr_utfe(wchar_t *str);
size_t			ft_wstr_utfelen(wchar_t *str);
int8_t			ft_strmatch(char *match, char *str);
size_t			ft_wstrlen(wchar_t *str);

int				ft_printf(const char *restrict fmt, ...);
void			ft_printerr(const char *fmt, ...);

typedef struct			s_string
{
	char				*str;
	int					len;
}						t_string;

#endif
