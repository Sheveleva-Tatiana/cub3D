/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshera <sshera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:51:52 by sshera            #+#    #+#             */
/*   Updated: 2021/10/20 17:37:25 by sshera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

int		ft_atoi(const char *str);
void	*ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
void	*ft_memchr(const void *s1, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *destination, const void *source, size_t n);
void	*ft_memmove(void *d, const void *source, size_t n);
void	*ft_memset(void *dst, int c, size_t len);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int nb, int fd);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strchr(const char *str, int ch);
char	*ft_strdup(const char *src);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(char const *s);
int		ft_strncmp(const char *s1, const char *s2, size_t len);
char	*ft_strnstr(const char *str, const char *s, size_t n);
char	*ft_strrchr(const char *str, int ch);
int		ft_tolower(int c);
int		ft_toupper(int c);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_substr(char const *str, unsigned int s, size_t l);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif