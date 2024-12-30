/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjose-va <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:35:55 by bjose-va          #+#    #+#             */
/*   Updated: 2024/11/15 20:08:24 by bjose-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *s, char c)
{
	size_t		count;
	int			in_substring;

	count = 0;
	in_substring = 0;
	while (*s)
	{
		if (*s != c && !in_substring)
		{
			in_substring = 1;
			count++;
		}
		else if (*s == c)
			in_substring = 0;
		s++;
	}
	return (count);
}

static char	*word_dup(const char *s, size_t start, size_t finish)
{
	char	*word;
	size_t	i;

	word = malloc((finish - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (start < finish)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

static void	*free_words(char **words, size_t i)
{
	while (i > 0)
		free(words[--i]);
	free(words);
	return (NULL);
}

static char	**split_loop(const char *s, char c, char **words)
{
	size_t	i;
	size_t	j;
	int		index;

	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			words[j++] = word_dup(s, index, i);
			if (!words[j - 1])
				return (free_words(words, j - 1));
			index = -1;
		}
		i++;
	}
	words[j] = 0;
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**words;

	if (!s)
		return (NULL);
	words = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!words)
		return (NULL);
	return (split_loop(s, c, words));
}

#include <stdio.h>
#include "libft.h"  // Certifique-se de incluir 
//o arquivo de cabeçalho que contém a declaração de ft_split

int main(void)
{
    char **result;
    char *str = NULL;
    char delimiter = ' ';
    int i;

    result = ft_split(str, delimiter);
    if (!result)
    {
        printf("Erro ao dividir a string.\n");
        return (1);
    }

    i = 0;
    while (result[i])
    {
        printf("Substring %d: %s\n", i, result[i]);
        i++;
    }

    // Libera a memória alocada
    i = 0;
    while (result[i])
    {
        free(result[i]);
        i++;
    }
    free(result);

    return (0);
}