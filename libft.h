/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 15:25:42 by mwunsch           #+#    #+#             */
/*   Updated: 2019/02/14 20:08:45 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <wchar.h>
# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

# define CONV_A format[i] != 'c' && format[i] != 's' && format[i] != 'p'
# define CONV_B format[i] != 'd' && format[i] != 'i' && format[i] != 'o'
# define CONV_C format[i] != 'u' && format[i] != 'x' && format[i] != 'X'
# define CONV_D format[i] != 'C' && format[i] != 'S' && format[i] != 'U'
# define CONV_E format[i] != 'f' && format[i] != 'D' && format[i] != 'b'
# define CONV_F format[i] != 'O' && format[i] != 'F'

# define IF_NOT_CONV (CONV_A && CONV_B && CONV_C && CONV_D && CONV_E && CONV_F)

# define F_A format[i] == 'j' || format[i] == 'h' || format[i] == 'l'
# define F_B format[i] == 'L' || format[i] == '#'
# define F_C ft_isdigit(format[i]) || format[i] == '-'
# define F_D format[i] == '+' || format[i] == '.'
# define F_E format[i] == ' ' || format[i] == '*' || format[i] == '\''
# define F_F format[i] == 'n' || format[i] == 'z'
# define FLAG_G_A format[i] == 'c' && format[i + 1] == 'a'
# define FLAG_G_B format[i + 2] == 's' && format[i + 3] == 'e'
# define FLAG_G_C format[i + 4] == ':'
# define FLAG_H_A format[i] == 'f' && format[i + 1] == 'i'
# define FLAG_H_B format[i + 2] == 'l' && format[i + 3] == 'e'
# define FLAG_I_A format[i] == 'c' && format[i + 1] == 'o'
# define FLAG_I_B format[i + 2] == 'l' && format[i + 3] == 'o'
# define FLAG_I_C format[i + 4] == 'r'

# define F_G (FLAG_G_A && FLAG_G_B && FLAG_G_C)

# define F_H (FLAG_H_A && FLAG_H_B)

# define F_I (FLAG_I_A && FLAG_I_B && FLAG_I_C)

# define IS_FLAG (F_A || F_B || F_C || F_D || F_E || F_F || F_G || F_H || F_I)

typedef struct	s_flags_ft_printf
{
	int				sharp;
	int				zero;
	int				minus;
	int				plus;
	int				space;
	int				grouping;
	int				width;
	int				precision;
	char			length[3];
}				t_flags;

typedef struct	s_flags_global_ft_printf
{
	char			*dest_str;
	int				dest_file;
	int				up_low_case;
	int				add_color;
	char			color[10];
	int				counter;
}				t_flags_global;

int				ft_printf(const char *restrict format, ...);
void			ft_conversion_di(char **output, va_list ap);
void			ft_conversion_di_tool_grouping(char **str);
void			ft_conversion_di_tool_precision(char **str);
void			ft_conversion_di_tool_width(char **str);
void			ft_conversion_c(char **output, int i);
void			ft_conversion_lc(char **output, wint_t i);
void			ft_conversion_s(char **output, const char *str);
void			ft_conversion_ls(char **output, const int *src);
void			ft_conversion_p(char **output, void *p);
int				ft_conversion_oux(char **output, char type, va_list ap);
char			*ft_conversion_oux_tool_getstr(char type, uintmax_t i);
void			ft_conversion_f(char **output, va_list ap);
void			ft_conversion_f_tool_getstr(char **str, double i);
void			ft_conversion_lf(char **output, va_list ap);
void			ft_conversion_lf_tool_getstr(char **str, long double i);
int				ft_flag_adder(const char *chr, va_list ap);
int				ft_flag_adder_tool_five(const char *chr, va_list ap);
void			ft_flag_clear(void);
void			ft_flag_global_clear(void);
void			ft_flag_correcter(void);

extern t_flags			g_flags;
extern t_flags_global	g_flags_global;

char			*ft_decimal_converter(const char *baze, uintmax_t n);
char			*ft_strupcase(char *str);
char			*ft_strlowcase(char *str);
char			*ft_uitoa(uintmax_t n);
int				ft_ustrlen(const int *c);
int				ft_ucharlen(const int c);
char			*ft_strcat_free(char **dst, char **src);
int				ft_strchr_index(const char *s, int c);

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

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
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
int				ft_putchar(int c);
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
int				ft_delimcount(char const *s, char c);
int				ft_wordcount(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(intmax_t n);
int				ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
char			**ft_arrdel(char ***arr);
int				ft_putchar_fd(int c, int fd);
int				ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdelprintcont(void *p, size_t d);
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstaddlast(t_list **alst, void const *content,
		size_t content_size);
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void			ft_lstputstr(t_list *elem);
t_list			*ft_lstcpy(t_list *elem);
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int				get_next_line(const int fd, char **line);
char			**ft_matrix(size_t size1, size_t size2, char c);
void			ft_matrix_print(char **matrix, size_t size);
void			*ft_matrix_del(char **matrix, int size);

#endif
