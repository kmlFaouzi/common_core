/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaouzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 19:45:10 by kfaouzi           #+#    #+#             */
/*   Updated: 2021/11/07 14:43:23 by kfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include<stdlib.h>
# include<unistd.h>

/**
 * checks  for  an  alphabetic character;
 * it is equivalent to (isupper(c) || islower(c)).
 *
 * @return int (1/0)
 */
int		ft_isalpha(int c);

/**
 * checks for a digit (0 through 9).
 *
 *@return int (1/0)
 */
int		ft_isdigit(int c);

/**
 * checks for an alphanumeric character;
 * it is equivalent to (isalpha(c) || isdigit(c)).
 *
 * @return int (1/0)
 */
int		ft_isalnum(int c);

/**
 * checks whether c is a 7-bit unsigned char value
 * that fits into the ASCII character set.
 *
 *@return int (1/0)
 */
int		ft_isascii(int c);

/**
 * checks for any printable character including space.
 *
 * @return int (1/0)
 */
int		ft_isprint(int c);

/**
 * calculates the length of the string pointed to by s,
 * excluding the terminating null byte ('\0')
 *
 * @return int (0/1)
 */
size_t	ft_strlen(const char *str);

/**
 * copies up to (size - 1) characters from the NUL-terminated string src to dst,
 * NUL-terminating the result.
 *
 * @return int
 */
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

/**
 *appends the NUL-terminated string src to the end of dst.
 *it will append at most size - strlen(dst) - 1 bytes,
 * NUL-terminating the result.
 *
 * @return int
 */
size_t	ft_strlcat(char *dst, const char *src, size_t size);

/**
 * @brief converts lowercase letters to uppercase, and vice versa
 *
 * @param c
 * @return int
 */
int		ft_toupper(int c);

/**
 * @brief converts uppercase letters to lowercase
 *
 * @param c
 * @return int
 */
int		ft_tolower(int c);

/**
 *  Allocates (with malloc(3)) and returns a substring
 *  from the string ’s’ .
 *  The substring begins at index ’start’ and is of
 *  maximum size ’len’ .
 *
 * @return char*
 */
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_stpncpy(char *dst, const char *src, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
int		ft_atoi(const char *str);
void	*calloc(size_t count, size_t size);
char	*strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
/*
   typedef struct s_list
   {
   void *content;
   struct s_list *next;
   }t_list;

   t_list *ft_lstnew(void *);
   void ft_lstadd_front(t_list **, t_list *);
   int ft_lstsize(t_list *);
   t_list *ft_lstlast(t_list *);
   void ft_lstadd_back(t_list **, t_list *);
   void ft_lstdelone(t_list *, void (*del)(void*));
   */

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}		t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **alst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
