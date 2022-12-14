/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 17:39:11 by muganiev          #+#    #+#             */
/*   Updated: 2022/09/20 13:27:48 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static void	handle_binary_to_str(int sig, siginfo_t *info, void *ptr)
{
	static char	c;
	static char	num_of_bits;

	(void) ptr;
	(void) info;
	if (sig == SIGUSR1)
		c |= 1;
	if (sig == SIGUSR2)
		c |= 0;
	num_of_bits++;
	if (num_of_bits == 8)
	{
		ft_printf("%c", c);
		num_of_bits = 0;
		c = 0;
	}
	c <<= 1;
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	if (argc != 1)
	{
		ft_printf(BRIGHT_RED
			"%s MUST HAVE 1 ARGUMENT!\n" RESET, argv[0]);
		exit(EXIT_FAILURE);
	}
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handle_binary_to_str;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf(BRIGHT_GREEN "Server PID: %u\n" RESET, getpid());
	while (1)
		pause();
	return (0);
}
