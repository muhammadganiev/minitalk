/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:40:10 by muganiev          #+#    #+#             */
/*   Updated: 2022/09/24 14:37:39 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk_bonus.h"

int	g_str_len;

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
		ft_printf(BRIGHT_RED "ERROR: string is empty"
			RESET);
		exit(EXIT_FAILURE);
	}
}

static void	handle_signal(int sig, siginfo_t *info, void *ptr)
{
	static int	count_str;

	(void) ptr;
	(void) info;
	if (sig == SIGUSR1)
		count_str++;
	if (count_str == g_str_len)
	{
		ft_printf(BRIGHT_GREEN "%d byte/s received!" RESET, count_str);
		exit(EXIT_SUCCESS);
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
	struct sigaction	sa;
	int					pid;

	if (argc != 3)
	{
		ft_printf(BRIGHT_RED
			"%s MUST HAVE 3 ARGUMENTS!\n" RESET, argv[0]);
		exit(EXIT_FAILURE);
	}
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handle_signal;
	sigaction(SIGUSR1, &sa, NULL);
	pid = ft_atoi(argv[1]);
	are_args_valid(pid, argv[2]);
	g_str_len = ft_strlen(argv[2]);
	ft_str_to_binary(pid, argv[2]);
	while (1)
		pause();
	return (0);
}
