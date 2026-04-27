# 🎓 Sistema de Cadastro de Alunos em C

## 📚 Sobre o Projeto

Projeto final desenvolvido para aplicar de forma integrada os principais conteúdos estudados na disciplina de **Fundamentos de Programação**.

O sistema simula o gerenciamento básico de alunos, permitindo cadastrar, consultar, editar e remover registros, além de calcular a média geral da turma e salvar os dados em arquivo.

A proposta é utilizar uma aplicação simples, mas suficiente para reunir os fundamentos da programação procedural em linguagem C.

---

## 🎯 Objetivos do Projeto

* Aplicar os conceitos fundamentais da linguagem C
* Desenvolver raciocínio lógico aplicado
* Organizar dados utilizando estruturas
* Trabalhar com funções e controle de fluxo
* Persistir informações em arquivos

---

## ⚙️ Funcionalidades

* 📌 Cadastro de alunos
* 📌 Listagem de alunos
* 📌 Busca por matrícula
* 📌 Edição de informações
* 📌 Remoção de alunos
* 📌 Cálculo da média da turma
* 📌 Salvamento em arquivo

---

## 🧱 Estrutura do Projeto

```bash id="5d7u2w"
sistema_cadastro_alunos/
│
├── README.md
├── main.c
└── dados.txt
```

---

## 🧠 Estrutura de Dados Utilizada

```c id="x8z2b7"
typedef struct {
    char nome[100];
    int matricula;
    float nota;
    float frequencia;
} Aluno;
```

---

## 📌 Conceitos Aplicados

### ✅ Variáveis e tipos primitivos

### ✅ Estruturas condicionais

### ✅ Estruturas de repetição

### ✅ Funções

### ✅ Vetores

### ✅ Structs

### ✅ Arquivos

---

## 📈 Relação com a Disciplina

Este projeto integra a progressão natural da matéria:

### Início

* entrada e saída de dados
* operadores
* lógica sequencial

### Intermediário

* decisões
* repetições
* funções

### Avançado

* structs
* vetores
* arquivos

---

## 💾 Persistência de Dados

As informações são armazenadas em arquivo `.txt`, permitindo manter os dados cadastrados mesmo após o encerramento do programa.

---

## 🚀 Como Executar

Compilar:

```bash id="z6f8bt"
gcc main.c -o sistema
```

Executar:

```bash id="9i8e0w"
./sistema
```

No Windows:

```bash id="s2e9vr"
sistema.exe
```

---

## 💡 Possíveis Evoluções Futuras

* Ordenação por nota
* Relatórios automáticos
* Busca mais eficiente
* Separação em módulos
* Interface gráfica futura

---

## 🎓 Importância Acadêmica

Este projeto representa a consolidação dos fundamentos da programação e serve como base para disciplinas futuras como:

* Estruturas de Dados
* Programação Orientada a Objetos
* Algoritmos

---

## 📌 Autor

**JonnyMarcus**

