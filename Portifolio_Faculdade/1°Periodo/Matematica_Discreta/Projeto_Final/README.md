# 📘 Discrete Math Toolkit — C Edition

Ferramenta em **C** que reúne operações fundamentais de Matemática Discreta — conjuntos, relações, lógica proposicional e grafos — num único sistema modular, com histórico de operações persistido em arquivo.

<p align="left">
  <img src="https://img.shields.io/badge/C-A8B9CC?logo=c&logoColor=white" alt="C">
  <img src="https://img.shields.io/badge/Grafos%20%28DFS%20%2F%20BFS%29-lightgrey" alt="Grafos">
</p>

## 📖 Sobre

O sistema aplica na prática os conteúdos teóricos da disciplina, permitindo operar com conjuntos, relações matemáticas, lógica proposicional e grafos, registrando automaticamente as operações realizadas durante a execução.

## 🎯 Objetivo

Aplicar conceitos teóricos de Matemática Discreta através da implementação de algoritmos em C, consolidando programação estruturada, modularização, manipulação de arquivos e estruturas de dados.

## ⚙️ Funcionalidades

| Módulo                   | Operações                                                                                   | Conceitos aplicados                         |
| ------------------------ | ------------------------------------------------------------------------------------------- | ------------------------------------------- |
| **Conjuntos**            | União · interseção · diferença · diferença simétrica · verificação de pertinência           | Vetores, funções, estruturas de controle    |
| **Relações**             | Produto cartesiano · verificação de reflexividade, simetria, antissimetria e transitividade | Matrizes, algoritmos de verificação         |
| **Lógica Proposicional** | AND, OR, NOT, XOR, implicação, bicondicional · geração de tabela-verdade                    | Operadores lógicos, manipulação binária     |
| **Grafos**               | Criação de grafos · inserção de vértices/arestas · grau de vértices · DFS · BFS             | Matriz e lista de adjacência, filas, pilhas |
| **Histórico**            | Salvar, consultar e limpar histórico de operações                                           | Manipulação de arquivos texto               |

## 📂 Estrutura do projeto

```text
Matematica_Discreta_C/
├── main.c
├── conjuntos.c / conjuntos.h
├── relacoes.c / relacoes.h
├── logica.c / logica.h
├── grafos.c / grafos.h
├── historico.c / historico.h
├── utils.c / utils.h
├── historico.txt
├── Makefile
└── README.md
```

## 🛠️ Tecnologias

C · GCC · Makefile

## ▶️ Como executar

```bash
make
./matematica_discreta
```

ou, sem Makefile:

```bash
gcc *.c -o matematica_discreta
./matematica_discreta
```

## 📈 Evolução do projeto

1. Operações com conjuntos
2. Relações matemáticas
3. Lógica proposicional
4. Implementação de grafos
5. Persistência de dados (histórico)
6. Organização modular do código

## 🎓 Conceitos de programação aplicados

Programação estruturada · modularização · arquivos header (`.h`) · ponteiros · vetores e matrizes · manipulação de arquivos · algoritmos matemáticos

## 👨‍💻 Autor

**Jonny Marcus**
Estudante de Ciência da Computação apaixonado por programação, algoritmos e matemática computacional.
