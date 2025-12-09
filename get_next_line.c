/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niverdie <niverdie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 15:44:47 by niverdie          #+#    #+#             */
/*   Updated: 2025/12/09 18:11:01 by niverdie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ft_strjoin, ft_strlen, eol_searcher, next_stash
#include "get_next_line.h"
#include <stdio.h>

int h = 0;

char    *final_string(char  *stash)
{
    int len;
    int i;
    char    *final;
    
    i = 0;
    len = eol_searcher(stash);
    final = malloc(sizeof(char)*len);
    while(i <= len)
    {
        final[i] = stash[i];
        i++;
    }
    return(final);
}
char    *next_stash(char *stash)
{
    int end;
    int i;
    char *temp_stash;

    i = 0;
    end = eol_searcher(stash) + 1;
    while(stash[i+end])
        i++;
    temp_stash = malloc(sizeof(char)*i);
    i = -1;
    while(stash[end + i])
    {
        temp_stash[i] = stash[i+end];
        i++;
    }
    if (stash != NULL)
        free(stash);
    stash = NULL;
    return (temp_stash);
}

int eol_searcher(char   *stash)
{
    int i;

    i = 0;
    while(stash[i])
    {
        if (stash[i] == '\n' || stash[i] == '\0')
            return(i);
        i++;
    }
    return(-1);
}
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char    *ft_strjoin(char *stash, const char *buffer)
{
	int		i;
	int		j;
	char	*stash_temp;
    int len_stash;

	i = 0;
	j = 0;
    h++;
    if (stash[0] == '\0'){
        len_stash = 0;
    }
    else 
        len_stash = ft_strlen(stash);
	stash_temp = malloc(sizeof(char) * (len_stash + ft_strlen(buffer) + 1));
	if (!stash_temp)
		return NULL;
    while (stash[0] != '\0' && stash[i])
    {
        stash_temp[i] = stash[i];
        i++;
    }
    // if (stash)
    //     free(stash);
	while (j <= ft_strlen(buffer))
    {
		stash_temp[i + j] = buffer[j];
        j++;
    }
	stash_temp[i + j] = '\0';
    return(stash_temp);
}
char    *get_next_line(int fd)
{
    int readcheck = 0;
    char  buffer[BUFFER_SIZE + 1];
    static  char    *stash = NULL;
    char *stash_temp;
    char    *final;

    if (!stash){
        stash = malloc(1 * sizeof(char));
        stash[0] = '\0';
}
    while(readcheck >= 0)
    {
        readcheck = read(fd, buffer, BUFFER_SIZE);
        if(readcheck < 0)
            return(free(stash), NULL);
        stash_temp = ft_strjoin(stash, buffer);
        if (!stash_temp)
            return (NULL);
        stash = stash_temp;
        if (eol_searcher(stash) >= 0)
        {
            final = final_string(stash);
            stash_temp = next_stash(stash);
            stash = stash_temp;
            return(final);
        }
    }
    return(NULL);
}

int	main(void)
{
	int	fd;
	fd = open("get_next_line.txt", O_RDONLY);
    printf("%s", get_next_line(fd));
    // printf("%s", get_next_line(fd))
    // printf("%s", get_next_line(fd));
    // printf("%s", get_next_line(fd));

    // char    *line;
    // do {
    //      line = get_next_line(fd);
    //     // printf("%s", line);
    //     // free(line);
    // } while (line != NULL);
}