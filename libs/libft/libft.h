/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakeshi <rtakeshi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 12:08:20 by rtakeshi          #+#    #+#             */
/*   Updated: 2021/11/06 17:24:38 by rtakeshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFFER_SIZE 42

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>
# include <stdint.h>
# include <stdarg.h>
# include <fcntl.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

void		*ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memccpy(void *dst, const void *src, int c, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
size_t		ft_strlen(const char*s);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_atoi(const char *str);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);
void		*ft_calloc(size_t count, size_t size);
char		*ft_strdup(const char *s1);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
size_t		ft_ptrlen(uintptr_t number);
char		*ft_reverthex(char *hex);
char		*ft_itohex(char c, unsigned int n);
char		*ft_ptrtohex(uintptr_t n);
char		*ft_utoa(unsigned int n);
int			ft_nlen(long long number);
size_t		ft_unlen(unsigned int number);
void		ft_putnchar_fd(char c, int n, int fd);
void		ft_putnstr_fd(char *s, int size, int fd);
size_t		ft_hexlen(unsigned int number);
size_t		ft_strcat(char *dst, const char *src);

/*ft_printf struct and functions*/
typedef struct s_option
{
	int		minus;
	int		zero;
	int		width;
	int		dot;
	int		precision;
	int		hash;
	int		space;
	int		plus;
	char	type;
	size_t	str_len;
	int		negative;
	int		option_offset;
}	t_option;

int			ft_printf(const char *format, ...);
void		init_struct(t_option *str);
int			ft_printtype(char type, t_option *options, va_list *arg);
t_option	ft_get_option(const char *format, va_list *arg, t_option *options);
int			get_flags(const char *format, t_option *options);
int			get_width(const char *format, t_option *options);
int			get_precision(const char *format, t_option *options);
void		get_type(char type, t_option *options);
int			print_char(t_option *str, va_list arg);
int			print_hex(t_option	*str, char *aux_str);
int			print_hexa(t_option *str, va_list arg);
int			print_int(t_option *str, va_list arg);
int			print_nbr(t_option	*str, int nbr);
void		ft_putunbr_fd(unsigned int n, int fd);
int			print_ptr(t_option *str, va_list arg);
char		*str_data(char *c_str, t_option *str, va_list arg);
int			print_str(t_option *str, va_list arg);
char		*check_str(char *str);
char		*str_data(char *c_str, t_option *str, va_list arg);
int			print_unsigned(t_option *str, va_list arg);
void		check_uformat(unsigned int unbr, t_option *str);
int			print_uint(t_option *str, char *aux_str);

/*GNL functions*/
size_t		ft_strlen_gnl(const char*s);
char		*ft_strjoin_gnl(char const *s1, char const *s2);
char		*ft_strdup_gnl(const char *s1);
size_t		ft_linelen_gnl(const char *s);
char		*ft_linedup_gnl(const char *s1);
int			ft_transfer_line(char **read_content, char **line);
//static int found_line(char *read_content);
//static void ft_cpy_content(char **read_content, char *buffer);
int			get_next_line(int fd, char **line);

#endif
