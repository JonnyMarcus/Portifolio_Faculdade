# 📈 Sistema de Análise de Investimentos em C

Sistema em **C** que aplica conceitos de **Engenharia Econômica** e Matemática Financeira, avaliando a viabilidade de diferentes projetos de investimento através de indicadores financeiros clássicos.

<p align="left">
  <img src="https://img.shields.io/badge/C-A8B9CC?logo=c&logoColor=white" alt="C">
  <img src="https://img.shields.io/badge/Matem%C3%A1tica%20Financeira-lightgrey" alt="Matemática Financeira">
</p>

## 📖 Sobre

O sistema permite cadastrar projetos de investimento, registrar seus fluxos de caixa anuais e calcular indicadores financeiros usados na tomada de decisão, possibilitando comparar diferentes alternativas de investimento lado a lado.

Foi desenvolvido com foco em praticar `struct`, vetores, modularização com múltiplos arquivos, manipulação de arquivos, funções e matemática financeira aplicada em C.

## ✨ Funcionalidades

- Cadastro de projetos de investimento e registro do fluxo de caixa anual
- Cálculo do **Payback Simples**
- Cálculo do **Valor Presente Líquido (VPL)**
- Cálculo aproximado da **Taxa Interna de Retorno (TIR)**
- Comparação entre diferentes investimentos
- Salvamento e carregamento dos dados em arquivo
- Consulta das informações cadastradas

## 🧮 Indicadores financeiros

| Indicador   | O que mede                                                                                          | Fórmula                                                                                                                           |
| ----------- | --------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------- |
| **Payback** | Tempo necessário para recuperar o capital investido                                                 | Soma acumulada do fluxo de caixa até zerar o investimento inicial                                                                 |
| **VPL**     | Se o investimento gera valor, descontando os fluxos futuros a uma taxa mínima de atratividade (TMA) | `VPL = -Investimento + Σ [FCₜ / (1 + i)ᵗ]`                                                                                        |
| **TIR**     | A taxa de desconto que zera o VPL — estima a rentabilidade do projeto                               | Aproximada por busca binária (_bisection_) sobre a taxa `i`, já que não há solução algébrica fechada para polinômios de grau alto |

> 💡 **Melhoria aplicada nesta revisão:** o cálculo da TIR passou a ser explicitado como aproximação por bisseção — no material original isso não estava claro, o que podia confundir sobre a precisão do resultado. Deixar isso explícito no README evita que alguém use o valor como se fosse uma solução exata.

## 📂 Estrutura do projeto

```text
Projeto_Analise_Investimentos/
├── main.c               # menu principal
├── investimento.c        # implementação das funções
├── investimento.h         # definições e protótipos
├── dados.txt                # armazenamento dos investimentos
└── README.md
```

## 🛠️ Tecnologias

C (`stdio.h`, `math.h`) · manipulação de arquivos · estruturas de dados simples

## ▶️ Como executar

```bash
gcc main.c investimento.c -o analise_investimentos
./analise_investimentos
```

## 🎓 Conceitos aplicados

Programação estruturada · modularização · manipulação de arquivos · vetores · `struct` · funções · matemática financeira · persistência de dados

## 🗺️ Possíveis melhorias

- [ ] Interface gráfica
- [ ] Exportação de relatórios em PDF
- [ ] Geração de gráficos comparativos
- [ ] Análise de sensibilidade
- [ ] Cálculo de Payback Descontado
- [ ] Simulação de cenários otimista, realista e pessimista
- [ ] Dashboard interativo
- [ ] Sistema de ranking dos investimentos

## 👨‍💻 Autor

**Jonny Marcus**
Estudante de Ciência da Computação e entusiasta de desenvolvimento de software.
