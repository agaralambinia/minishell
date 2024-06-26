/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 10:48:20 by sosokin           #+#    #+#             */
/*   Updated: 2024/06/05 11:31:19 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_arrlen(void **arr)
{
	int	len;

	len = 0;
	while (arr[len])
		len++;
	return (len);
}
