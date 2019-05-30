/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 14:41:48 by olaktion          #+#    #+#             */
/*   Updated: 2018/01/04 15:09:31 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <sys/types.h>

# include <stdint.h>
# include <string.h>
# define UNUSED(x) (void)(x)
# define FALSE 0
# define TRUE !FALSE

typedef int				t_bool;
typedef unsigned char	t_byte;
typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);

char				*ft_strtrim(char const *s);
char				*ft_strsub(char const *s, unsigned int star, size_t len);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strdup(char *s);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_stpcpy(char *s1, const char *s2);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *str, int n);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *hay, const char *ned, size_t n);
char				*ft_strmap(char *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strjoin(char const *s1, char const *s2);
char				**ft_strsplit(char const *str, char x);
char				*ft_strnew(size_t size);
char				*ft_strupcase(char *str);
char				*ft_itoa(intmax_t n);

void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char*));
void				ft_striteri(char *s, void (*f)(unsigned int, char*));

size_t				ft_strlen(const char *str);
size_t				ft_strnlen(const char *s, size_t maxlen);
size_t				ft_strlcat(char *dest, const char *src, size_t destsize);

void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				*ft_memset(void *str, int val, size_t n);
void				*ft_memcpy(void *str1, const void *str2, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t len);
void				*ft_memchr(const void *str, int c, size_t n);
int					ft_memcmp(const void *m1, const void *m2, size_t n);

int					ft_atoi(const char *s);
int					ft_isalpha(int n);
int					ft_isdigit(int n);
int					ft_isalnum(int n);
int					ft_isascii(int n);
int					ft_isprint(int n);
int					ft_toupper(int n);
int					ft_tolower(int n);
int					ft_abs(int c);
int					ft_fact(int n);
int					ft_cntchr(char k, char const *str);
int					ft_sq(int n);

void				*ft_bzero(void *str, size_t num);
void				ft_swap(int *a, int *b);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putchar(char c);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

t_bool				ft_isupper(int c);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *lst);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));

#endif
