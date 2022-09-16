/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 17:45:18 by muganiev          #+#    #+#             */
/*   Updated: 2022/09/16 17:09:10 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
 int main()
 {
	 while (1)
	 {
		 printf("cycle %d\n", getpid());
		 sleep(1);
	 }
	 
 }