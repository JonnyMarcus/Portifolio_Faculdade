# 💻 Simulador de Conversão Numérica e Memória

Projeto em **C** que aplica, na prática, os conceitos de sistemas de numeração, representação da informação e organização básica de memória estudados em **Arquitetura de Computadores I**.

<p align="left">
  <img src="https://img.shields.io/badge/C-A8B9CC?logo=c&logoColor=white" alt="C">
  <img src="https://img.shields.io/badge/Convers%C3%A3o%20Num%C3%A9rica-lightgrey" alt="Conversão Numérica">
  <img src="https://img.shields.io/badge/Status-conclu%C3%ADdo-brightgreen" alt="Status">
</p>

## 📖 Sobre

Computadores trabalham internamente em formato binário. Este projeto demonstra como números são convertidos, armazenados e interpretados pelo hardware, tornando tangíveis conceitos fundamentais de representação de dados e organização de memória.

## 🎯 Objetivos

- Aplicar conceitos de sistemas de numeração e algoritmos de conversão entre bases
- Entender como números são representados digitalmente
- Relacionar bits, bytes e capacidade de armazenamento
- Simular conceitos básicos de endereçamento e memória

## ⚙️ Funcionalidades

| Categoria             | Operações                                                                                                                      |
| --------------------- | ------------------------------------------------------------------------------------------------------------------------------ |
| Conversões numéricas  | Decimal ↔ Binário · Decimal ↔ Octal · Decimal ↔ Hexadecimal · Binário ↔ Octal · Binário ↔ Hexadecimal                          |
| Operações binárias    | Soma binária simples · cálculo da quantidade de bits necessários · conversão entre bits e bytes                                |
| Simulações de memória | Estimativa do espaço ocupado em memória · simulação simples de endereçamento · visualização da representação binária dos dados |

## 💡 Exemplo de uso

```text
Entrada:
Número decimal: 25

Saída:
Decimal: 25 | Binário: 11001 | Octal: 31 | Hexadecimal: 19
Bits necessários: 5 | Bytes ocupados: 1
```

## 📂 Estrutura do projeto

```text
simulador_numerico_memoria/
├── main.c
├── conversoes.c / conversoes.h
├── memoria.c / memoria.h
├── utils.c / utils.h
└── README.md
```

## 🛠️ Tecnologias

C (`stdio.h`, `stdlib.h`, `math.h`), programação estruturada e modularização do código.

## ▶️ Como executar

```bash
gcc *.c -o simulador
./simulador          # Linux/macOS
simulador.exe        # Windows
```

## 🗺️ Possíveis melhorias

<<<<<<< HEAD
Linux:

```bash
./simulador
```

Windows:

```bash
simulador.exe
```

---

## 🎓 Importância Acadêmica

Este projeto foi desenvolvido para consolidar os conceitos fundamentais de Arquitetura de Computadores, proporcionando uma visão prática da representação e manipulação de dados em sistemas computacionais.

Além disso, o projeto reforça conhecimentos em:

- Programação em C;
- Estruturas e funções;
- Modularização;
- Manipulação de dados;
- Algoritmos de conversão;
- Organização interna dos computadores.

## 👨‍💻 Autor

**Jonny Marcus**
Estudante de Ciência da Computação, utilizando projetos práticos para aprofundar conhecimentos em programação e arquitetura de computadores.
