/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaouzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:35:49 by kfaouzi           #+#    #+#             */
/*   Updated: 2021/11/04 17:54:10 by kfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int	i;
	unsigned char	*nv_sr;
	unsigned char	*nv_ds;

	nv_sr = (unsigned char *)src;
	nv_ds = (unsigned char *)dst;
	i = 0;
	if (!nv_sr && !nv_ds)
		return (NULL);
	if (src >= dst)
		ft_memcpy(nv_ds, nv_sr, len);
	else
		while (i < len--)
			nv_ds[len] = nv_sr[len];
	return (dst);
}
