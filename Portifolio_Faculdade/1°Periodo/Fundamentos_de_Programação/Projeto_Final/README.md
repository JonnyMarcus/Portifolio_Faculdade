<div align="center">

# 🎓 Sistema de Cadastro de Alunos

![C](https://img.shields.io/badge/C-00599C?logo=c&logoColor=white)
![Status](https://img.shields.io/badge/status-concluído-brightgreen)
![Licença](https://img.shields.io/badge/licença-livre_para_estudo-lightgrey)

Um CRUD completo em C puro, rodando 100% no terminal, com persistência em arquivo.

</div>

---

## 📖 Índice

- [Sobre](#-sobre)
- [Funcionalidades](#️-funcionalidades)
- [Como executar](#-como-executar)
- [Menu do sistema](#️-menu-do-sistema)
- [Arquitetura](#-arquitetura)
- [Persistência de dados](#-persistência-de-dados)
- [Conceitos aplicados](#-conceitos-aplicados)
- [Evoluções futuras](#-evoluções-futuras)
- [Autor](#-autor)

---

## 📚 Sobre

Projeto final desenvolvido para aplicar, de forma integrada, os principais conteúdos da disciplina de **Fundamentos de Programação**.

O sistema simula o gerenciamento de uma turma: cadastro, consulta, edição, remoção, cálculo de médias e ordenação de alunos — com os dados persistidos automaticamente em arquivo, sem depender de banco de dados externo.

**Objetivos do projeto:**

- Aplicar os conceitos fundamentais da linguagem C na prática
- Organizar dados utilizando `structs` e vetores
- Trabalhar com funções, ponteiros e controle de fluxo
- Persistir informações em arquivo, mantendo os dados entre execuções

---

## ⚙️ Funcionalidades

| Opção | Ação                    | Descrição                                                                 |
| :---: | ----------------------- | ------------------------------------------------------------------------- |
|  `1`  | Cadastrar aluno         | Registra nome, matrícula e as duas notas; calcula a média automaticamente |
|  `2`  | Listar alunos           | Exibe todos os alunos cadastrados, com situação (Aprovado/Reprovado)      |
|  `3`  | Buscar aluno            | Localiza um aluno pela matrícula                                          |
|  `4`  | Calcular média da turma | Média geral considerando todos os alunos cadastrados                      |
|  `5`  | Editar aluno            | Atualiza nome e notas de um aluno já existente                            |
|  `6`  | Remover aluno           | Remove um aluno pela matrícula                                            |
|  `7`  | Salvar alunos           | Grava todos os registros no arquivo `dados.txt`                           |
|  `8`  | Ordenar por nome        | Reordena a lista em memória, em ordem alfabética                          |
|  `0`  | Sair                    | Encerra o programa                                                        |

> A situação do aluno é calculada automaticamente: **Aprovado** se média ≥ 6, **Reprovado** caso contrário.

---

## 🚀 Como executar

**Pré-requisito:** um compilador C (`gcc` ou equivalente) instalado.

```bash
# 1. Compilar
gcc main.c -o sistema

# 2. Executar
./sistema          # Linux/macOS
sistema.exe        # Windows
```

Ao iniciar, o programa carrega automaticamente os dados salvos em `dados.txt`, se o arquivo já existir.

---

## 🖥️ Menu do sistema

```
===== SISTEMA DE CADASTRO DE ALUNOS =====
1 - Cadastrar aluno
2 - Listar alunos
3 - Buscar aluno
4 - Calcular media da turma
5 - Editar Aluno
6 - Remover Aluno
7 - Salvar Alunos no arquivo
8 - Ordenar alunos por nome
0 - Sair
Escolha:
```

---

## 🏗️ Arquitetura

```
sistema-cadastro-alunos/
├── main.c        # todo o código-fonte do sistema
├── dados.txt     # gerado/atualizado automaticamente ao salvar
└── README.md
```

### Estrutura de dados

Cada aluno é representado por uma `struct`, armazenada em um vetor de tamanho fixo (`MAX_ALUNOS = 100`):

```c
typedef struct aluno {
    char nome[100];
    int matricula;
    float nota_1;
    float nota_2;
    float media;
} Aluno;
```

### Organização das funções

| Categoria        | Funções                                                                      |
| ---------------- | ---------------------------------------------------------------------------- |
| **CRUD**         | `CadastrarAluno`, `ListarAluno`, `BuscarAluno`, `EditaAluno`, `RemoverAluno` |
| **Cálculo**      | `CalculandoMediaTurma`, `MostrarSituacao`                                    |
| **Persistência** | `SalvaAlunos`, `CarregaAlunos`                                               |
| **Ordenação**    | `OrdenarPorNome`                                                             |

Todas as funções recebem o vetor de alunos e a quantidade atual por **parâmetro** (passagem por ponteiro quando a quantidade precisa ser alterada), evitando variáveis globais.

---

## 💾 Persistência de dados

Ao escolher a opção **7**, os dados são gravados em `dados.txt`, um registro por linha, separados por `;`:

```
matricula;nome;nota_1;nota_2;media
```

Exemplo:

```
101;Maria Silva;8.50;9.00;8.75
```

Esse arquivo é lido automaticamente (`CarregaAlunos`) sempre que o programa inicia, restaurando o cadastro da sessão anterior.

---

## 📌 Conceitos aplicados

<table>
<tr>
<td valign="top" width="33%">

**Fundamentos**

- Variáveis e tipos primitivos
- Operadores
- Entrada/saída (`scanf`, `fgets`)

</td>
<td valign="top" width="33%">

**Controle de fluxo**

- Condicionais (`if`/`else`/`switch`)
- Repetição (`for`/`do-while`)
- Funções e parâmetros

</td>
<td valign="top" width="33%">

**Estruturas avançadas**

- Vetores e `structs`
- Ponteiros
- Arquivos (`fopen`/`fprintf`/`fscanf`)
- Ordenação (_bubble sort_)

</td>
</tr>
</table>

---

## 👤 Autor

Feito por **Jonny Marcus**
