/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 18:03:51 by lucdubos          #+#    #+#             */
/*   Updated: 2018/09/17 15:32:51 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

int				ft_first_sqrt(int nb);
int				ft_iterative_power(int nb, int power);
int				ft_sqrt(int nb);
void			ft_swap(int *a, int *b);
void			ft_sort_integer_table(int *tab, int size);
void			ft_is_negative(int n);
void			ft_print_params(int argc, char **argv);
char			**ft_strsplit(char const *s, char c);
char			*ft_strrev(char *str);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
int				ft_strcmp(const char *s1, const char *s2);
size_t			ft_strlen(const char *str);
void			ft_putnbr(int n);
int				ft_atoi(const char *str);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dest, const char *src, size_t n);
int				ft_strncmp(char const *s1, char const *s2, size_t n);
char			*ft_strstr(const char *str, const char *to_find);
char			*ft_strcat(char *dest, char const *src);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
void			ft_strclr(char *s);
char			*ft_strdup(char const *str);
char			*ft_strndup(const char *str, int k);
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
void			ft_striter(char *s, void (*f)(char *));
void			*ft_memset(void *s, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			ft_putendl(char const *s);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s);
char			*ft_itoa(intmax_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnstr(const char *str, const char *to_find, size_t len);
char			*ft_strjoin0(char const *s1, char const *s2);
char			*ft_strjoin1(char const *s1, char const *s2);
char			*ft_strjoin2(char const *s1, char const *s2);
char			*ft_strjoin3(char const *s1, char const *s2);
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
char			*ft_itoa_base(intmax_t value, intmax_t base);
char			*ft_majtomin(char *str);
int				char_in_str(char *str, char c);
int				ft_worth_zero(char *str);
char			*ft_uitoa_base(uintmax_t nb, uintmax_t base);
char			*ft_stockwchar(wchar_t wc);
char			*ft_stockwstr(wchar_t *wstr);
char			*ft_char_to_str(char c);
char			*ft_putmaj(char *str);

#endif
