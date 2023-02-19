/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: psadeghi <psadeghi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/03 15:11:02 by psadeghi      #+#    #+#                 */
/*   Updated: 2023/02/14 11:44:40 by psadeghi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stddef.h>
# include <errno.h>

typedef struct s_pipex
{
	int		file[2];
	int		ends[2];
	int		pid1;
	int		pid2;
	int		pid_status;
	char	**command1;
	char	**command2;
}			t_pipex;
int		main(int argc, char *argv[], char *envp[]);
char	**ft_split(char	*s, char c);
char	*ft_substr(char	*s, unsigned int start, size_t	len);
char	*ft_strnstr(const char	*haystack, const char	*needle, size_t	len);
size_t	ft_strlen(char *str);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_access(char *command, char *path);
char	*ft_path(char **envp);
char	*ft_strchr(const char *s, int c);
int		ft_checkquote(char *s);
void	*ft_calloc(size_t	count, size_t	size);
void	ft_errorcommand(char *command);
void	ft_errorfile(char *file, int i);
void	ft_errofunction(int i);
void	ft_argument(int argc);
void	ft_firstfork(char **envp, char **argv, t_pipex p);
void	ft_secondfork(char **envp, char **argv, t_pipex p);
void	ft_errorprocess(int i);
void	ft_close(t_pipex p);
char	*ft_freeall(char **str);
void	ft_errorallacate(int i);
void	ft_errorunsetpath(char *command);
void	ft_free_access(char **address, char *path, char *str);

#endif