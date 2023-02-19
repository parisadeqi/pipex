# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: psadeghi <psadeghi@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/01/03 15:02:17 by psadeghi      #+#    #+#                  #
#    Updated: 2023/02/14 17:16:54 by psadeghi      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = pipex
BNAME = pipex_bonus
CC = gcc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs

SRCS = main.c ft_split.c ft_strnstr.c ft_strdup.c ft_strlen.c ft_substr.c ft_access.c ft_strjoin.c ft_strchr.c\
		ft_checkquote.c ft_calloc.c ft_errorcommand.c ft_errorfile.c ft_argument.c ft_firstfork.c ft_errorprocess.c\
		ft_secondfork.c ft_close.c ft_errorallocate.c ft_freeall.c ft_errorfunction.c ft_errorunsetpath.c\

BSRCS = main_bonus.c ft_split_bonus.c ft_strnstr_bonus.c ft_strdup_bonus.c ft_strlen_bonus.c ft_substr_bonus.c ft_access_bonus.c ft_strjoin_bonus.c ft_strchr_bonus.c\
		ft_checkquote_bonus.c ft_calloc_bonus.c ft_errorcommand_bonus.c ft_errorfile_bonus.c ft_errorprocess_bonus.c ft_errorallocate.c\
		ft_close_bonus.c ft_argc_bonus.c ft_firstcommand_bonus.c ft_lastcommand_bonus.c ft_freeall_bonus.c\
		ft_gnl_bonus.c ft_gnl_utils_bonus.c ft_strcmp_bonus.c ft_heredoc_bonus.c ft_excm_bonus.c ft_first_bonus.c ft_errorfunction_bonus.c ft_errorunsetpath_bonus.c\


OBJFILES=$(SRCS:%.c=%.o)
BOBJFILES=$(BSRCS:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJFILES)
	$(CC) $(OBJFILES) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

bonus : $(BNAME)

$(BNAME) : $(BOBJFILES)
	$(CC) $(BOBJFILES) -o $(BNAME)
	cp $(BNAME) $(NAME)

clean :
	rm -f $(OBJFILES) $(BOBJFILES)

fclean :
	rm -rf $(OBJFILES) $(BOBJFILES) $(NAME) $(BNAME)

re : fclean all

.PHONY : all clean fclean re bonus