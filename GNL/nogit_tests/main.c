/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-l <dgomez-l@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 12:38:15 by dgomez-l          #+#    #+#             */
/*   Updated: 2024/02/29 12:38:17 by dgomez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

// cc -Wall -Wextra -Werror -g3 *.c ./nogit_tests/*.c
int	main(void)
{
	int		fd1;
	int		fd2;
	int		fd3;
	char	*test;

	fd1 = open("./nogit_tests/variable_test.txt", O_RDWR);
	fd2 = open("./nogit_tests/variable_test.txt", O_RDWR);
	fd3 = open("./nogit_tests/variable_test.txt", O_RDWR);
	test = get_next_line(fd1);
	printf("test fd1 1: %s\n", test);
	free(test);
	test = get_next_line(fd2);
	printf("test fd2 1: %s\n", test);
	free(test);
	test = get_next_line(fd3);
	printf("test fd3 1: %s\n", test);
	free(test);
	test = get_next_line(fd1);
	printf("test fd1 2: %s\n", test);
	free(test);
	test = get_next_line(fd2);
	printf("test fd2 2: %s\n", test);
	free(test);
	test = get_next_line(fd3);
	printf("test fd3 2: %s\n", test);
	free(test);
	test = get_next_line(fd1);
	printf("test fd1 3: %s\n", test);
	free(test);
	test = get_next_line(fd2);
	printf("test fd2 3: %s\n", test);
	free(test);
	test = get_next_line(fd3);
	printf("test fd3 3: %s\n", test);
	free(test);
	close(fd1);
	close(fd2);
	close(fd3);
	test = get_next_line(fd1);
	printf("test fd1 close: %s\n", test);
	free(test);
	test = get_next_line(fd2);
	printf("test fd2 close: %s\n", test);
	free(test);
	test = get_next_line(fd3);
	printf("test fd3 close: %s\n", test);
	free(test);
	system("leaks a.out");
	return (0);
}
