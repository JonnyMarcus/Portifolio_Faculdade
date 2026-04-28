# 🎓 Sistema de Cadastro de Alunos em C

## 📚 Sobre o Projeto

Projeto final desenvolvido para aplicar de forma integrada os principais conteúdos estudados na disciplina de **Fundamentos de Programação**.

O sistema simula o gerenciamento básico de alunos, permitindo cadastrar, consultar, editar, remover registros, calcular médias e armazenar os dados em arquivo.

A proposta é reunir, em uma aplicação única, os principais fundamentos da programação procedural em linguagem C.

---

## 🎯 Objetivos do Projeto

* aplicar os conceitos fundamentais da linguagem C
* desenvolver raciocínio lógico aplicado
* organizar dados utilizando estruturas
* trabalhar com funções e controle de fluxo
* persistir informações em arquivos

---

## ⚙️ Funcionalidades

* 📌 cadastro de alunos
* 📌 listagem de alunos
* 📌 busca por matrícula
* 📌 edição de informações
* 📌 remoção de alunos
* 📌 cálculo da média da turma
* 📌 exibição da situação do aluno (aprovado, recuperação ou reprovado)
* 📌 salvamento em arquivo
* 📌 carregamento automático dos dados
* 📌 ordenação por nome

---

## 🧱 Estrutura do Projeto

```bash
sistema_cadastro_alunos/
│
├── README.md
├── main.c
└── alunos.txt
```

---

## 🧠 Estrutura de Dados Utilizada

```c
typedef struct aluno{
    char nome[100];
    int matricula;
    float nota_1;
    float nota_2;
    float media;
} Aluno;
```

---

## 📌 Conceitos Aplicados

### ✅ variáveis e tipos primitivos

### ✅ estruturas condicionais

### ✅ estruturas de repetição

### ✅ funções

### ✅ vetores

### ✅ structs

### ✅ ponteiros

### ✅ manipulação de strings

### ✅ arquivos

### ✅ ordenação de dados

---

## 📈 Relação com a Disciplina

Este projeto integra a progressão natural da disciplina:

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
* ponteiros
* arquivos

---

## 🖥️ Exemplo do Menu

```text
===== SISTEMA DE CADASTRO DE ALUNOS =====
1 - Cadastrar aluno
2 - Listar alunos
3 - Buscar aluno
4 - Calcular média da turma
5 - Editar aluno
6 - Remover aluno
7 - Salvar alunos em arquivo
8 - Ordenar alunos por nome
0 - Sair
```

---

## 💾 Persistência de Dados

As informações são armazenadas no arquivo:

```text
alunos.txt
```

Isso permite manter os dados cadastrados mesmo após o encerramento do programa.

---

## 🚀 Como Executar

Compilar:

```bash
gcc main.c -o sistema
```

Executar:

```bash
./sistema
```

No Windows:

```bash
sistema.exe
```

---

## 💡 Possíveis Evoluções Futuras

* modularização em múltiplos arquivos `.c` e `.h`
* ordenação por média
* geração de relatórios automáticos
* uso de alocação dinâmica
* interface gráfica futura

---

## 🎓 Importância Acadêmica

Este projeto representa a consolidação dos fundamentos da programação e serve como base para disciplinas futuras como:

* Estruturas de Dados
* Programação Orientada a Objetos
* Algoritmos

---

## 📌 Autor

**JonnyMarcus**
