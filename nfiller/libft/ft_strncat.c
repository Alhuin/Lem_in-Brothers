/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nbettach <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/26 17:12:52 by nbettach     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/26 17:12:52 by nbettach    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char *str1;

	str1 = s1;
	while (*str1 != '\0')
		str1++;
	while (n-- && *s2 != '\0')
		*str1++ = *s2++;
	*str1 = '\0';
	return (s1);
}