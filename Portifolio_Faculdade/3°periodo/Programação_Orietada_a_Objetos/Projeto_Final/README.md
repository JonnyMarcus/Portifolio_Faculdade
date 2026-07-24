# 🎵 Sistema de Streaming Musical em Python

Simulação de um sistema de streaming musical aplicando os principais conceitos de **Programação Orientada a Objetos**.

<p align="left">
  <img src="https://img.shields.io/badge/Python-3776AB?logo=python&logoColor=white" alt="Python">
</p>

## 📖 Sobre

Sistema com organização orientada a classes, relacionamentos entre objetos e regras de negócio semelhantes às de aplicações reais de streaming.

## 🎯 Objetivo

Aplicar os conceitos fundamentais de orientação a objetos em Python através da construção de um sistema completo de gerenciamento musical.

## ⚙️ Funcionalidades

| Módulo                | O que cobre                                               |
| --------------------- | --------------------------------------------------------- |
| Cadastro de artistas  | Nome, gênero musical, lista de álbuns                     |
| Cadastro de álbuns    | Título, artista, ano, lista de músicas                    |
| Cadastro de músicas   | Nome, duração, gênero, avaliação                          |
| Playlist              | Criar, adicionar músicas, remover músicas, listar músicas |
| Sistema de reprodução | Tocar música, avançar faixa, voltar faixa                 |
| Busca                 | Por nome, por artista, por gênero                         |
| Avaliação             | Nota para músicas, ordenação por avaliação                |

## 🧠 Conceitos de POO aplicados

| Conceito               | Aplicação no projeto                                  |
| ---------------------- | ----------------------------------------------------- |
| Classes e objetos      | Modelagem de entidades reais (artista, álbum, música) |
| Encapsulamento         | Atributos privados e uso de propriedades              |
| Herança                | `UsuarioComum` e `UsuarioPremium`                     |
| Polimorfismo           | Comportamento diferente por tipo de usuário           |
| Classe abstrata        | Classe base `Midia`                                   |
| Associação             | Artista relacionado a álbuns                          |
| Composição             | Álbum contém músicas                                  |
| Agregação              | Playlist reutiliza músicas já existentes              |
| Tratamento de exceções | Validação de entradas e erros de busca                |
| Sobrecarga             | Operadores para comparação de músicas                 |

## 📂 Estrutura do projeto

```text
sistema_streaming_poo/
├── README.md
├── main.py
├── artista.py
├── album.py
├── musica.py
├── playlist.py
├── usuario.py
├── player.py
└── exceptions.py
```

## 🛠️ Tecnologias

Python · VS Code

## 👨‍💻 Autor

**Jonny Marcus**
