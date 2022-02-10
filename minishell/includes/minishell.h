#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <curses.h>
# include <term.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/errno.h>
# include <string.h>
# include "libft.h"

# define WORD 0
# define PIPE 1
# define REDIR_L 2
# define REDIR_LL 3
# define REDIR_R 4
# define REDIR_RR 5

typedef struct s_token
{
	int		type;
	char	*val;
}	t_token;

// main
char	*get_ev_name(char *str);

// expand 
void	expand_ev(char **line, char **env);
char	*str_insert(char *dst, const char *src, size_t n);
char	*trunc_str(char *str, int start, int len);
char	*get_str_truncated(const char *str, int start, int len);
void	my_strncpy(char *dst, const char *src, int n);
int		ft_strcmp(char *s1, char *s2);

// strs
char	**copy_strs(char **strs);
void	free_strs(char **strs);
int		strs_len(char **strs);
char	*strs_join(char **strs1, char **strs2);
char	**strs_append(char **strs, const char *str);
char	*strs_chr(char **strs, char *s);

// error
void	exit_error(char *msg, int code);
void	return_error(char *msg, int code);
void	print_error(char *msg);

// dev
void	print_strs(char **strs);
void	print_tokens(t_list *tokens);

#endif