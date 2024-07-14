/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error_errno.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 23:24:31 by defimova          #+#    #+#             */
/*   Updated: 2024/07/14 23:24:34 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	ft_print_error_errno(const char *shell,
	const char *cmd, const char *arg)
{
	ft_print_error(shell, cmd, arg, strerror(errno));
}
