
# seu objetivo é definir regras de compilação para projetos de software. As regras são definidas
# em um arquivo chamado 'Makefile'. O programa 'make' interpreta o conteúdo do makefile e executa 
# as regras lá definidas.

# As variáveis precisam estar MAIÚSCULAS.	
# Precisa de '$' antes das variáveis, e esta precisa estar entre parênteses.

# 'NAME' = variável; 'libft.a' = nome do executável.
NAME = libft.a

# 'SRC`é a variável que vai reunir todas as fontes 'C' que quero compilar. 
SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
ft_strlen.c ft_tolower.c ft_toupper.c ft_atoi.c ft_memset.c ft_bzero.c \
ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strchr.c ft_strrchr.c ft_memcmp.c \
ft_strncmp.c ft_strnstr.c ft_calloc.c ft_memchr.c ft_strdup.c ft_substr.c \
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_strjoin.c ft_strmapi.c \
ft_strtrim.c ft_strlcat.c ft_split.c ft_putnbr_fd.c ft_itoa.c ft_striteri.c \

OBJS = $(SRC:.c=.o) 
#em 'src', pego tudo que é .c e transformo em .o

# o 'all' usa o mesmo nome do programa alvo. Se executar somente 'make', ele vai rodar 
# a primeira regra do 'Makefile'. Então, coloco 'all'. É uma convenção que chama a regra
# que iniciará a compilação.
all: $(NAME)

# O "ar" (archiver) junta todos os -arquivos-objeto em uma biblioteca estática chamada "libft.a"
# A flags -r, insere o arquivo membro no arquivo (com substituição) / -c, criar o arquivo, e quando
# se atualiza, cria o arquivo se ele não existir / -s, escreve um índice de ficheiro objeto no arquivo, 
# ou atualiza um já existente, mesmo que nenhuma outra alteração seja feita no arquivo. 
# -usamos a ar para compactar no arquivo (libft.a) local, os arquivos da SRCS
# Como a regra está subordinada ao 'name' e aos 'objs' ela só ocorre se houve modificações nestes, evitando o relink;

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

# É complilado usando o compilador gcc e usamos as flags -Wall -Wextra -Werror, que possibilita os avisos de erro;
# Para cada arquivo.c um arquivo OBJETO e criado com a extensão ".o" arquivo.o;
# '-c' diz para não executar o linker, então ela forma os .o;
# O '@' não deixa a regra aparecer na linha de comando quando o make estiver rodando;

$(OBJS):
	gcc -Wall -Werror -Wextra -c $(@:.o=.c) -o $@ 
# o '$(@:.o=.c) pega tudo que é .o e trasforma em .c; E $@ indica qual o alvo da regra, que no caso é -o

# O 'Clean', 'fclean' e o 're' são regras utilitárias.

# 'Clean' limpará todos os arquivos objetos (.o) gerados durante a compilação. Ele tb serve para limpar
# outros arquivos inúteis (ex: "~").
clean:
	/bin/rm -f *.o

# 'fclean' sempre vai depender do 'clean'. Esta regra adiciona a exclusão do executável gerado.
fclean: clean
	/bin/rm -f $(NAME)

# 're' permite um reset da compilação, ou seja, começar tudo novamente em um ambiente limpo. Por isso,
# primeiro chamo o 'fclean' do qual ele depende, depois chamo o ALL. Tudo será limpo e então meu programa
# será compilado novamente.
re: fclean all

# 'PHONE' serve para evitar conflitos. é uma proteção, se houver um arqiuvo com o mesmo nome de uma das regras, 
# a regra deve ser executada, mesmo se existirem arquivos com o nome dela.
.PHONY : all clean fclean re #SÓ PRA EXPLICITAR QUE TODAS AS REGRAS SÃO CRIAÇÕES MINHAS DO MEU MAKEFILE E NÃO DO SISTEMA.
