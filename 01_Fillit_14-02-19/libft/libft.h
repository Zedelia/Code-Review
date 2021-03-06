/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: groubaud <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 20:22:01 by groubaud     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/17 18:11:43 by groubaud    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *s1);
char				*ft_strndup(const char *s1, int n);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *hay, const char *ndl, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_atoi(const char *str);

void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memalloc(size_t size);
int					*ft_memalloc_int(int size, int full, int end);
void				ft_memdel(void **ap);
void				ft_bzero(void *s, size_t n);
void				ft_freetab(char **str);

char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strsub(char const *s, unsigned int start, size_t len);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);

void				ft_putchar(char c);
void				ft_putstr(const char *str);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_puterror(const char *str);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_puttab(char **tab);
void				ft_puttab_int (int *tab, int end, char sep);

t_list				*ft_lstnew(void const *content, size_t constent_size);
void				ft_lstdelone(t_list**alst,
					void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

char				*ft_itoa_base(int n, int base);
size_t				ft_nbrlen(int nb, int base);
char				*ft_spec_rev(char *nbr);
void				ft_swap(int *a, int *b);
char				*ft_strlowcase(const char *str);
char				*ft_strupcase(const char *str);
int					ft_strcasecmp(const char *s1, const char *s2);
int					ft_strncasecmp(const char *s1, const char *s2, size_t n);

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isblank(int c);
int					ft_is_tnsp(int c);
int					ft_iscntrl(int c);
int					ft_isblank(int c);
int					ft_isgraph(int c);
int					ft_isspace(int c);
int					ft_islower(int c);
int					ft_isupper(int c);

int					ft_str_is_alpha(const char *str);
int					ft_str_is_lowercase(const char *str);
int					ft_str_is_numeric(const char *str);
int					ft_str_is_printable(const char *str);
int					ft_str_is_uppercase(const char *str);

int					ft_sqrt(int nb);
int					ft_pow(int nb, int p);
int					ft_tablen(char **tab);
int					ft_abs(int nb);

int					ft_isprime(int nb);
void				ft_sleep(int nb);

#endif
