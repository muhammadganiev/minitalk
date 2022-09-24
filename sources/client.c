/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 17:45:18 by muganiev          #+#    #+#             */
/*   Updated: 2022/09/20 13:21:13 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static void	are_args_valid(int pid, char *str)
{
	if (pid < MIN_PID || pid > MAX_PID)
	{
		ft_printf(BRIGHT_RED "ERROR: PID range: %d and %d\n"
			RESET, MIN_PID, MAX_PID);
		exit(EXIT_FAILURE);
	}
	if (!*str)
	{
		ft_printf(BRIGHT_RED "ERROR: there is nothing to send"
			RESET);
		exit(EXIT_FAILURE);
	}
}

static void	ft_str_to_binary(int pid, char *str)
{
	int	index;
	int	shift_len;

	index = 0;
	while (str[index])
	{
		shift_len = 7;
		while (shift_len >= 0)
		{
			if ((str[index] & (1 << shift_len)) > 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			shift_len--;
			usleep(100);
		}
		index++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;

	if (argc != 3)
	{
		ft_printf(BRIGHT_RED
			"%s MUST HAVE 3 ARGUMENTS!\n" RESET, argv[0]);
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	are_args_valid(pid, argv[2]);
	ft_str_to_binary(pid, argv[2]);
	return (0);
}
