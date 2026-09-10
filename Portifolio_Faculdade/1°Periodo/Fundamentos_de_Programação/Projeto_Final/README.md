# 🎓 Sistema de Cadastro de Alunos

Um CRUD completo em **C puro**, rodando 100% no terminal, com persistência automática em arquivo — projeto final da disciplina de **Fundamentos de Programação**.

<p align="left">
  <img src="https://img.shields.io/badge/C-A8B9CC?logo=c&logoColor=white" alt="C">
  <img src="https://img.shields.io/badge/Status-conclu%C3%ADdo-brightgreen" alt="Status">
  <img src="https://img.shields.io/badge/License-livre%20para%20estudo-lightgrey" alt="Licença">
</p>

---

## 📖 Sobre

O sistema simula o gerenciamento de uma turma: cadastro, consulta, edição, remoção, cálculo de médias, situação (Aprovado/Reprovado) e ordenação alfabética de alunos — com os dados salvos automaticamente em arquivo, sem depender de banco de dados externo.

**Objetivos:** aplicar os conceitos fundamentais da linguagem C na prática — `structs`, vetores, ponteiros, funções, controle de fluxo e manipulação de arquivos — construindo um sistema pequeno, mas completo, do zero.

---

## ⚙️ Funcionalidades

| Opção | Ação                        | Descrição                                                                  |
| :---: | --------------------------- | -------------------------------------------------------------------------- |
|  `1`  | Cadastrar aluno             | Registra nome, matrícula, nota 1 e nota 2; calcula a média automaticamente |
|  `2`  | Remover aluno               | Remove um aluno pela matrícula                                             |
|  `3`  | Listar alunos               | Exibe todos os alunos cadastrados                                          |
|  `4`  | Editar aluno                | Atualiza nome e notas de um aluno existente (a matrícula não é editável)   |
|  `5`  | Buscar aluno                | Localiza um aluno específico pela matrícula                                |
|  `6`  | Mostrar situação dos alunos | Lista todos os alunos com a situação (Aprovado/Reprovado)                  |
|  `7`  | Calcular média da turma     | Média geral considerando todos os alunos cadastrados                       |
|  `0`  | Sair                        | Salva os dados e encerra o programa                                        |

> **Situação do aluno:** calculada automaticamente — **Aprovado** se média ≥ 6, **Reprovado** caso contrário.

### 💾 Salvamento automático

Não existe uma opção manual de "salvar" no menu — o sistema salva sozinho sempre que os dados mudam:

- Ao **cadastrar** um aluno
- Ao **editar** um aluno
- Ao **remover** um aluno
- Ao **sair** do programa

Toda vez que os dados são salvos, a lista também é **reordenada alfabeticamente por nome** antes da gravação — então o arquivo e a lista em memória estão sempre organizados.

---

## ▶️ Como executar

### Com o Makefile (recomendado)

```bash
make run
```

### Manualmente

```bash
gcc -Wall -g main.c -o sistema
./sistema          # Linux/macOS
sistema.exe        # Windows
```

Ao iniciar, o programa carrega automaticamente os dados salvos em `dados.txt`, se o arquivo já existir.

---

## 🏗️ Arquitetura

```text
sistema-cadastro-alunos/
├── main.c        # todo o código-fonte do sistema
├── Makefile      # compilação (make, make run, make clean)
├── dados.txt     # gerado/atualizado automaticamente pelo programa
└── README.md
```

Cada aluno é representado por uma `struct`, armazenada em um vetor de tamanho fixo:

```c
#define MAX 10

typedef struct
{
    char nome[100];
    int matricula;
    float nota_1;
    float nota_2;
    float media;
} Aluno;
```

| Categoria    | Funções                                                                         |
| ------------ | ------------------------------------------------------------------------------- |
| CRUD         | `cadastra_aluno`, `remove_aluno`, `lista_alunos`, `buscar_aluno`, `edita_aluno` |
| Cálculo      | `calcula_media`, `calcula_media_alunos`, `mostra_situacao`                      |
| Persistência | `salva_aluno`, `carrega_aluno`                                                  |
| Ordenação    | `ordena_por_nome`                                                               |

Todas as funções recebem o vetor de alunos e a quantidade atual por parâmetro — por ponteiro (`int *quantidade`) quando a função precisa alterar esse valor, por valor (`int quantidade`) quando só precisa consultá-lo — sem uso de variáveis globais.

---

## 💾 Persistência de dados

Sempre que o sistema salva, os dados são gravados em `dados.txt`, um registro por linha, no formato:

```
matricula;nome;nota_1;nota_2;media
101;Maria Silva;8.50;9.00;8.75
```

Esse arquivo é lido automaticamente (`carrega_aluno`) a cada início do programa, restaurando o cadastro da sessão anterior. A leitura trata corretamente nomes compostos (com espaço), usando `%99[^;]` para capturar tudo até o próximo `;`.

---

## 📌 Conceitos aplicados

| Fundamentos                      | Controle de fluxo                       | Estruturas avançadas                                                  |
| -------------------------------- | --------------------------------------- | --------------------------------------------------------------------- |
| Variáveis e tipos primitivos     | Condicionais (`if` / `else` / `switch`) | Vetores e `structs`                                                   |
| Operadores                       | Repetição (`for` / `do-while`)          | Ponteiros e passagem por referência                                   |
| Entrada/saída (`scanf`, `fgets`) | Funções e parâmetros                    | Arquivos (`fopen` / `fprintf` / `fscanf`) · ordenação (_bubble sort_) |
| Strings (`strchr`, `strcmp`)     |                                         | Compilação com `Makefile`                                             |

---

## 👨‍💻 Autor

**Jonny Marcus**
