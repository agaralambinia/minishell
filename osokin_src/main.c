/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 10:43:29 by sosokin           #+#    #+#             */
/*   Updated: 2024/05/25 19:04:34 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main()
{
	char	*line;

	line = readline("> ");
	while (line)
	{
		add_history(line);
		printf("You type %s, great...\n", line);
		line = readline("> ");
	}

	return (0);
}
