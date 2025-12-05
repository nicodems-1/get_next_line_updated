/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niverdie <niverdie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 15:44:47 by niverdie          #+#    #+#             */
/*   Updated: 2025/12/05 17:05:43 by niverdie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ft_strjoin, ft_strlen, eol_searcher, next_stash

#include <unistd.h>
#include <stdlib.h>

char    *final_string(char  *stash)
{
    int len;
    int i;
    char    *final;
    
    i = 0;
    len = eol_searcher(stash);
    final = malloc(sizeof(char)*len);
    while(i <= len)
        final[i++] = stash[i];
    return(final);
}
void    next_stash(char *stash)
{
    int end;
    int i;
    char *temp_stash;

    i = 0;
    end = eol_searcher(stash);
    while(stash[i+end])
        i++;
    temp_stash = malloc(sizeof(char)*i);
    i = 0;
    while(stash[i+end])
        temp_stash[i++] = stash[i+end];
    free(stash);
    stash = temp_stash; 
}

int eol_searcher(char   *stash)
{
    int i;

    i = 0;
    while(stash[i])
    {
        if (stash[i] == '\n' || stash[i] == '\0')
            return(i);
    }
    return(-1);
}
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
    if(s == NULL)
        return(0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *stash, char *buffer)
{
	int		i;
	int		j;
	char	*stash_temp;

	i = ft_strlen(stash);
	j = -1;
	stash_temp = malloc(sizeof(char) * (ft_strlen(stash) + ft_strlen(buffer) + 1));
	if (!stash_temp)
		return (NULL);
	while (buffer[j++])
		stash_temp[i + j] = buffer[j];
	stash_temp[i + j] = '\0';
    free(stash);
	stash = stash_temp;
    return(stash);
}
