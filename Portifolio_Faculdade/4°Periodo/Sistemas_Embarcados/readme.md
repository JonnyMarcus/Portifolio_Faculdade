# 🔌 Sistemas Embarcados

Repositório de estudos da disciplina **Sistemas Embarcados** — resumos, exercícios, laboratórios e materiais desenvolvidos ao longo do semestre.

<p align="left">
  <img src="https://img.shields.io/badge/C-A8B9CC?logo=c&logoColor=black" alt="C">
  <img src="https://img.shields.io/badge/PIC18F4520-microcontrolador-1BA0D7" alt="PIC18F4520">
  <img src="https://img.shields.io/badge/MPLAB%20X%20IDE-E5121B" alt="MPLAB X IDE">
  <img src="https://img.shields.io/badge/Sistemas%20de%20Tempo%20Real-183A61" alt="Tempo Real">
</p>

## 📖 Sobre a disciplina

A disciplina apresenta os fundamentos da programação de sistemas embarcados em linguagem C, com foco no microcontrolador PIC. São abordados o acesso direto a periféricos (IO, Serial, PWM, ADC, Timers), a manipulação de registros e memória, o uso de interrupções para código em tempo real e as principais arquiteturas de software utilizadas em sistemas embarcados (single loop, interrupt driven, cooperative multitasking).

Este repositório organiza tudo que foi estudado — resumos, exercícios, laboratórios, trabalhos e materiais de apoio — servindo tanto de registro do aprendizado quanto de referência para consultas e revisão futuras.

## 🎯 Objetivos

- Demonstrar o funcionamento dos periféricos: IO, Serial, PWM, ADC, Timers
- Classificar as atividades em background e foreground
- Implementar códigos em tempo real usando interrupção
- Implementar códigos para interfaces de hardware
- Organizar o programa selecionando a melhor arquitetura de software

## 🧠 Competências e habilidades

Linguagem C · Sistemas Embarcados · Sistemas Operacionais de Tempo Real · Programação de Periféricos · Interrupções · Arquiteturas de Software Embarcado

## 📚 Conteúdo programático

| #   | Módulo                               | Tópicos                                                                                                                                           |
| --- | ------------------------------------ | ------------------------------------------------------------------------------------------------------------------------------------------------- |
| 1   | **Fundamentos de C para embarcados** | Linguagem C e vetores, funções, ambiente de programação, indentação, comentários, arquivos `.c`/`.h`, diretivas de compilação                     |
| 2   | **IDE e rotinas básicas**            | IDE para embarcado, criação de projeto com bibliotecas prontas, `stdio.h` (`printf`), operações matemáticas, rotinas de delay                     |
| 3   | **Bits e debug**                     | Operações com bits, debug de sistemas embarcados                                                                                                  |
| 4   | **Memória e registros**              | Ponteiros e endereços de memória, acesso à memória, clock e tempo de instrução, registros de configuração do microcontrolador                     |
| 5   | **Periféricos e portas**             | Programação dos periféricos, acesso às portas do microcontrolador (via variável e via `define`), configuração dos periféricos, barramento de LEDs |
| 6   | **Display de 7 segmentos**           | Operação com display, flicker                                                                                                                     |
| 7   | **Leitura de teclas**                | Debounce, contagem de pressionamentos                                                                                                             |
| 8   | **Display LCD 2x16**                 | Posicionamento no LCD, controle de temperatura                                                                                                    |
| 9   | **Comunicação serial**               | Envio de comandos via serial                                                                                                                      |
| 10  | **Conversor AD e PWM**               | Conversor AD, saídas PWM                                                                                                                          |
| 11  | **Timer e Watchdog**                 | Timer, reprodução de sons, relógio LCD com timer, watchdog                                                                                        |
| 12  | **Interrupções**                     | Interrupção, watchdog                                                                                                                             |
| 13  | **Arquiteturas de software**         | One single loop, interrupt driven, cooperative multitasking                                                                                       |
| 14  | **Tempo real**                       | Sistemas de tempo real                                                                                                                            |

## 🔬 Atividades desenvolvidas

Exercícios · Laboratórios · Trabalhos · Avaliações

## 🛠️ Ferramentas utilizadas

| Categoria                   | Ferramentas                                              |
| --------------------------- | -------------------------------------------------------- |
| Linguagem                   | C                                                        |
| Microcontrolador            | PIC18F4520                                               |
| Ambiente de desenvolvimento | IDE para embarcados (MPLAB X)                            |
| Periféricos                 | Display 7 segmentos, LCD 2x16, teclado, ADC, PWM, Timers |

## 📂 Estrutura do repositório

```text
Sistemas-Embarcados/
├── README.md
│
├── 01-Fundamentos-C/
├── 02-IDE-Rotinas-Basicas/
├── 03-Bits-Debug/
├── 04-Memoria-Registros/
├── 05-Perifericos-Portas/
├── 06-Display-7-Segmentos/
├── 07-Leitura-Teclas/
├── 08-Display-LCD/
├── 09-Comunicacao-Serial/
├── 10-Conversor-AD-PWM/
├── 11-Timer-Watchdog/
├── 12-Interrupcoes/
├── 13-Arquiteturas-Software/
├── 14-Tempo-Real/
│
├── Exercicios/
├── Laboratorios/
└── Trabalhos/
```

## 📖 Bibliografia

**Básica**

- PEREIRA, Fábio — _Microcontroladores PIC: técnicas avançadas_
- KERNIGHAN, Brian W.; RITCHIE, Dennis M. — _C, a linguagem de programação: padrão ANSI_
- SCHILDT, Herbert — _C: completo e total_

**Complementar**

- BARRETT, Steven F.; PACK, Daniel J. — _Embedded systems: design and applications with the 68HC12 and HCS12_
- ASCÊNCIO, Ana Fernandes Gomes; CAMPOS, Edilene Aparecida Veneruchi de — _Fundamentos da programação de computadores: Algoritmos, Pascal e C/C++_
- ZIVIANI, Nivio — _Projeto de algoritmos: com implementações em Pascal e C_
- SCHEID, F. — _Computadores e Programação_
- PAULA FILHO, Wilson de Pádua — _Engenharia de Software: fundamentos, métodos e padrões_

## 👨‍💻 Autor

**Jonny Marcus**
Graduando em Ciência da Computação na UNIFEI, com interesse em Sistemas Embarcados, Desenvolvimento de Software, Inteligência Artificial, Computação em Nuvem e Automação de Processos.
