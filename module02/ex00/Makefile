# **************************************************************************** #
#       COMANDS                                                                #
# **************************************************************************** #
CPP			=	c++
RM			=	rm -rf

# **************************************************************************** #
#       TITLE                                                                  #
# **************************************************************************** #
NAME			=	Fixed

# **************************************************************************** #
#       FLAGS                                                                  #
# **************************************************************************** #
CFLAGS			=	-Wall -Wextra -Werror
STD			=	-std=c++98
FSAN			=	-fsanitize=address
DEBUG			=	-g3 -O0

# **************************************************************************** #
#       SOURCES                                                                #
# **************************************************************************** #
SRCS			=	main.cpp \
				Fixed.cpp \

# **************************************************************************** #
#       LIBRARIES                                                              #
# **************************************************************************** #

# **************************************************************************** #
#       RULES                                                                  #
# **************************************************************************** #
OBJS			=	$(SRCS:.cpp=.o)

%.o				:	%.cpp
					$(CPP) $(CFLAGS) $(STD) -c $< -o $@

$(NAME)			:	$(OBJS)
					$(CPP) $(CFLAGS) $(STD) -o $@ $(OBJS)

all				:	$(NAME)

debug			:	$(OBJS)
					$(CPP) $(CFLAGS) $(STD) -o $@ $(OBJS) $(FSAN) $(DEBUG)

clean			:
					$(RM) $(OBJS)

fclean			:	clean
					$(RM) $(NAME)
					$(RM) debug

re				:	fclean all

# **************************************************************************** #
#       PHONY                                                                  #
# **************************************************************************** #
.PHONY			:	all clean fclean re
