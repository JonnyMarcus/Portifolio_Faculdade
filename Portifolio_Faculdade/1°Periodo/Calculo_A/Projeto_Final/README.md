# 📈 Analisador de Funções em C

Projeto em **C** que aplica os principais conceitos estudados em **Cálculo A**, integrando análise matemática e visualização gráfica via gnuplot.

<p align="left">
  <img src="https://img.shields.io/badge/C-A8B9CC?logo=c&logoColor=white" alt="C">
  <img src="https://img.shields.io/badge/gnuplot-lightgrey" alt="gnuplot">
</p>

## 📖 Sobre

O sistema permite analisar funções matemáticas, calcular derivadas, aproximar integrais, estudar limites e gerar gráficos automaticamente — transformando teoria de cálculo diferencial e integral em análise computacional.

## 🎯 Objetivo

Aplicar conceitos de cálculo diferencial e integral através da programação.

## ⚙️ Funcionalidades

| Módulo            | O que faz                                                          |
| ----------------- | ------------------------------------------------------------------ |
| Entrada de função | Função quadrática e polinomial simples                             |
| Limites           | Aproximação numérica lateral e comportamento em pontos específicos |
| Derivadas         | Cálculo de `f'(x)`, análise de crescimento e decrescimento         |
| Integrais         | Aproximação por soma de retângulos, área sob a curva               |
| Estudo da função  | Raízes, vértice, máximo e mínimo                                   |
| Plotagem gráfica  | Geração automática de pontos e gráfico via gnuplot                 |

## 💻 Exemplo de uso

```text
Entrada: f(x) = 2x² + 3x − 1

Saída:
Derivada: 4x + 3
Raízes: x1, x2
Vértice: (xv, yv)
Integral aproximada: ...
```

Pontos gerados para o gráfico:

```text
-2  3
-1  0
 0 -1
 1  0
 2  3
```

## 📂 Estrutura do projeto

```text
analisador_funcoes/
├── main.c            # menu principal e interação com o usuário
├── funcoes.c/.h        # cálculo da função, derivada, limites e integral
├── grafico.c/.h          # geração de pontos, escrita em arquivo e chamada ao gnuplot
├── dados.txt              # arquivo temporário com os pontos do gráfico
├── graficos/               # gráficos gerados
└── README.md
```

## 🛠️ Tecnologias

GCC · gnuplot · Visual Studio Code

## ▶️ Como executar

```bash
gcc main.c funcoes.c grafico.c -o analisador
./analisador
```

## 🗺️ Possíveis evoluções futuras

- [ ] Derivada numérica automática
- [ ] Integrais definidas mais precisas
- [ ] Suporte a múltiplos tipos de função
- [ ] Comparação visual entre função e derivada

## 👨‍💻 Autor

**Jonny Marcus**
