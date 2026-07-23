# 👁️ VisionAid — Assistente de Visão em Edge

**Sistema de assistência para pessoas com deficiência visual**, rodando inteiramente em um dispositivo de borda (Raspberry Pi), combinando detecção de obstáculos em tempo real com descrição de cena por IA generativa — sem depender de conexão com a internet ou de servidores em nuvem.

<p align="left">
  <img src="https://img.shields.io/badge/Python-3776AB?logo=python&logoColor=white" alt="Python">
  <img src="https://img.shields.io/badge/Raspberry%20Pi-A22846?logo=raspberrypi&logoColor=white" alt="Raspberry Pi">
  <img src="https://img.shields.io/badge/YOLOv8-black" alt="YOLOv8">
  <img src="https://img.shields.io/badge/Ollama%20%2F%20VLM-3B82F6" alt="Ollama / VLM">
  <img src="https://img.shields.io/badge/100%25%20Offline-success" alt="100% Offline">
  <img src="https://img.shields.io/badge/License-MIT-green" alt="License">
</p>

## 📖 Sobre

No Brasil, mais de 6,5 milhões de pessoas têm algum grau de deficiência visual, e a grande maioria dos sistemas de auxílio disponíveis dependem de conexão de internet estável e de assinaturas de serviços em nuvem — uma barreira real de acesso e custo. O **VisionAid** nasce como projeto final da disciplina de **Machine Learning Systems** com uma proposta direta: levar duas capacidades de visão computacional — **detecção de obstáculos** e **descrição de cena** — para dentro de um Raspberry Pi, rodando 100% localmente, sem depender de nuvem, assinatura ou internet.

A ideia é simples de entender e de usar: o dispositivo fica pendurado no peito ou preso à roupa da pessoa, com uma câmera USB/CSI voltada para frente. Dois processos rodam em paralelo:

1. **Alerta imediato de obstáculos** — usando um modelo leve de detecção de objetos (YOLOv8n), o sistema avisa em voz alta, na hora, quando algo se aproxima demais e na direção do usuário (ex: _"cuidado, objeto à frente"_).
2. **Descrição de cena periódica** — a cada alguns segundos, um modelo de visão generativa (VLM) roda localmente via Ollama e descreve o ambiente ao redor em linguagem natural (ex: _"você está numa calçada, há uma mesa de bar à direita e uma pessoa se aproximando pela esquerda"_).

## 🎯 Por que esse projeto tem impacto

- **Acessibilidade sem custo recorrente**: uma vez montado o hardware, não há mensalidade de API nem dependência de plano de dados
- **Funciona sem internet**: essencial em áreas com conectividade instável, ou simplesmente para não expor a pessoa a uma falha de rede no pior momento possível — atravessando uma rua
- **Privacidade**: nenhuma imagem sai do dispositivo — tudo é processado localmente, o que importa muito quando a câmera capta o dia a dia de alguém continuamente
- **Baixo custo de hardware**: um Raspberry Pi 5 com câmera custa uma fração do preço de soluções assistivas comerciais equivalentes

## 🚀 Funcionalidades

### 🚧 Detecção de obstáculos em tempo real

- Detecção contínua de objetos via **YOLOv8n** (variante "nano", leve o suficiente para rodar em CPU de edge)
- Estimativa de proximidade a partir do tamanho e posição da caixa delimitadora no quadro (sem sensores extras de distância)
- Priorização de alertas: objetos grandes e centralizados no quadro (= próximos e no caminho) disparam aviso imediato; objetos distantes ou nas bordas são ignorados, para não sobrecarregar o usuário com alertas irrelevantes

### 🗣️ Descrição de cena por IA generativa

- A cada alguns segundos (configurável), um **Vision Language Model** local (via Ollama, ex: LLaVA) descreve o ambiente em uma frase curta e natural
- Frequência ajustável para equilibrar detalhamento vs. uso de CPU/bateria

### 🔊 Saída por voz

- Toda comunicação com o usuário é por áudio (texto-para-fala offline), já que a interface visual não faz sentido aqui
- Alertas de obstáculo têm prioridade sobre a descrição de cena — se as duas competirem, o alerta de segurança fala primeiro

