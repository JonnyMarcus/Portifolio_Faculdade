# 🎓 Sistema de Cadastro de Alunos

Um CRUD completo em **C puro**, rodando 100% no terminal, com persistência em arquivo — projeto final da disciplina de **Fundamentos de Programação**.

<p align="left">
  <img src="https://img.shields.io/badge/C-A8B9CC?logo=c&logoColor=white" alt="C">
  <img src="https://img.shields.io/badge/Status-conclu%C3%ADdo-brightgreen" alt="Status">
  <img src="https://img.shields.io/badge/License-livre%20para%20estudo-lightgrey" alt="Licença">
</p>

## 📖 Sobre

O sistema simula o gerenciamento de uma turma: cadastro, consulta, edição, remoção, cálculo de médias e ordenação de alunos — com os dados persistidos automaticamente em arquivo, sem depender de banco de dados externo.

**Objetivos:** aplicar os conceitos fundamentais da linguagem C na prática, organizar dados com `structs` e vetores, trabalhar com funções, ponteiros e controle de fluxo, e persistir informações em arquivo entre execuções.

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

## ▶️ Como executar

```bash
gcc main.c -o sistema
./sistema          # Linux/macOS
sistema.exe        # Windows
```

Ao iniciar, o programa carrega automaticamente os dados salvos em `dados.txt`, se o arquivo já existir.

## 🏗️ Arquitetura

```text
sistema-cadastro-alunos/
├── main.c        # todo o código-fonte do sistema
├── dados.txt     # gerado/atualizado automaticamente ao salvar
└── README.md
```

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

| Categoria    | Funções                                                                      |
| ------------ | ---------------------------------------------------------------------------- |
| CRUD         | `CadastrarAluno`, `ListarAluno`, `BuscarAluno`, `EditaAluno`, `RemoverAluno` |
| Cálculo      | `CalculandoMediaTurma`, `MostrarSituacao`                                    |
| Persistência | `SalvaAlunos`, `CarregaAlunos`                                               |
| Ordenação    | `OrdenarPorNome`                                                             |

Todas as funções recebem o vetor de alunos e a quantidade atual por parâmetro (passagem por ponteiro quando a quantidade precisa ser alterada), evitando variáveis globais.

## 💾 Persistência de dados

Ao escolher a opção `7`, os dados são gravados em `dados.txt`, um registro por linha:

```
matricula;nome;nota_1;nota_2;media
101;Maria Silva;8.50;9.00;8.75
```

Esse arquivo é lido automaticamente (`CarregaAlunos`) a cada início do programa, restaurando o cadastro da sessão anterior.

## 📌 Conceitos aplicados

| Fundamentos                      | Controle de fluxo                   | Estruturas avançadas                                              |
| -------------------------------- | ----------------------------------- | ----------------------------------------------------------------- |
| Variáveis e tipos primitivos     | Condicionais (`if`/`else`/`switch`) | Vetores e `structs`                                               |
| Operadores                       | Repetição (`for`/`do-while`)        | Ponteiros                                                         |
| Entrada/saída (`scanf`, `fgets`) | Funções e parâmetros                | Arquivos (`fopen`/`fprintf`/`fscanf`) · ordenação (_bubble sort_) |

## 👨‍💻 Autor

**Jonny Marcus**
