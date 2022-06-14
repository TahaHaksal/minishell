#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <signal.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "../Libft/Libft/libft.h"

typedef struct s_history
{
	char				*str;
	struct s_history	*next;
}				t_history;

typedef struct s_lines
{
	char	**paths;
	char	*line_read;
	char	**piped;
	char	***commands;
}			t_lines;

//List utilities
void		list_prepend(t_history **lst, t_history *new);
void		list_clear(t_history **lst);
t_history	*list_new(char *str);

//Other utilities
int	ft_chrcnt(char *ptr, char needle);

#endif
