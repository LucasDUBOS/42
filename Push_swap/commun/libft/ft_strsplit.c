/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:48:11 by lucdubos          #+#    #+#             */
/*   Updated: 2017/11/20 20:04:45 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nombres_mots(int nombres_mots, const char *str, char c)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (i == 0 || str[i] == c)
		{
			while (str[i] == c && str[i] != '\0')
				i++;
			if (str[i] != c && str[i] != '\0')
				nombres_mots++;
		}
		if (str[i] != '\0')
			i++;
	}
	return (nombres_mots);
}

static int		taille_mots(const char *str, int i, char c)
{
	int j;

	j = 0;
	while (str[i] == c && str[i] != '\0')
		i++;
	while (str[i] != c && str[i] != '\0')
	{
		i++;
		j++;
	}
	return (j);
}

static char		**fill_tab(char **tab2, const char *str, int i, char c)
{
	int j;
	int k;
	int nombres_mots;

	nombres_mots = ft_nombres_mots(0, str, c);
	j = 0;
	while (str[i] != '\0' && j < nombres_mots)
	{
		k = 0;
		tab2[j] = (char *)malloc(sizeof(*tab2) * (taille_mots(str, i, c) + 1));
		if (tab2[j] == NULL)
			return (NULL);
		while (str[i] == c && str[i] != '\0')
			i++;
		while (str[i] != c && str[i] != '\0')
			tab2[j][k++] = str[i++];
		tab2[j][k] = '\0';
		j++;
		i++;
	}
	tab2[nombres_mots] = 0;
	return (tab2);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab2;
	int		i;
	int		j;
	int		nombres_mots;

	if (s != NULL)
	{
		j = 1;
		i = 0;
		nombres_mots = 0;
		nombres_mots = ft_nombres_mots(nombres_mots, s, c);
		while (s[i] != '\0')
		{
			j++;
			i++;
		}
		tab2 = (char**)malloc(sizeof(char *) * (nombres_mots + 1));
		if (tab2 == NULL)
			return (NULL);
		i = 0;
		tab2 = fill_tab(tab2, s, i, c);
		return (tab2);
	}
	return (0);
}
