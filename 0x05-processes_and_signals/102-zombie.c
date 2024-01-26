#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * infinite_while - Infinite loop function
 *
 * Return: Always 0
 */
int infinite_while(void)
{
	while (1)
	{
		sleep (1);
	}
	return (0);
}

/**
 * main - entry point that creates 5 zombie processes
 *
 * Return: Always 0
 */
int main(void)
{
	pid_t child_pid;
	char counter = 0;

	while (counter < 5)
	{
		child_pid = fork();
		if (child_pid > 0)
		{
			printf("Zombie process created, PID: %d\n", getpid());
			sleep(1);
			counter++;
		}
		else
			exit(0);
	}
	infinite_while();

	return (EXIT_SUCCESS);
}
