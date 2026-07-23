# 🦠 EpidemicLab

**Simulador interativo de epidemias baseado no modelo epidemiológico SIR**, desenvolvido em Python para a disciplina de Modelagem Computacional. Permite visualizar em tempo real como doenças infecciosas se propagam sob diferentes cenários e parâmetros.

<p align="left">
  <img src="https://img.shields.io/badge/Python-3.11-blue?logo=python&logoColor=white" alt="Python">
  <img src="https://img.shields.io/badge/Streamlit-App-red?logo=streamlit&logoColor=white" alt="Streamlit">
  <img src="https://img.shields.io/badge/NumPy-Scientific-013243?logo=numpy&logoColor=white" alt="NumPy">
  <img src="https://img.shields.io/badge/SciPy-Modeling-8CAAE6?logo=scipy&logoColor=white" alt="SciPy">
  <img src="https://img.shields.io/badge/Matplotlib-Graphs-orange" alt="Matplotlib">
  <img src="https://img.shields.io/badge/License-MIT-green" alt="License">
</p>

<!-- Sugestão: coloque aqui um GIF ou screenshot do dashboard rodando -->
<!-- ![Demo](assets/screenshots/demo.gif) -->

---

## 📖 Sobre o projeto

O **EpidemicLab** simula a propagação de doenças infecciosas usando o **Modelo SIR** (_Susceptible, Infected, Recovered_), um dos modelos fundamentais da epidemiologia matemática. O objetivo é tornar tangível — de forma visual e interativa — como pequenas mudanças na taxa de transmissão, na taxa de recuperação ou no tamanho da população alteram completamente a curva de uma epidemia.

O projeto une conceitos de modelagem matemática, física computacional, simulação numérica e visualização de dados numa aplicação científica interativa construída com Streamlit.

## 🧠 O modelo SIR

A população total (constante ao longo da simulação) é dividida em três compartimentos:

| Estado         | Símbolo | Significado                                                       |
| -------------- | ------- | ----------------------------------------------------------------- |
| 🟢 Suscetíveis | `S`     | Pessoas saudáveis que podem ser infectadas                        |
| 🔴 Infectados  | `I`     | Pessoas atualmente infectadas                                     |
| 🔵 Recuperados | `R`     | Pessoas que já passaram pela doença e não podem mais transmiti-la |

$$S + I + R = N$$

A dinâmica entre os três grupos é descrita pelo seguinte sistema de equações diferenciais:

$$\frac{dS}{dt} = -\beta S I \qquad\qquad \frac{dI}{dt} = \beta S I - \gamma I \qquad\qquad \frac{dR}{dt} = \gamma I$$

Onde:

- **β** (beta) — taxa de transmissão da doença
- **γ** (gama) — taxa de recuperação
- **N** — população total

## 🚀 Funcionalidades

**Simulação**

- Simular epidemias com parâmetros customizáveis
- Ajustar população, infectados/recuperados iniciais, β e γ
- Comparar diferentes cenários lado a lado

**Dashboard interativo**

- Gráficos atualizados em tempo real conforme os sliders mudam
- Pico de infectados e dia em que ele ocorre
- Total de infectados e recuperados ao longo do tempo
- Estatísticas agregadas da simulação

## 📊 O que você pode ajustar

| Parâmetro                  | Descrição                                     |
| -------------------------- | --------------------------------------------- |
| 👥 População               | Tamanho total do grupo simulado               |
| 🦠 Infectados iniciais     | Quantas pessoas começam infectadas            |
| 💉 Recuperados iniciais    | Quantas pessoas já começam imunes/recuperadas |
| 📈 Taxa de transmissão (β) | Quão rápido a doença se espalha               |
| ❤️ Taxa de recuperação (γ) | Quão rápido as pessoas se recuperam           |
| 📅 Dias simulados          | Duração da simulação                          |

## 📈 Visualizações geradas

- Evolução dos suscetíveis, infectados e recuperados ao longo do tempo
- Curva epidêmica completa
- Comparação entre múltiplos cenários
- Área sob a curva de infectados
- Indicadores: pico de infectados, dia do pico, total infectado, percentual da população afetada, duração da epidemia e taxa média de crescimento

## ⚙️ Tecnologias

- **Python 3.11**
- **Streamlit** — interface interativa
- **NumPy** e **SciPy** — resolução numérica do sistema de EDOs
- **Pandas** — manipulação dos dados de simulação
- **Plotly** e **Matplotlib** — visualização dos resultados

## 📂 Estrutura do projeto

```
epidemic-lab/
├── app.py                  # Ponto de entrada da aplicação Streamlit
├── simulation.py           # Orquestração da simulação
├── sir_model.py             # Implementação do modelo SIR
├── statistics.py            # Cálculo dos indicadores (pico, duração, etc.)
├── graphs.py                # Geração dos gráficos
├── utils.py                  # Funções auxiliares
│
├── assets/
│   ├── logo.png
│   └── screenshots/
│
├── data/
│   └── simulations.csv       # Histórico de simulações exportadas
│
├── notebooks/
│   └── analysis.ipynb         # Análises exploratórias adicionais
│
├── docs/
│   ├── report.pdf              # Relatório da disciplina
│   └── presentation.pdf        # Slides de apresentação
│
├── requirements.txt
└── README.md
```

## ▶️ Como executar

**1. Clone o repositório**

```bash
git clone https://github.com/JonnyMarcus/epidemic-lab
cd epidemic-lab
```

**2. Instale as dependências**

```bash
pip install -r requirements.txt
```

**3. Rode a aplicação**

```bash
streamlit run app.py
```

A aplicação abre automaticamente no navegador em `http://localhost:8501`.

## 🔬 Perguntas que dá pra explorar com o simulador

- O que acontece com a curva quando a taxa de transmissão aumenta?
- Como o isolamento social reduz o pico da epidemia?
- Quanto tempo uma epidemia leva para terminar, dado um certo β e γ?
- Qual o impacto da taxa de recuperação na duração total do surto?
- Como a vacinação prévia (recuperados iniciais) muda o resultado?

## 📚 Conceitos aplicados

| Área       | Tópicos                                               |
| ---------- | ----------------------------------------------------- |
| Modelagem  | Sistemas dinâmicos, equações diferenciais, modelo SIR |
| Computação | Simulação, métodos numéricos, programação científica  |
| Matemática | Integração numérica, estatística, análise de dados    |

## 🗺️ Roadmap

- [x] **v1.0** — Simulação SIR, dashboard e gráficos básicos
- [ ] **v2.0** — Exportação para CSV/PDF e comparação de cenários
- [ ] **v3.0** — Modelos SEIR, SIS e SIRS
- [ ] **v4.0** — Vacinação, mortalidade, distanciamento social e lockdown
- [ ] **v5.0** — Simulação baseada em agentes, rede social entre indivíduos, múltiplas cidades, mapa de calor e previsão com IA

## 📖 Bibliografia

- Gould & Tobochnik — _An Introduction to Computer Simulation Methods_
- Serway & Jewett — _Physics for Scientists and Engineers_
- Shiflet — _Introduction to Computational Science_

## 📄 Licença

Este projeto está sob a licença MIT — veja o arquivo [LICENSE](LICENSE) para mais detalhes.

## 👨‍💻 Autor

**Jonny Marcus**
Graduando em Ciência da Computação na UNIFEI.

Projeto desenvolvido para a disciplina de Modelagem Computacional, aplicando conceitos de modelagem matemática, simulação computacional, programação científica e visualização de dados para estudar a propagação de epidemias através do modelo SIR.
