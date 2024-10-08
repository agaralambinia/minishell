/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <sosokin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 21:05:20 by defimova          #+#    #+#             */
/*   Updated: 2024/08/04 19:44:00 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}
/*
Аргументы:
s: Строка для вывода.
fd: Файловый дескриптор, в который выполняется

Возвращаемое значение: нет

Описание:
Выводит строку ’s’ в указанный файловый дескриптор
*/
