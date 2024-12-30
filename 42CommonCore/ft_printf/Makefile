# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bjose-va <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 15:11:40 by bjose-va          #+#    #+#              #
#    Updated: 2024/12/21 17:10:13 by bjose-va         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variáveis do projeto
SRCS =	ft_printf.c
		
OBJS			= $(SRCS:.c=.o)
LIBFT			= ./libft/libft.a
					
CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= libftprintf.a

# Regras principais
all:			libft $(NAME)

libft:
				@make -C ./libft

$(NAME): $(OBJS)
				@cp $(LIBFT) $(NAME)
				@ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)
				@make clean -C ./libft

fclean:			clean
				$(RM) $(NAME)
				$(RM) tester.c
				$(RM) test_ftprintf
				@make fclean -C ./libft

re:				fclean all

# Regra para criar o arquivo tester.c automaticamente
tester.c:
	@echo "#include \"ft_printf.h\"" > tester.c
	@echo "#include <stdio.h>" >> tester.c
	@echo "" >> tester.c
	@echo "int main(void)" >> tester.c
	@echo "{" >> tester.c
	@echo "    // Testes com strings" >> tester.c
	@echo "    ft_printf(\"String: %s\\n\", \"Olá, mundo!\");" >> tester.c
	@echo "    printf(\"String com original: %s\\n\", \"Olá, mundo!\");" >> tester.c
	@echo "" >> tester.c
	@echo "    // Testes com inteiros" >> tester.c
	@echo "    ft_printf(\"Número inteiro: %d\\n\", 42);" >> tester.c
	@echo "    printf(\"Número inteiro com original: %d\\n\", 42);" >> tester.c
	@echo "    ft_printf(\"Número inteiro negativo: %i\\n\", -42);" >> tester.c
	@echo "    printf(\"Número inteiro negativo com original: %i\\n\", -42);" >> tester.c
	@echo "" >> tester.c
	@echo "    // Testes com caracteres" >> tester.c
	@echo "    ft_printf(\"Caractere: %c\\n\", 'A');" >> tester.c
	@echo "    printf(\"Caractere com original: %c\\n\", 'A');" >> tester.c
	@echo "" >> tester.c
	@echo "    // Testes com números unsigned" >> tester.c
	@echo "    ft_printf(\"Número unsigned: %u\\n\", 4294967295);" >> tester.c
	@echo "    printf(\"Número unsigned com original: %u\\n\", 4294967295);" >> tester.c
	@echo "" >> tester.c
	@echo "    // Testes com hexadecimais" >> tester.c
	@echo "    ft_printf(\"Hexadecimal minúsculo: %x\\n\", 255);" >> tester.c
	@echo "    printf(\"Hexadecimal minúsculo com original: %x\\n\", 255);" >> tester.c
	@echo "    ft_printf(\"Hexadecimal maiúsculo: %X\\n\", 255);" >> tester.c
	@echo "    printf(\"Hexadecimal maiúsculo com original: %X\\n\", 255);" >> tester.c
	@echo "" >> tester.c
	@echo "    // Testes com apontadores" >> tester.c
	@echo "    int a = 42;" >> tester.c
	@echo "    ft_printf(\"Apontador: %p\\n\", &a);" >> tester.c
	@echo "    printf(\"Apontador com original: %p\\n\", &a);" >> tester.c
	@echo "" >> tester.c
	@echo "    // Teste com porcentagem" >> tester.c
	@echo "    ft_printf(\"Porcentagem: %%\\n\");" >> tester.c
	@echo "    printf(\"Porcentagem com original: %%\\n\");" >> tester.c
	@echo "" >> tester.c
	@echo "    return 0;" >> tester.c
	@echo "}" >> tester.c


# Regra para compilar e executar automaticamente
test: tester.c $(NAME)
	@gcc tester.c -L. -lftprintf -o test_ftprintf
	@echo "A carregar o teste..."
	@./test_ftprintf

.PHONY:			all libft clean fclean re test


