# 💻 Simulador de Conversão Numérica e Memória

Projeto desenvolvido em **C** com o objetivo de aplicar, de forma prática, conceitos fundamentais estudados em **Arquitetura de Computadores I**, como sistemas de numeração, representação da informação e organização básica de memória.

O sistema permite realizar conversões entre diferentes bases numéricas e simular aspectos relacionados ao armazenamento e representação digital dos dados, aproximando a teoria do funcionamento real dos computadores.

---

## 📚 Sobre o Projeto

Computadores trabalham internamente com informações representadas em formato binário. Este projeto foi desenvolvido para demonstrar como números são convertidos, armazenados e interpretados pelo hardware, permitindo visualizar conceitos fundamentais da arquitetura dos sistemas computacionais.

Além de servir como ferramenta de aprendizado, o projeto busca consolidar conhecimentos sobre representação de dados e organização da memória.

---

## 🎯 Objetivos

- Aplicar conceitos de sistemas de numeração;
- Praticar algoritmos de conversão entre bases;
- Entender como números são representados digitalmente;
- Relacionar bits, bytes e capacidade de armazenamento;
- Simular conceitos básicos de endereçamento e memória.

---

## ✨ Funcionalidades

### 🔢 Conversões Numéricas

- Decimal → Binário
- Decimal → Octal
- Decimal → Hexadecimal
- Binário → Decimal
- Octal → Decimal
- Hexadecimal → Decimal
- Binário → Octal
- Octal → Binário
- Binário → Hexadecimal
- Hexadecimal → Binário

### ➕ Operações Binárias

- Soma binária simples
- Cálculo da quantidade de bits necessários
- Conversão entre bits e bytes

### 🧠 Simulações de Memória

- Estimativa do espaço ocupado em memória
- Simulação simples de endereçamento
- Visualização da representação binária dos dados

---

## 📂 Estrutura do Projeto

```text
simulador_numerico_memoria/
│
├── main.c
├── conversoes.c
├── conversoes.h
├── memoria.c
├── memoria.h
├── utils.c
├── utils.h
└── README.md
```

---

## 🧠 Conceitos Aplicados

### Sistemas de Numeração

- Binário
- Octal
- Decimal
- Hexadecimal

### Representação da Informação

- Bits
- Bytes
- Palavras de memória
- Representação binária

### Aritmética Binária

- Soma binária
- Conversões entre bases

### Organização de Memória

- Endereçamento
- Capacidade de armazenamento
- Representação dos dados em memória

---

## 💡 Exemplo de Funcionamento

### Entrada

```text
Número decimal: 25
```

### Saída

```text
Decimal: 25
Binário: 11001
Octal: 31
Hexadecimal: 19

Bits necessários: 5
Bytes ocupados: 1
```

---

## 📈 Relação com a Disciplina

Este projeto integra conteúdos estudados em:

- Sistemas de Numeração;
- Representação de Dados;
- Organização de Memória;
- Armazenamento Digital;
- Conversão entre Bases;
- Arquitetura de Computadores.

---

## 🛠 Tecnologias Utilizadas

- Linguagem C
- Biblioteca `stdio.h`
- Biblioteca `stdlib.h`
- Biblioteca `math.h`
- Programação Estruturada
- Modularização do código

---

## 🚀 Como Executar

### Compilar

```bash
gcc *.c -o simulador
```

### Executar

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

---

## 👨‍💻 Autor

**Jonny Marcus**

Estudante de Ciência da Computação, utilizando projetos práticos para aprofundar conhecimentos em programação, arquitetura de computadores e desenvolvimento de software.

⭐ Caso este projeto seja útil, considere deixar uma estrela no repositório.
