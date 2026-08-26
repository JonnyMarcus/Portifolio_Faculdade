# 🧮 Calculadora Binária em Assembly x86

Projeto final em **Assembly x86**, aplicando os conceitos de **Arquitetura de Computadores II** diretamente no funcionamento do processador, registradores e execução de instruções em baixo nível.

<p align="left">
  <img src="https://img.shields.io/badge/Assembly%20x86-lightgrey" alt="Assembly x86">
  <img src="https://img.shields.io/badge/NASM-lightgrey" alt="NASM">
</p>

## 📖 Sobre

O sistema realiza operações aritméticas básicas e exibe os resultados tanto em decimal quanto em binário.

## 🎯 Objetivo

Aplicar conceitos de arquitetura de computadores através da implementação direta de operações em linguagem de montagem.

## ⚙️ Funcionalidades

- Entrada de dois números inteiros
- Operações: soma, subtração, multiplicação
- Comparações: maior valor, menor valor
- Conversão do resultado para decimal e binário

## 🧠 Conceitos aplicados

| Categoria              | Itens                                                       |
| ---------------------- | ----------------------------------------------------------- |
| Registradores          | AX, BX, CX, DX                                              |
| Instruções aritméticas | ADD, SUB, MUL                                               |
| Fluxo de controle      | JMP, CMP, JE, JG, JL                                        |
| Subrotinas             | Separação de rotinas de cálculo, reutilização de código     |
| Organização de memória | Armazenamento em registradores, manipulação direta de dados |

## 💡 Exemplo de funcionamento

```text
Entrada:
Número 1: 5
Número 2: 3

Saída:
Soma: 8
Binário: 1000
```

## 📂 Estrutura do projeto

````text
calculadora_binaria_assembly/
├── README.md
└── calculadora.asm


## ▶️ Como executar

```bash
nasm -f elf64 calculadora.asm
ld calculadora.o -o calculadora
./calculadora
````

## 🛠️ Tecnologias

Assembly x86 · NASM · GCC/LD · Visual Studio Code

## 🗺️ Possíveis evoluções futuras

- [ ] Divisão
- [ ] Menu interativo
- [ ] Entrada por teclado completa
- [ ] Suporte a múltiplas operações

## 👨‍💻 Autor

**Jonny Marcus**
