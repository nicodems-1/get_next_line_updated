/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niverdie <niverdie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 15:45:36 by niverdie          #+#    #+#             */
/*   Updated: 2025/12/09 17:09:50 by niverdie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
 #define GET_NEXT_LINE_H
 
 #ifndef BUFFER_SIZE
  #define BUFFER_SIZE 42
#endif
#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
int eol_searcher(char   *stash);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(const char *s);
#endif