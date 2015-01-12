# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apergens <apergens@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 12:04:58 by svachere          #+#    #+#              #
#    Updated: 2015/01/11 19:28:25 by apergens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_retro
CC = g++
CFLAGS = -Wall -Wextra -Werror -g3
SRCSFILES = \
			AEntity.class.cpp \
			Display.class.cpp \
			Game.class.cpp \
			Input.class.cpp \
			Player.class.cpp \
			Enemy.class.cpp \
			Missile.class.cpp \
			Hud.class.cpp \
			main.cpp
SRCSDIR = srcs/
SRCS = $(addprefix $(SRCSDIR), $(SRCSFILES))
OBJSDIR = objs/
OBJSFILES = $(SRCSFILES:.cpp=.o)
OBJS = $(addprefix $(OBJSDIR), $(OBJSFILES))
HEADERSFILES = \
			AEntity.class.hpp \
			Display.class.hpp \
			Game.class.hpp \
			Input.class.hpp \
			Player.class.hpp \
			Enemy.class.hpp \
			Missile.class.hpp \
			Hud.class.hpp
HEADERS = $(addprefix $(SRCSDIR), $(HEADERSFILES))
HEADERFLAGS = $(addprefix -I, $(dir $(HEADERS)))
LIBS = -lncurses

all: $(NAME)

$(NAME): $(OBJSDIR) $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LIBS)

$(OBJSDIR):
	mkdir $(OBJSDIR)

$(OBJSDIR)%.o: $(SRCSDIR)%.cpp $(HEADERS)
	$(CC) $(CFLAGS) $(HEADERFLAGS) -c -o $@ $<

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
