/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zphakath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 11:19:18 by zphakath          #+#    #+#             */
/*   Updated: 2018/01/10 15:40:04 by zphakath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# define BUFF_SIZE 16

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

size_t				ft_strlen(const char *str);
char				*ft_strcpy(char	*dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t len);
int					ft_strcmp(const char *str1, const char *str2);
int					ft_strncmp(const char *str1, const char *str2, size_t n);
int					get_next_line(const int fd, char **line);
int					ft_isalpha(int chr);
int					ft_isdigit(int chr);
int					ft_isalnum(int chr);
int					ft_isascii(int chr);
int					ft_isprint(int chr);
int					ft_toupper(int chr);
int					ft_tolower(int chr);
void				ft_putchar(char c);
char				*ft_strdup(char const *s1);
char				*ft_strcat(char	*s1, const char *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *src, int c);
char				*ft_strnstr(const char *bigi, const char *lit, size_t len);
char				*ft_strstr(const char *str, const char *to_find);
void				ft_putnbr(int n);
void				ft_putstr(char const *s);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(void const *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				ft_bzero(void *s, size_t n);
char				*ft_itoa(int n);
char				*ft_strncat(char *s1, const char *s2, size_t n);
void				ft_strdel(char **as);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putendl(char const *s);
int					ft_atoi(const char *s);
char				*ft_strjoin(char const *s1, char const *s2);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **p);
char				*ft_strnew(size_t size);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char	const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_strrchr(const char *src, int c);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del) (void *, size_t));
void				ft_lstdel(t_list **alst, void (*del) (void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f) (t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem));

#endif
