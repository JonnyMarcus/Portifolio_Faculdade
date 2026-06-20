# 🧮 Calculadora Binária em Assembly x86

## 📚 Sobre o Projeto

Projeto final desenvolvido em **Assembly x86** para aplicar os principais conceitos estudados em **Arquitetura de Computadores II**, explorando diretamente o funcionamento do processador, registradores e execução de instruções em baixo nível.

O sistema realiza operações aritméticas básicas e exibe resultados em decimal e binário.

---

## 🎯 Objetivo

Aplicar conceitos de arquitetura de computadores através da implementação direta de operações em linguagem de montagem.

---

## ⚙️ Funcionalidades

### 📌 Entrada de dois números inteiros

### 📌 Operações:

* soma
* subtração
* multiplicação

### 📌 Comparações:

* maior valor
* menor valor

### 📌 Conversão de resultado:

* decimal
* binário

---

## 🧠 Conceitos Aplicados

### ✅ Registradores

* AX
* BX
* CX
* DX

### ✅ Instruções Aritméticas

* ADD
* SUB
* MUL

### ✅ Fluxo de Controle

* JMP
* CMP
* JE
* JG
* JL

### ✅ Subrotinas

* separação de rotinas de cálculo
* reutilização de código

### ✅ Organização de Memória

* armazenamento em registradores
* manipulação direta de dados

---

## 📂 Estrutura do Projeto

```bash id="asm01"
calculadora_binaria_assembly/
│
├── README.md
└── calculadora.asm
```

---

## 💡 Exemplo de Funcionamento

Entrada:

```text id="asm02"
Número 1: 5
Número 2: 3
```

Saída:

```text id="asm03"
Soma: 8
Binário: 1000
```

---

## 🚀 Tecnologias Utilizadas

* Assembly x86
* NASM
* GCC / LD
* Visual Studio Code

---

## ▶️ Como Executar

Compilar:

```bash id="asm04"
nasm -f elf64 calculadora.asm
ld calculadora.o -o calculadora
```

Executar:

```bash id="asm05"
./calculadora
```

---

## 🎓 Relação com a Disciplina

Este projeto integra diretamente:

* ISA
* instruções assembly
* registradores
* aritmética computacional
* fluxo de controle

---

## 📈 Possíveis Evoluções Futuras

* divisão
* menu interativo
* entrada por teclado completa
* suporte a múltiplas operações

---

## 👨‍💻 Autor

**JonnyMarcus**

