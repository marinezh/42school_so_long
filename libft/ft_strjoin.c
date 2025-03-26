/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:32:01 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/03/26 12:19:02 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	size_t	s1_len;
// 	size_t	s2_len;
// 	char	*result;

// 	if (!s1 || !s2)
// 		return (NULL);
// 	s1_len = ft_strlen(s1);
// 	s2_len = ft_strlen(s2);
// 	result = (char *)malloc((s1_len + s2_len +1) * sizeof(char));
// 	if (!result)
// 		return (NULL);
// 	ft_memcpy(result, s1, s1_len);
// 	result[s1_len] = '\0';
// 	ft_strlcat(result, s2, s1_len + s2_len + 1);
// 	return (result);
// }
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*result;

	s1_len = 0;
	s2_len = 0;
	while (s1 && s1[s1_len])
		s1_len++;
	while (s2 && s2[s2_len])
		s2_len++;
	result = malloc(s1_len + s2_len + 1);
	if (!result)
		return (NULL);
	if (s1)
		ft_memcpy(result, s1, s1_len);
	if (s2)
		ft_memcpy(result + s1_len, s2, s2_len + 1);
	result[s1_len + s2_len] = '\0';
	// free(s1);
	return (result);
}