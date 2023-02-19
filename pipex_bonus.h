/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex_bonus.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: psadeghi <psadeghi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/31 10:32:53 by psadeghi      #+#    #+#                 */
/*   Updated: 2023/02/15 16:38:43 by psadeghi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <errno.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_bonus
{
	int		forkindex;
	int		secondpipe[2];
	int		file[2];
	int		ends[2];
	int		pid_status;
	int		command_count;
	char	**command_bonus;
	int		commandnumber;
	int		fork_id[2088];
	char	*access_result;
	char	*limiter_newline;
	char	*line;
}			t_bonus;
char	*get_next_line(int fd);
char	*read_and_save(int fd, char *stash);
char	*find_char(char *str, char p);
char	*join_stash_and_buffer(char *stash, char *buffer);
char	*get_new_stash(char *stash);
char	*print_line(char	*stash);
char	*ft_substr_gnl(char	*s, unsigned int start, size_t	len);
char	*ft_strdup_gnl(char *str);
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
void	ft_argc_bonus(int argc, char **argv);
void	ft_firstcommand_bonus(char **envp, char **argv, t_bonus b, int fork_id);
void	ft_lastcommand_bonus(int argc, char **envp, char **argv, t_bonus *b);
void	ft_close_bonus(t_bonus *b, int i, char **argv);
void	ft_errorprocess(int i);
void	ft_errorallacate(int i);
char	*ft_freeall(char **str);
void	ft_middlecommands_bonus(int argc, char **argv, char **envp, t_bonus *b);
int		ft_strcmp(char	*s1, char	*s2);
void	ft_first_heredoc(char **argv, char **envp, t_bonus b, int fork_id);
void	ft_second_heredoc(char **envp, char **argv, t_bonus b, int fork_id);
void	ft_excm_bonus(char **envp, char *command, t_bonus b);
int		ft_first_bonus(int argc, char **argv, char **envp, t_bonus b);
void	ft_firstchild_heredoc(char **argv, t_bonus b);
void	ft_errorunsetpath(char *command);
void	ft_free_access(char **address, char *path, char *str);
int		ft_second_bonus(char **argv, char **envp, t_bonus b);
void	ft_excm_1bonus(char **envp, char *command, t_bonus *b);

#endif