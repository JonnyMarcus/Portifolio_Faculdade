# 🗜️ HuffC — Compressor de Arquivos com Árvore de Huffman

**Compressor e descompressor de arquivos sem perdas**, implementado em C, usando a **codificação de Huffman** — um algoritmo clássico que aplica na prática quase todos os pilares estudados na disciplina de Estrutura de Dados: recursão, TADs, filas, listas encadeadas e árvores binárias.

<p align="left">
  <img src="https://img.shields.io/badge/C-A8B9CC?logo=c&logoColor=white" alt="C">
  <img src="https://img.shields.io/badge/%C3%81rvores%20Bin%C3%A1rias-lightgrey" alt="Árvores Binárias">
  <img src="https://img.shields.io/badge/Recurs%C3%A3o-lightgrey" alt="Recursão">
  <img src="https://img.shields.io/badge/Compress%C3%A3o%20sem%20Perdas-success" alt="Compressão sem perdas">
  <img src="https://img.shields.io/badge/License-MIT-green" alt="License">
</p>

## 📖 Sobre

Todo arquivo digital — texto, imagem, log de sistema — tem padrões de repetição em seus bytes. O **HuffC** explora exatamente isso: em vez de gastar 8 bits fixos para representar cada byte, ele atribui **códigos binários mais curtos aos bytes mais frequentes** e códigos mais longos aos mais raros, reduzindo o tamanho final do arquivo sem perder nenhuma informação — a descompressão reconstrói o arquivo original byte a byte, de forma perfeita.

O projeto foi escolhido como aplicação prática da disciplina justamente porque a codificação de Huffman não é um exercício acadêmico isolado: é usada de verdade dentro de formatos como **ZIP, GZIP, PNG e JPEG**.

## 🎯 Objetivo

Implementar um compressor/descompressor funcional de ponta a ponta, aplicando de forma real cada estrutura de dados estudada ao longo do semestre — sem usar nenhuma biblioteca pronta de compressão.

## 🧠 Como funciona

1. **Contagem de frequência**: o arquivo é lido byte a byte, contando quantas vezes cada um dos 256 valores possíveis aparece
2. **Construção da árvore de Huffman**: os bytes viram folhas de uma árvore binária, combinadas repetidamente pelas duas menores frequências até sobrar uma única árvore — o processo clássico de "montar de baixo para cima"
3. **Geração dos códigos**: percorrendo a árvore recursivamente (esquerda = bit `0`, direita = bit `1`), cada byte recebe um código binário único, mais curto quanto mais frequente ele for
4. **Codificação do arquivo**: cada byte do arquivo original é substituído pelo seu código, e a sequência de bits é escrita de volta em disco
5. **Descompressão**: a árvore é reconstruída a partir do cabeçalho salvo no arquivo comprimido, e os bits são percorridos um a um até se chegar numa folha (= um byte decodificado), repetindo até reconstruir o arquivo inteiro

## 🔗 Mapeamento com o conteúdo da disciplina

| Módulo da disciplina | Onde aparece no projeto |
|---|---|
| Ponteiros e alocação dinâmica | Todos os nós da árvore e da fila de prioridade são alocados dinamicamente com `malloc` |
| Recursão | Construção da árvore, geração dos códigos e reconstrução na descompressão são todas recursivas |
| Tipos Abstratos de Dados (TADs) | A árvore de Huffman e a fila de prioridade são implementadas como TADs, com interface separada da implementação |
| Filas | A fila de prioridade (min-heap ou lista ordenada) decide qual par de nós combinar a cada passo da construção da árvore |
| Listas encadeadas | Usadas na implementação da fila de prioridade e no armazenamento da tabela de códigos |
| Árvores binárias | O coração do projeto: toda a lógica de codificação/decodificação depende da árvore de Huffman |
| Análise de complexidade | O projeto inclui uma comparação entre implementar a fila de prioridade como lista ordenada (O(n) por inserção) vs. heap binária (O(log n)) |

## 🚀 Funcionalidades

- Compressão de qualquer tipo de arquivo (texto, binário, imagem) sem perda de dados
- Descompressão fiel, restaurando o arquivo byte a byte
- Relatório de taxa de compressão ao final (tamanho original vs. comprimido, percentual economizado)
- Modo de comparação entre fila de prioridade como lista ordenada e como heap binária, medindo o tempo de construção da árvore em arquivos grandes

## 📂 Estrutura do projeto

```text
huffc/
├── README.md
├── Makefile
│
├── src/
│   ├── main.c                # interface de linha de comando
│   ├── huffman_tree.c/.h      # construção e travessia da árvore
│   ├── priority_queue.c/.h     # fila de prioridade (lista ordenada e heap)
│   ├── bitwriter.c/.h            # escrita/leitura de sequências de bits
│   ├── frequency.c/.h             # contagem de frequência dos bytes
│   └── file_io.c/.h                # leitura/escrita de arquivos e cabeçalho
│
├── tests/
│   └── arquivos_teste/              # arquivos de exemplo para testar compressão
│
└── docs/
    └── relatorio.pdf                 # relatório técnico da disciplina
```

## 🛠️ Tecnologias

- **C** (padrão C11), sem dependências externas
- Compilação via `Makefile` / `gcc`

## ▶️ Como compilar e executar

```bash
git clone https://github.com/JonnyMarcus/huffc
cd huffc
make

# Comprimir um arquivo
./huffc -c arquivo.txt arquivo.huff

# Descomprimir
./huffc -d arquivo.huff arquivo_restaurado.txt

# Comparar desempenho: lista ordenada vs. heap binária
./huffc --benchmark arquivo_grande.txt
```

## 🗺️ Roadmap

- [x] **v1** — Compressão e descompressão funcionais com fila de prioridade em lista ordenada
- [ ] **v2** — Fila de prioridade como heap binária, com benchmark comparando as duas implementações
- [ ] **v3** — Suporte a compressão de diretórios inteiros (múltiplos arquivos num único `.huff`)
- [ ] **v4** — Codificação adaptativa (árvore atualizada dinamicamente, sem precisar armazenar a tabela de frequências no cabeçalho)

## 📖 Referência

- Cormen, Leiserson, Rivest & Stein — *Algoritmos: Teoria e Prática*, 3ª ed., Elsevier, 2012 (capítulo sobre códigos de Huffman e algoritmos gulosos)

## 👨‍💻 Autor

**Jonny Marcus**
Graduando em Ciência da Computação na UNIFEI.

Projeto desenvolvido para a disciplina de **Estrutura de Dados**, aplicando recursão, TADs, filas, listas encadeadas e árvores binárias na construção de um compressor de arquivos funcional.