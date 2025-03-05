# Collectors
## Garbage Collector em C

## Visão Geral
Este projeto implementa um **Garbage Collector** (GC) utilizando a técnica *Mark-and-Sweep* para gerenciamento automático de memória em programas escritos em **C**. O GC rastreia a alocação de objetos, identifica aqueles ainda em uso e libera memória de objetos não referenciados.

## Estrutura do Projeto
A estrutura do projeto foi organizada para manter um código modular e de fácil manutenção.

```
garbage_collector/
├── include/
│   ├── gc.h
│   ├── memory.h
│   ├── object.h
│   └── utils.h
├── src/
│   ├── gc.c
│   ├── memory.c
│   ├── object.c
│   ├── utils.c
│   └── main.c
├── tests/
│   ├── test_basic.c
│   └── test_stress.c
└── Makefile
```

### 📂 `include/` - Arquivos de Cabeçalho
- **gc.h**: Declara as funções principais do GC, incluindo `gc_init`, `gc_alloc`, `gc_mark`, `gc_sweep`, `gc_run` e `gc_shutdown`.
- **memory.h**: Define a estrutura `MemoryBlock` e funções de alocação (`mem_alloc`) e liberação de memória (`mem_free`).
- **object.h**: Contém a estrutura `Object` e funções para criar (`object_create`) e conectar (`object_link`) objetos.
- **utils.h**: Funções auxiliares como `log_message` para depuração e `check_null` para validação de ponteiros.

### 📂 `src/` - Implementação do GC
- **gc.c**: Implementa o funcionamento do *Mark-and-Sweep*.
- **memory.c**: Implementa a lógica de alocação/liberação de memória.
- **object.c**: Gerencia a criação e conexão de objetos.
- **utils.c**: Funções auxiliares para depuração.
- **main.c**: Ponto de entrada do programa, onde o GC é testado.

### 📂 `tests/` - Testes
- **test_basic.c**: Testa funcionalidades básicas do GC.
- **test_stress.c**: Teste de estresse com grande volume de objetos.

## 🚀 Como Compilar e Executar
O projeto utiliza um **Makefile** para automatizar a compilação.

### 🔨 Compilar o projeto principal:
```sh
make
```
Isso gera o executável `gc`.

### 🧪 Compilar e rodar testes:
```sh
make test_basic
./test_basic

make test_stress
./test_stress
```

### 🧹 Limpar arquivos gerados:
```sh
make clean
```

## 📌 Tecnologias Utilizadas
- **Linguagem:** C
- **Compilador:** GCC
- **Ferramentas:** Makefile para automação

## 📝 Licença
Este projeto está sob a licença MIT. Sinta-se livre para usá-lo e modificá-lo.

---
🔥 **Autor:** *Felipe Panosso*  
💡 **Objetivo:** Aprendizado e implementação de conceitos avançados de gerenciamento de memória em C.

