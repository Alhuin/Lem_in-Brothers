/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   nassim_tools.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/26 17:34:13 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/26 17:44:02 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lemin.h"

void swap_matrix(t_lem *e, int a, int b)
{
	int *tmp;

	tmp = e->matrix[a];
	e->matrix[a] = e->matrix[b];
	e->matrix[b] = tmp;
}


void print_matrix(t_lem *e)
{
	int i;
	int j;

	i = 0;
	while (i < e->nb_room)
	{
		j = 0;
		while (j < e->nb_room)
		{
			ft_printf("%d ", e->matrix[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void print_equiv(t_lem *e, int *equiv)
{
	int i;

	i = 0;
	while (i < e->nb_room)
	{
		ft_printf("%d - ", equiv[i]);
		i++;
	}
	ft_printf("\n");
}

void print_datalinks(t_lem *e)
{
	int i;
	int j;

	i = -1;
	while (++i < e->nb_room)
	{
		j = -1;
		printf("data[%d] = ", i);
		while (++j < e->data[i].nb_links)
			printf(" %d ", e->data[i].links[j]);
		printf(" name = %s\n", e->data[i].name);
	}
}

int sort_matrix(t_lem *e)
{
	int i;
	int equiv[e->nb_room];

	//MALLOC NOUVELLE MATRIX
	i = -1;
	if (!(e->sorted = malloc(sizeof(int *) * e->nb_room)))
		return (-1);
	while (++i < e->nb_room)
		if (!(e->sorted[i] = malloc(sizeof(int) * e->nb_room)))
			return (-1);
	//DEBUT TABLEAU EQUIV
	i = -1;
	while (++i < e->nb_room)
	{
		if (i == e->end)
			equiv[i] = 0;
		else if (i == e->start)
			equiv[i] = e->nb_room - 1;
		else
			equiv[i] = -1;
	}
	//SCAN data POUR AVOIR L'ORDRE && METTRE EQUIVALENCE DATA[i].LINKS
	data_scan(e, equiv);
	//TRI DE DATA
	data_sort(e, equiv);
	return (0);
}

int	make_matricei_suit(t_lem *e)
{
	int i;
	int j;
	int f;
	int k;

	i = -1;
	if (!(e->matrix = malloc(sizeof(int *) * e->nb_room)))
		return (-1);
	while (++i < e->nb_room)
	{
		j = -1;
		if (!(e->matrix[i] = malloc(sizeof(int) * e->nb_room)))
			return (-1);
		while (++j < e->nb_room)
		{
			f = 0;
			k = -1;
			while (++k < e->data[j].nb_links)
				if (e->data[j].links[k] == i)
					f = 1;
			e->matrix[i][j] = (f == 1 ? 1 : 0);
		}
	}
	return (0);
}

int make_matrice(t_lem *e)
{
	printf("MATRICE NON SORTED\n");
	make_matricei_suit(e);
	print_matrix(e);
	printf("\nDATA LINKS NON SORTED\n");
	print_datalinks(e);
	ft_printf("\n");
	sort_matrix(e);
	printf("DATA LINKS SORTED\n");
	print_datalinks(e);
	printf("\nMATRICE SORTED\n");
	make_matricei_suit(e);
	print_matrix(e);
	return (0);
}
