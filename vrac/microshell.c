#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int	print_error(char *str, char *av, int status)
{
	while (*str)
		write(2, str++, 1);
	while (av && *av)
		write(2, av++, 1);
	write(2, "\n", 1);
	return (status);
}

void	set_pipe(int *fd, int fileno)
{
	if (dup2(fd[fileno], fileno) == -1)
		exit(print_error("error: fatal", NULL, 1));
	close(fd[0]);
	close(fd[1]);
}

int	exec_cd(char **av, int i)
{
	if (i != 2)
		return (print_error("error: cd: bad arguments", NULL, 1));
	if (chdir(av[1]) != 0)
		return (print_error("error: cd: cannot change directory to ", av[1], 1));
	return (0);
}

int	ft_exec(char **av, int i, char **env)
{
	int	fd[2];
	int	pid;
	int	status;

	if (!strcmp(av[0], "cd"))
		return (exec_cd(av, i));
	if (!av[i] || !strcmp(av[i], ";"))
	{
		pid = fork();
		if (pid == -1)
			exit(print_error("error: fatal", NULL, 1));
		if (pid == 0)
		{
			av[i] = NULL;
			execve(av[0], av, env);
			exit(print_error("error: cannot execute ", av[0], 1));
		}
		while (waitpid(-1, &status, 0) != -1)
			;
//		waitpid(pid, &status, 0);
	}
	else if (!strcmp(av[i], "|"))
	{
		if (pipe(fd) == -1)
			exit(print_error("error: fatal", NULL, 1));
		pid = fork();
		if (pid == -1)
			exit(print_error("error: fatal", NULL, 1));
		if (pid == 0)
		{
			av[i] = NULL;
			set_pipe(fd, 1);
			execve(av[0], av, env);
			exit(print_error("error: cannot execute ", av[0], 1));
		}
		set_pipe(fd, 0);
		while (waitpid(-1, &status, 0) != -1)
			;
//		waitpid(pid, &status, 0);
	}
	return (WIFEXITED(status) && WEXITSTATUS(status));
}

int main(int ac, char **av, char **env)
{
	int	i;
	int	status;

	if (ac < 2)
		return (0);
	i = 0;
	while (av[i])
	{
		av += i + 1;
		i = 0;
		while (av[i] && strcmp(av[i], ";") && strcmp(av[i], "|"))
			i++;
		if (i)
			status = ft_exec(av, i, env);
	}
	return (status);
}
