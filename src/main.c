#include "../include/minishell.h"

t_lines	main_struct;

char	*rl_gets(char *str, const char *prompt)
{
	if (str)
	{
		free(str);
		str = NULL;
	}
	str = readline(prompt);
	if (str && *str)
		add_history(str);
	return (str);
}

// void	find_path(t_lines *ptr)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (ptr->commands[i])
// 	{
// 		while ()
// 		i++;
// 	}
// }

void	format_command(t_lines *ptr)
{
	int	i;

	i = 0;
	ptr->piped = ft_split(ptr->line_read, '|');
	while (ptr->piped[i])
		i++;
	ptr->commands = malloc(sizeof(char **) * (i + 1));
	ptr->commands[i + 1] = NULL;
	i = 0;
	while (ptr->piped[i])
	{
		ptr->commands[i] = ft_split(ptr->piped[i], ' ');
		i++;
	}
	// find_path(ptr);
	i = 0;
	while (ptr->commands[i])
	{
		ptr->commands[i][0] = ft_strjoin("/usr/bin/", ptr->commands[i][0]);
		if (fork() != 0)
			wait(NULL);
		else
			execve(ptr->commands[i][0], ptr->commands[i], 0);
		i++;
	}
}

void	init_struct(t_lines *ptr)
{
	ptr->paths = ft_split(getenv("PATH"), ':');
}

void	loop()
{
	while (1)
	{
		main_struct.line_read = rl_gets(main_struct.line_read, "Ta sh : ");
		if (!strcmp("exit", main_struct.line_read))
			break;
		format_command(&main_struct);
	}
	// free(main_struct.line_read);
}

void	sighandler(int sig)
{
	loop();
}


int	main(void)
{
	char	**ptr;

	signal(SIGINT, &sighandler);
	main_struct.paths = ft_split(getenv("PATH"), ':');
	main_struct.line_read = NULL;
	loop();
	return (0);
}
