# 📈 Analisador de Funções em C

## 📚 Sobre o Projeto

Projeto desenvolvido em linguagem **C** com foco na aplicação prática dos principais conceitos estudados em **Cálculo A**, integrando análise matemática e visualização gráfica.

O sistema permite analisar funções matemáticas, calcular derivadas, aproximar integrais, estudar limites e gerar gráficos automaticamente.

---

## 🎯 Objetivo

Aplicar conceitos de cálculo diferencial e integral através da programação, transformando teoria matemática em análise computacional.

---

## ⚙️ Funcionalidades

### 🔹 Entrada de Função

* função quadrática
* função polinomial simples

### 🔹 Cálculo de Limites

* aproximação numérica lateral
* comportamento em pontos específicos

### 🔹 Derivadas

* cálculo da derivada da função

f'(x)=\frac{d}{dx}f(x)

* análise de crescimento
* análise de decrescimento

### 🔹 Integrais

* cálculo aproximado por soma de retângulos

\int_a^b f(x),dx

* área sob a curva

### 🔹 Estudo da Função

* raízes
* vértice
* máximo e mínimo

### 🔹 Plotagem Gráfica

* geração automática de pontos
* criação de gráfico com gnuplot

---

## 📂 Estrutura do Projeto

```bash
analisador_funcoes/
│
├── README.md
├── main.c
├── funcoes.c
├── funcoes.h
├── grafico.c
├── grafico.h
├── dados.txt
└── graficos/
```

---

## 📁 Organização dos Arquivos

### main.c

Responsável pelo menu principal e interação com o usuário.

### funcoes.c / funcoes.h

Contém:

* cálculo da função
* derivada
* limites
* integral

### grafico.c / grafico.h

Responsável por:

* gerar pontos
* salvar em arquivo
* chamar gnuplot

### dados.txt

Arquivo temporário contendo os pontos do gráfico.

### graficos/

Armazena gráficos gerados.

---

## 🧠 Conceitos Matemáticos Aplicados

### Limite

\lim_{x\to a} f(x)

### Derivada de função quadrática

genui{"math_block_widget_always_prefetch_v2":{"content":"f(x)=ax^2+bx+c"}}


### Integral numérica

\sum f(x)\Delta x

---

## 💻 Exemplo de Uso

Entrada:

```text
f(x)=2x²+3x−1
```

Saída:

```text
Derivada: 4x+3
Raízes: x1, x2
Vértice: (xv, yv)
Integral aproximada: ...
```

---

## 📈 Plotagem de Gráfico

O programa gera automaticamente pontos da função e envia para o gnuplot.

Exemplo de geração:

```text
-2 3
-1 0
0 -1
1 0
2 3
```

---

## 🚀 Compilação

```bash
gcc main.c funcoes.c grafico.c -o analisador
```

---

## ▶️ Execução

```bash
./analisador
```

---

## 🛠️ Dependências

* GCC
* gnuplot
* Visual Studio Code

---

## 🎓 Relação com Cálculo A

Este projeto integra:

* funções
* limites
* derivadas
* integrais
* interpretação gráfica

---

## 📈 Possíveis Evoluções Futuras

* derivada numérica automática
* integrais definidas mais precisas
* múltiplos tipos de função
* comparação entre função e derivada

---

## 👨‍💻 Autor

**JonnyMarcus**
