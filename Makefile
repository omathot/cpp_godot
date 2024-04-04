#---------------------------------
#VARIABLES

NAME 	:= plug_comp
REMOVE	:= srcs/*.os
SRC		:= src/*.cpp
CMP		:= scons
OS 		:= $(shell uname -m)
GD_PATH	= poop
PLATFORM = placeholder
_SUCCESS := "\033[32m[%s]\033[0m %s\n" # Green text for "printf"
_ERROR := "\033[31m[%s]\033[0m %s\n" # Red text for "printf"
ans		= prout


#---------------------------------
#OS CHECK

ifeq ($(OS), arm64)
	PLATFORM = macos
	GD_PATH = ~/../../Applications/Godot_mono.app/Contents/MacOS/Godot
else ifeq ($(OS), x86_64)
	PLATFORM = linux
endif

#---------------------------------
#FORMATTING AND FUN

clear_line = \033[K
move_up = \033[A
define prettycomp
	@printf "$(1)$(clear_line)\n"
	@$(1)
	@printf "$(move_up)"
endef

RED		:= \033[31m
GREEN 	:= \033[32m
YELLOW	:= \033[33m
BLUE	:= \033[38;5;87m
MAGENTA := \033[35m
CYAN	:= \033[36m
RESET	:= \033[0m

#---------------------------------
#RULES

all	: $(NAME)
		

$(NAME) : 
		scons platform=$(PLATFORM)
		open -a iTerm -n test.sh

redo :
		@echo -n "Are you sure? [Y/n] " && read ans && if [ $${ans:-'Y'} = 'n' ]; then \
       		printf $(_ERROR) "KO" "Stopping" ; \
        	exit 1 ; \
    	else \
        	printf $(_SUCCESS) "OK" "Continuing" ; \
        	exit 0; \
    	fi
		killall Godot
		scons platform=$(PLATFORM)
		open -a iTerm -n test.sh

#./Godot -e --path /Users/oscarmathot/Construction/gdextension_cpp_example/demo/


clean :
		@rm -f $(REMOVE)
		@echo "$(GREEN)Cleaned up the artifacts !$(RESET)"

fclean :
		@make clean

hardclean :
		@make fclean

re : fclean all

.PHONY : clean fclean re hardclean