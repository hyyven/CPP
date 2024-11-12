SRCS = $(shell find ./ -name '*.cpp')
OBJ_DIR = .Objects
OBJS = $(addprefix $(OBJ_DIR)/,$(SRCS:.cpp=.o))
CC = g++
FLAGS = -Wall -Wextra -Werror -std=c++98
TOTAL_FILES = $(words $(SRCS))
NAME = Megaphone

all: $(NAME)

$(OBJ_DIR)/%.o: %.cpp
	@tput civis
	@mkdir -p $(@D)
	@$(CC) $(FLAGS) -g -c $< -o $@
	@count=$$(find $(OBJ_DIR) -name '*.o' | wc -l); \
	i=1; \
	while [ $$i -le $$count ]; do \
		echo -n "▰"; \
		i=$$((i + 1)); \
	done; \
	while [ $$i -le $(TOTAL_FILES) ]; do \
		echo -n "═"; \
		i=$$((i + 1)); \
	done; \
	echo "  $$((($$count * 100) / $(TOTAL_FILES)))% Compiling $$(basename $<)...\r\c"

$(NAME): $(OBJS)
	@printf "\033[2K\r"
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)
	@echo "   \033[37;42;1m$(NAME) created\033[0m"
	@tput cnorm

run: $(NAME)
	./$(NAME)

clean:
	@rm -rf $(OBJS) $(OBJ_DIR)
	@echo "   \033[41;1mObject file deleted\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "   \033[41;1m$(NAME) deleted\033[0m"

re: fclean all

.SILENT:
.PHONY: all clean fclean re run 
