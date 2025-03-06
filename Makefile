# Variáveis
CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# Diretórios
SRC_DIR = src
OBJ_DIR = obj

# Arquivos fontes e objetos
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Nome dos executáveis
EXEC_GC = gc
EXEC_TEST_BASIC = test_basic
EXEC_TEST_STRESS = test_stress

# Regra default
all: $(EXEC_GC)

# Regra para compilar o programa principal (gc)
$(EXEC_GC): $(OBJ) $(SRC_DIR)/main.c
	$(CC) $(CFLAGS) -o $(EXEC_GC) $(OBJ) $(SRC_DIR)/main.c

# Regra para compilar o teste básico
test_basic: $(OBJ) $(SRC_DIR)/test_basic.c
	$(CC) $(CFLAGS) -o $(EXEC_TEST_BASIC) $(OBJ) $(SRC_DIR)/test_basic.c

# Regra para compilar o teste de estresse
test_stress: $(OBJ) $(SRC_DIR)/test_stress.c
	$(CC) $(CFLAGS) -o $(EXEC_TEST_STRESS) $(OBJ) $(SRC_DIR)/test_stress.c

# Regra para compilar os arquivos .c da pasta src, excluindo main.c, test_basic.c e test_stress.c
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpar os arquivos compilados
clean:
	rm -f $(EXEC_GC) $(EXEC_TEST_BASIC) $(EXEC_TEST_STRESS) $(OBJ_DIR)/*.o

.PHONY: all test_basic test_stress clean