### ⚙️ Modo de simulação

- Todo o pipeline pode rodar sem câmera nem Raspberry Pi físico, usando cenas sintéticas de teste — útil para desenvolver e validar a lógica de priorização de alertas antes de testar com hardware real

## 🏗️ Arquitetura

```
┌─────────────┐     ┌──────────────────┐     ┌──────────────────────┐
│   Câmera    │────▶│ Detector YOLOv8 │────▶│  Motor de Prioridade │
│ (USB / CSI) │     │   (obstáculos)   │     │  (urgente / aviso)   │
└─────────────┘     └──────────────────┘     └──────────┬───────────┘
       │                                                 │
       │             ┌──────────────────┐                 ▼
       └───────────▶│   VLM (Ollama)    │        ┌───────────────┐
        a cada N s   │ descrição de cena│───────▶│  Texto-para-  │
                     └──────────────────┘         │      Fala     │
                                                  └───────────────┘
```

## 📂 Estrutura do projeto

```
visionaid/
├── README.md
├── requirements.txt
├── config.py                    # todos os parâmetros ajustáveis num só lugar
│
├── core/
│   ├── camera.py                 # captura de frames (USB/CSI ou webcam de dev)
│   ├── detector.py                # detecção de objetos (YOLOv8 + fallback simulado)
│   ├── proximity.py                # heurística de proximidade e urgência
│   ├── describer.py                 # descrição de cena via VLM (Ollama)
│   └── speaker.py                    # texto-para-fala offline
│
├── demo/
│   └── run_simulation.py            # roda o pipeline completo sem hardware real
│
├── tests/
│   └── test_proximity.py            # testes da lógica de priorização de alertas
│
└── main.py                          # ponto de entrada em hardware real
```

## 🛠️ Tecnologias

| Camada              | Tecnologia                                    | Por quê                                                                 |
| ------------------- | --------------------------------------------- | ----------------------------------------------------------------------- |
| Detecção de objetos | YOLOv8n (Ultralytics)                         | Variante mais leve da família YOLO, roda em CPU de Raspberry Pi sem GPU |
| Descrição de cena   | VLM local via Ollama (ex: LLaVA)              | Modelo multimodal rodando 100% local, sem chamadas de API externas      |
| Câmera              | OpenCV                                        | Suporte nativo a câmeras USB e CSI da Raspberry Pi                      |
| Voz                 | Text-to-speech offline (ex: pyttsx3 / espeak) | Não depende de internet para falar com o usuário                        |
| Hardware alvo       | Raspberry Pi 5 / Pi Zero 2W                   | Mesmo hardware usado ao longo da disciplina                             |

## ▶️ Como executar

**Modo simulação (sem hardware, para desenvolvimento):**

```bash
git clone https://github.com/JonnyMarcus/visionaid
cd visionaid
pip install -r requirements.txt
python demo/run_simulation.py
```

**Em Raspberry Pi com câmera conectada:**

```bash
git clone https://github.com/JonnyMarcus/visionaid
cd visionaid
pip install -r requirements.txt
ollama pull llava        # baixa o modelo de visão generativa localmente
python main.py
```

## 🗺️ Roadmap

- [x] **v1** — Detecção de obstáculos com YOLOv8 e alerta por voz
- [ ] **v2** — Descrição de cena periódica via VLM local (Ollama)
- [ ] **v3** — Ajuste fino de priorização (evitar excesso de alertas em ambientes muito movimentados)
- [ ] **v4** — Leitura de texto no ambiente (placas, letreiros) via OCR
- [ ] **v5** — Botão físico para "descrever agora" sob demanda, além da descrição automática periódica

## 👨‍💻 Autor

**Jonny Marcus**
Graduando em Ciência da Computação na UNIFEI.

Projeto final da disciplina de **Machine Learning Systems**, aplicando conceitos de visão computacional em edge, modelos generativos multimodais locais e sistemas MLOps para dispositivos de recursos restritos, com foco em acessibilidade.
