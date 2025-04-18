/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 08:12:38 by thmaitre          #+#    #+#             */
/*   Updated: 2024/11/05 14:57:09 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <bsd/string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	test_ft_isalpha(void)
{
	printf("ft_isalpha('c') %d\n", ft_isalpha('t'));
	printf("isalpha('c')    %d\n", isalpha('t'));
	printf("ft_isalpha('0') %d\n", ft_isalpha('0'));
	printf("isalpha('0')    %d\n\n", isalpha('0'));
}

void	test_ft_isdigit(void)
{
	printf("ft_isdigit('0') %d\n", ft_isdigit('0'));
	printf("isdigit('0')    %d\n", isdigit('0'));
	printf("ft_isdigit('a') %d\n", ft_isdigit('a'));
	printf("isdigit('a')    %d\n\n", isdigit('a'));
}

void	test_ft_isalnum(void)
{
	printf("ft_isalnum('0') %d\n", ft_isalnum('0'));
	printf("isalnum('0')    %d\n", isalnum('0'));
	printf("ft_isalnum('a') %d\n", ft_isalnum('a'));
	printf("isalnum('a')    %d\n", isalnum('a'));
	printf("ft_isalnum(' ') %d\n", ft_isalnum(' '));
	printf("isalnum(' ')    %d\n", isalnum(' '));
	printf("ft_isalnum('{') %d\n", ft_isalnum('{'));
	printf("isalnum('{')    %d\n\n", isalnum('{'));
}

void	test_ft_isascii(void)
{
	printf("ft_isascii(0)   %d\n", ft_isascii(0));
	printf("isascii(0)      %d\n", isascii(0));
	printf("ft_isascii(138) %d\n", ft_isascii(138));
	printf("isascii(138)    %d\n\n", isascii(138));
}

void	test_ft_isprint(void)
{
	int	i;

	i = 0;
	while (i <= 127)
	{
		if (ft_isprint(i) != isprint(i))
		{
			printf("ft_isprint(i) =  %d\n", ft_isprint(i));
			printf("is_print(i)   =  %d\n\n", isprint(i));
		}
		if (i == 127 && (ft_isprint(i) == isprint(i)))
			printf("ft_isprint OK !\n\n");
		i++;
	}
}

void	test_ft_strlen(void)
{
	printf("ft_strlen('bonjour')	%zu\n", ft_strlen("bonjour"));
	printf("strlen('bonjour')	%lu\n\n", strlen("bonjour"));
	printf("ft_strlen('jour')   	%zu\n", ft_strlen("jour"));
	printf("strlen('jour')		%lu\n\n", strlen("jour"));
	printf("ft_strlen('')   	%zu\n", ft_strlen(""));
	printf("strlen('')		%lu\n\n", strlen(""));
}

void	test_ft_memset(void)
{
	int	tab[] = {1, 5, 7, 8, 9};
	int	i;

	i = 0;
	while (i < 5)
	{
		printf("%d ", tab[i]);
		i++;
	}
	printf("\n");
	ft_memset(tab, 0, 20);
	i = 0;
	while (i < 5)
	{
		printf("%d ", tab[i]);
		i++;
	}
	printf("\n\n");
}

void	test_ft_bzero(void)
{
	int	tab[] = {1, 5, 7, 8, 9};
	int	i;

	i = 0;
	while (i < 5)
	{
		printf("%d ", tab[i]);
		i++;
	}
	printf("\n");
	ft_memset(tab, 0, 20);
	i = 0;
	while (i < 5)
	{
		printf("%d ", tab[i]);
		i++;
	}
	printf("\n\n");
}

void	test_ft_memcpy(void)
{
	int		src[] = { 2, 4, 3, 6, 74 };
	int		*dest;
	size_t	size;
	int		i;

	dest = NULL;
	size = sizeof(src);
	i = 0;
	dest = malloc(size);
	while (i < 5)
	{
		printf("%d ", src[i]);
		i++;
	}
	printf("\n");
	dest = (int *)ft_memcpy(dest, src, size);
	i = 0;
	while (i < 5)
	{
		printf("%d ", dest[i]);
		i++;
	}
	printf("\n\n");
}

void	test_ft_memmove(void)
{
	char	str[] = "abc.defgh.ijklm";
	void	*src;
	void	*dest;
	size_t	size_moove;

	src = str + 4;
	dest = str;
	size_moove = 15;
	printf("%s\n", str);
	ft_memmove(dest, src, size_moove);
	printf("%s\n\n", str);
}

void	test_ft_strlcpy(void)
{
	const char	*src = "bonjour";
	char		dst[8];
	size_t		size;

	size = sizeof(*src) * 8;
	size = ft_strlcpy(dst, src, size);
	printf("src : %s\n", src);
	printf("dst : %s\n", dst);
	printf("size: %zu\n\n", size);
	size = sizeof(*src) * 8;
	size = strlcpy(dst, src, size);
	printf("src : %s\n", src);
	printf("dst : %s\n", dst);
	printf("size: %zu\n\n", size);
}

void	test_ft_strlcat(void)
{
	const char	*src = "123";
	char		dst[15];
	size_t		size;
	size_t		result;

	size = 0;
	result = 0;
	result = ft_strlcat(dst, src, size);
	printf("result : %zu\n", result);
	printf("src    : %s\n", src);
	printf("dest   : %s\n\n", dst);
	result = strlcat(dst, src, size);
	printf("result : %zu\n", result);
	printf("src    : %s\n", src);
	printf("dest   : %s\n\n", dst);
}

void	test_ft_toupper(void)
{
	char	str[] = "bonjourcoucou389";
	int		i;

	i = 0;
	printf("%s\n", str);
	while (str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
	printf("%s\n\n", str);
}

void	test_ft_tolower(void)
{
	char	c;

	c = 'A';
	c = ft_tolower(c);
	printf("%c\n\n", c);
}

void	test_ft_strchr(void)
{
	const char	*str = "tripouille";
	char		chr;

	chr = 't' + (char)256;
	str = ft_strchr(str, chr);
	printf("%s\n\n", str);
}

void	test_ft_strrchr(void)
{
	const char	*str = "tripouille";
	char		chr;

	chr = 't';
	str = ft_strrchr(str, chr);
	printf("%s\n\n", str);
}

void	test_ft_strncmp(void)
{
	char	*s1;
	char	*s2;
	size_t	n;
	int		result;

	s1 = "abcdefgh";
	s2 = "";
	n = 0;
	result = ft_strncmp(s1, s2, n);
	printf("%d\n", result);
	result = strncmp(s1, s2, n);
	printf("%d\n\n", result);
}

void	test_ft_memchr(void)
{
	char	str[] = {101, 102, 103, 120, 0};
	void	*chr;
	int		c;
	size_t	n;

	c = 103;
	n = sizeof(*str) * 4;
	chr = ft_memchr(str, c, n);
	printf("%s\n", (char *)chr);
}

void	test_ft_memcmp(void)
{
	int			result;
	const char	*s1 = "ABC";
	const char	*s2 = "ABD";
	size_t		n;

	n = 3;
	result = ft_memcmp(s1, s2, n);
	printf("%d\n\n", result);
}

void	test_ft_strnstr(void)
{
	const char	*big = "abc";
	const char	*little = "abc";
	char		*chr;
	size_t		len;

	len = 7;
	chr = ft_strnstr(big, little, len);
	printf("%s\n\n", chr);
	chr = strnstr(big, little, len);
	printf("%s\n", chr);
}

void	test_ft_atoi(void)
{
	int			result;
	const char	*nptr = " \f \t \n \r \v +1224284abc";

	// const char *nptr = "bc";
	result = atoi(nptr);
	printf("%d\n", result);
	result = ft_atoi(nptr);
	printf("%d\n\n", result);
}







void	test_ft_calloc(void)
{
	char	*str;
	size_t	nmemb;
	size_t	size;

	nmemb = 0;
	size = 0;
	str = ft_calloc(nmemb, size);
	printf("%s\n", str);
	free(str);
}

void	test_ft_strdup(void)
{
	const char	*s = "helloworld!";
	char		*dup;

	dup = ft_strdup(s);
	printf("%s\n", dup);
	dup = strdup(s);
	printf("%s\n\n", dup);
}

void	test_ft_substr(void)
{
	char			*sub;
	const char		*s = "";
	unsigned int	start;
	size_t			len;

	start = 1;
	len = 1;
	sub = ft_substr(s, start, len);
	printf("%s\n\n", sub);
	free(sub);
}

void	test_ft_strjoin(void)
{
	char const	*s1;
	char const	*s2;
	char		*join;

	s1 = "lorem ipsum";
	s2 = "dolor sit amet";
	join = ft_strjoin(s1, s2);
	printf("%s\n\n", join);
}

void	test_ft_strtrim(void)
{
	const char	*s1 = "   xxx   xxx";
	const char	*set = " x";
	char		*trim;

	trim = ft_strtrim(s1, set);
	printf("%s\n\n", trim);
}

void	test_ft_split(void)
{
	char		**split;
	char const	*str;
	char		c;
	int			i;

	str = "";
	c = 'a';
	i = 0;
	split = ft_split(str, c);
	while (split[i])
	{
		printf("%s\n", split[i]);
		i++;
	}
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	test_ft_itoa(void)
{
	int		n;
	char	*itoa;

	n = -422;
	itoa = ft_itoa(n);
	printf("%s\n", itoa);
	n = 422;
	itoa = ft_itoa(n);
	printf("%s\n", itoa);
}

char	ft_mapi_toupper_even(unsigned int index, char c)
{
	if (c >= 'a' && c <= 'z' && index % 2 == 0)
		c -= 32;
	return (c);
}

void	test_ft_strmapi(void)
{
	char		*mapi;
	char const	*s;

	mapi = NULL;
	s = "bonjour";
	mapi = ft_strmapi(s, &ft_mapi_toupper_even);
	printf("%s\n\n", mapi);
}

void	ft_iteri_toupper_even(unsigned int index, char *c)
{
	if (*c >= 'a' && *c <= 'z' && index % 2 == 0)
		*c -= 32;
}

void	test_ft_striteri(void)
{
	char	s[] = "bonjour";

	ft_striteri(s, &ft_iteri_toupper_even);
	printf("%s\n\n", s);
}

void	test_ft_putchar_fd(void)
{
	char	c;
	int		fd;

	c = 'c';
	fd = 1;
	ft_putchar_fd(c, fd);
}

void	test_ft_putstr_fd(void)
{
	char	*s;
	int		fd;

	s = "bonjourtouslemonde";
	fd = 1;
	ft_putstr_fd(s, fd);
}

void	test_ft_putendl_fd(void)
{
	char	*s;
	int		fd;

	s = "bonjouratous";
	fd = 1;
	ft_putendl_fd(s, fd);
}

void	test_ft_putnbr_fd(void)
{
	int	n;
	int	fd;

	// int	n = 0;
	n = -2147483648;
	fd = 1;
	ft_putnbr_fd(n, fd);
}

void	ft_lstprint(t_list *list)
{
	t_list *li = list;

	while (li != NULL)
	{
		printf("[%p] ", li);
		printf("[%s] ", (char *)li->content);
		printf("[%p] \n", li->next);
		li = li->next;
	}
}

void	bonus_ft_lstnew_bonus()
{
	t_list lst;

	lst.next = ft_lstnew("42");
}

void	ft_lstadd_front_bonus()
{
	t_list *lst;
	t_list *new;

	lst = ft_lstnew("42");
	new = ft_lstnew("41");

	ft_lstadd_front(&lst, new);
	ft_lstadd_front(&lst, new);
	lst = new;
	ft_lstprint(lst);
}

void	ft_lstsize_bonus()
{
	t_list *lst;
	t_list *new;
	t_list *newnew;
	int		lstsize;

	lst = ft_lstnew("42");
	new = ft_lstnew("41");
	newnew = ft_lstnew("40");
	lstsize = 0;

	ft_lstadd_front(&lst, new);
	lst = new;
	ft_lstadd_front(&lst, newnew);
	lst = newnew;
	lstsize = ft_lstsize(lst);
	ft_lstprint(lst);
	printf("lstsize :%d\n", lstsize);
}

void	ft_lstlast_bonus()
{
	t_list *lst;
	t_list *new;
	t_list *newnew;
	int		lstsize;

	lst = ft_lstnew("42");
	new = ft_lstnew("41");
	newnew = ft_lstnew("40");
	lstsize = 0;

	ft_lstadd_front(&lst, new);
	lst = new;
	ft_lstadd_front(&lst, newnew);
	lst = newnew;
	lstsize = ft_lstsize(lst);
	ft_lstprint(lst);
	lst = ft_lstlast(lst);
	ft_lstprint(lst);
	printf("lstsize :%d\n", lstsize);
}

void	ft_print_result(t_list *elem)
{
	int		len;

	len = 0;
	while (((char *)elem->content)[len])
		len++;
	write(1, elem->content, len);
	write(1, "\n", 1);
}

void	ft_lstadd_back_bonus()
{
	// t_list	*lst;
	// t_list	*front;
	// t_list	*back;
	// t_list	*backback;

	// lst = ft_lstnew("12");
	// front = ft_lstnew("11");
	// back = ft_lstnew("13");
	// backback = ft_lstnew("14");
	// if(!lst || !front || !back || !backback)
	// 	return;

	// ft_lstadd_front(&lst, front);
	// ft_lstadd_back(&lst, back);
	// ft_lstadd_back(&lst, backback);
	// printf("lstsize: %d\n", ft_lstsize(lst));
	// ft_lstprint(lst);




	t_list		*begin;
	t_list		*elem;
	t_list		*elem2;
	t_list		*elem3;
	t_list		*elem4;
	char		*str = strdup("lorem");
	char		*str2 = strdup("ipsum");
	char		*str3 = strdup("dolor");
	char		*str4 = strdup("sit");

	elem = ft_lstnew(str);
	elem2 = ft_lstnew(str2);
	elem3 = ft_lstnew(str3);
	elem4 = ft_lstnew(str4);
	begin = NULL;
	ft_lstadd_back(&begin, elem);
	ft_lstadd_back(&begin, elem2);
	ft_lstadd_back(&begin, elem3);
	ft_lstadd_back(&begin, elem4);
	while (begin)
	{
		ft_print_result(begin);
		begin = begin->next;
	}
}

void	delone(void *content)
{
	free(content);
}

void	ft_lstdelone_bonus()
{
	t_list	*lst;
	t_list	*front;
	t_list	*back;
	t_list	*backback;

	lst = ft_lstnew("12");
	front = ft_lstnew("11");
	back = ft_lstnew("13");
	backback = ft_lstnew("14");
	if(!lst || !front || !back || !backback)
		return;

	ft_lstadd_front(&lst, front);
	ft_lstadd_back(&lst, back);
	ft_lstadd_back(&lst, backback);
	printf("lstsize: %d\n", ft_lstsize(lst));
	ft_lstprint(lst);
	ft_lstdelone(lst, &delone);
	ft_lstprint(lst);
}

void	ft_lstclear_bonus()
{
	t_list	*lst;
	t_list	*front;
	t_list	*back;
	t_list	*backback;

	lst = ft_lstnew("12");
	front = ft_lstnew("11");
	back = ft_lstnew("13");
	backback = ft_lstnew("14");
	if(!lst || !front || !back || !backback)
		return;

	ft_lstadd_front(&lst, front);
	ft_lstadd_back(&lst, back);
	ft_lstadd_back(&lst, backback);
	printf("lstsize: %d\n", ft_lstsize(lst));
	ft_lstprint(lst);
	ft_lstclear(&lst, &delone);
	ft_lstprint(lst);
}

void	f_toupper(void *content)
{
	*(char *)content += 1;
}

void	*f_toupper_return(void *content)
{
	char	*new_content;

	new_content = ft_strjoin(content, "map");;
	return (new_content);
}

void	ft_lstiter_bonus()
{
	t_list	*begin;
	t_list	*elem1;
	t_list	*elem2;
	t_list	*elem3;
	char	*str1;
	char	*str2;
	char	*str3;

	begin = NULL;
	str1 = strdup("a");
	str2 = strdup("b");
	str3 = strdup("c");
	elem1 = ft_lstnew(str1);
	elem2 = ft_lstnew(str2);
	elem3 = ft_lstnew(str3);
	ft_lstadd_back(&begin, elem1);
	ft_lstadd_back(&begin, elem2);
	ft_lstadd_back(&begin, elem3);
	ft_lstiter(begin, &f_toupper);
	ft_lstprint(begin);
}

t_list	*list_create_3(t_list *begin)
{
	if (begin != NULL)
	{
		printf("begin should be NULL");
		return (NULL);
	}
	t_list	*elem1;
	t_list	*elem2;
	t_list	*elem3;
	char	*str1;
	char	*str2;
	char	*str3;

	begin = NULL;
	str1 = ft_strdup("str1");
	str2 = ft_strdup("str2");
	str3 = ft_strdup("str3");
	elem1 = ft_lstnew(str1);
	elem2 = ft_lstnew(str2);
	elem3 = ft_lstnew(str3);
	ft_lstadd_back(&begin, elem1);
	ft_lstadd_back(&begin, elem2);
	ft_lstadd_back(&begin, elem3);
	return (begin);
}

void	ft_lstmap_bonus()
{
	t_list	*begin;
	t_list	*map;

	begin = NULL;
	begin = list_create_3(begin);
	map = NULL;

	printf("begin :\n");
	ft_lstprint(begin);
	printf("\n\n");

	map = ft_lstmap(begin, &f_toupper_return, &delone);

	printf("begin :\n");
	ft_lstprint(begin);
	printf("\n\n");
	printf("map   :\n");
	ft_lstprint(map);
}

//make bonus
//cc -g -Wall -Wextra -Werror tester.c -lbsd libft.a
int	main(void)
{
	// test_ft_isalpha();
	// test_ft_isdigit();
	// test_ft_isalnum();
	// test_ft_isascii();
	// test_ft_isprint();
	// test_ft_strlen();
	// test_ft_memset();
	// test_ft_bzero();
	// test_ft_memcpy();
	test_ft_memmove();
	// test_ft_strlcpy();
	// test_ft_strlcat();
	// test_ft_toupper();
	// test_ft_tolower();
	// test_ft_strchr();
	// test_ft_strrchr();
	// test_ft_strncmp();
	// test_ft_memchr();
	// test_ft_memcmp();
	// test_ft_strnstr();
	// test_ft_atoi();
	// test_ft_calloc();
	// test_ft_strdup();
	// test_ft_substr();
	// test_ft_strjoin();
	// test_ft_strtrim();
	// test_ft_split();
	// test_ft_itoa();
	// test_ft_strmapi();
	// test_ft_striteri();
	// test_ft_putchar_fd();
	// test_ft_putstr_fd();
	// test_ft_putendl_fd();
	// test_ft_putnbr_fd();

	// ft_lstnew_bonus();
	// ft_lstadd_front_bonus();
	// ft_lstsize_bonus();
	// ft_lstlast_bonus();
	// ft_lstadd_back_bonus();
	// ft_lstdelone_bonus();
	// ft_lstclear_bonus();
	// ft_lstiter_bonus();
	// ft_lstmap_bonus();

	return (0);
}
