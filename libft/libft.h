/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:27:10 by victofer          #+#    #+#             */
/*   Updated: 2022/11/16 19:39:02 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <signal.h>

/*BONUS*/
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int		ft_isalpha(int c); //return 1 if c is alpha. Else return 0
int		ft_isdigit(int c); //return 1 if c is a digit. Else return 0
int		ft_isalnum(int c); //return 1 if c is alpha or a digit. Else return 0
int		ft_isascii(int c); //return 1 if c is ascii. Else return 0
int		ft_isprint(int c); //return 1 if c is printable. Else return 0
size_t	ft_strlen(const char *s); //Returrn the number of characters of string.
void	*ft_memset(void *b, int c, size_t len); //writes n bytes of c to string
void	*ft_bzero(void *s, size_t n); //writes n zeroed bytes to the string.
void	*ft_memcpy(void *dst, const void *src, size_t n); //copy bytes des->src
void	*ft_memmove(void *dst, const void *src, size_t len); //same but overlap
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);//copy src->dst
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);//concat dst->src
int		ft_toupper(int c); //Convert a lowercase lettter to uppercase
int		ft_tolower(int c); //Convert a uppercase lettter to lowercase
char	*ft_strchr(const char *s, int c); //locate first ocurrence of c. ret str
char	*ft_strrchr(const char *s, int c); //locate last ocurrence of c. ret str
void	*ft_memchr(const void *s, int c, size_t n);//Locate first ocurrency of c
int		ft_memcmp(void *s1, const void *s2, size_t n);//copy n bytes src to dst
int		ft_strncmp(const char *s1, const char *s2, size_t n); //compare n char 
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(const char *str);//arrayToInt take the first digits of str(+-)
void	*ft_calloc(size_t count, size_t size);//allocate memory. ret str(0) 
char	*ft_strdup(char *s1);//allocate memori for a copy of s, ret the copy
char	*ft_substr(char const *s, unsigned int start, size_t len);/*return a
		string of a string "s" from start and with lenght len" */
char	*ft_strjoin(char *s1, char *s2); //join to strings
char	*ft_strtrim(char *s1, char *set);//remove the "set" from s1 begin & end
char	**ft_split(char *s, char c);//ret array with "str" of "s" splitted by c
char	*ft_itoa(int n);//IntegerToArray convert the int to str
char	*ft_strmapi(char *s, char (*f)(unsigned int, char));/*ret a str whith
		the result of apllying the function "f" to all charact of s */
void	ft_striteri(char *s, void (*f)(unsigned int, char*));/*Same but return
		the string "s" modified applying the finction "f" to its characters*/
void	ft_putchar_fd(char c, int fd); //putchar to a fd
void	ft_putstr_fd(char *s, int fd); //putstr to a fd
void	ft_putendl_fd(char *s, int fd);//putstr to a fd followed by a new line
void	ft_putnbr_fd(int n, int fd);//put number to a fd

/* BONUS */
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/* MORE FUNCTIONS ADDED  */
void	ft_put_bin(unsigned int num); //Print int to binary
void	ft_put_oct(unsigned int num); //Print int to octal
void	ft_put_hexa(unsigned int num);//Print int to Hexadecomal
char	*ft_str_rev(char *str); //print a string but reversal ex(hello -> olleh)
int		ft_bin_to_dec(int num); //Return a binary number in decimal base
int		ft_dec_to_bin(int num); //Return a decimal number in binary base
int		ft_dec_to_oct(int num); //Return a decimal number in octal base
char	*ft_dec_to_hexa(int num); //Return a decimal number in hexa base
int		max(int *tab, unsigned int len); //Returns the max value of an array
int		min(int *tab, unsigned int len); //Returns the min value of an array
int		ft_pow(int n, int pow); //pow (pow(2, 3) -> 2 * 2 * 2) you know...
int		ft_power(int n, int pow); //pow (pow(2, 3) -> 2 * 2 * 2) you know...

//FT_PRINTF AND RELATED FUNCTIONS
int		ft_printf(char const *input, ...); //Something like prinf
int		ft_print_char(int c); //Print a char and return the num of chars printed
int		ft_print_unsigned(unsigned int n); //print an unsigned int (ret)
char	*ft_unsigned_itoa(unsigned int n); //Same that itoa but with unsigned
int		ft_print_ptr(unsigned long long ptr); //print pointer of void ...
int		ft_print_string(char *s); //print a string (return num chars printed)
int		ft_print_int(int n); //print an int numbber (return num chars printed)
int		ft_print_hexa(unsigned int num, char format);//print an int->hexa (ret)

#endif
