/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlen.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nbettach <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/26 17:12:52 by nbettach     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/29 18:30:50 by nbettach    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t			ft_strlen(const char *s)
{
	int			i;

	i = 0;
	while (s && s[i] != '\0')
		i++;
	return (i);
}