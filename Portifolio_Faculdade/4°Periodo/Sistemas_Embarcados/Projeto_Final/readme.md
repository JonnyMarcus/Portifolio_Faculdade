# 🌱 Smart Greenhouse - Estufa Inteligente (100% Simulada)

Um sistema embarcado capaz de monitorar e controlar automaticamente uma pequena estufa, mantendo as condições ideais para o crescimento das plantas — **todo simulado online, sem precisar comprar nenhum componente físico**.

## 💡 Ideia central

O mesmo conceito de uma estufa inteligente, mas montado inteiramente em um simulador de circuitos gratuito no navegador (**[Wokwi](https://wokwi.com)**), que já possui todos os componentes necessários prontos (ESP32/Arduino, sensores, display, LEDs, buzzer). O código roda exatamente como rodaria no hardware real.

## 🛠️ Ferramenta necessária

| Ferramenta                                    | Para quê                                                                                |
| --------------------------------------------- | --------------------------------------------------------------------------------------- |
| **Wokwi** (wokwi.com, gratuito, no navegador) | Montar o circuito virtual completo e simular sensores, atuadores e código em tempo real |
| **VS Code + extensão Wokwi** (opcional)       | Simular localmente e versionar o projeto no GitHub                                      |

> Não precisa instalar nada além do navegador — o Wokwi já roda o ESP32/Arduino, os sensores e os atuadores todos virtualmente, e você consegue "mexer" nos sensores (ex: arrastar o slider de temperatura) para ver o sistema reagir em tempo real.

## 🎯 Objetivo

Desenvolver um sistema utilizando um microcontrolador simulado para monitorar temperatura, umidade, luminosidade e umidade do solo, acionando automaticamente dispositivos virtuais como ventilador, bomba d'água e iluminação.

## ❓ Problema

Muitas pessoas esquecem de cuidar corretamente das plantas, causando:

- Falta de água
- Excesso de calor
- Pouca iluminação
- Baixa produtividade

O sistema resolve esse problema automatizando o monitoramento — e o projeto pode ser todo demonstrado via simulação, sem depender de aquisição de hardware.

## ⚙️ Funcionalidades

- 🌡️ Monitorar temperatura
- 💧 Monitorar umidade do ar
- 🌱 Monitorar umidade do solo
- ☀️ Medir luminosidade
- 🚿 Acionar irrigação automática
- 🌀 Ligar ventilador automaticamente
- 💡 Controlar iluminação
- 🔔 Emitir alerta sonoro em situações críticas
- 📺 Mostrar informações em display LCD/OLED
- 📡 Enviar dados via Wi-Fi (opcional, o Wokwi simula Wi-Fi do ESP32)

## 🧩 Componentes utilizados (todos virtuais no Wokwi)

| Componente virtual                                        | Função                            |
| --------------------------------------------------------- | --------------------------------- |
| ESP32 (simulado)                                          | Microcontrolador                  |
| Sensor DHT22 (simulado)                                   | Temperatura e umidade             |
| Sensor de umidade do solo (simulado)                      | Detectar necessidade de irrigação |
| Sensor LDR (simulado)                                     | Luminosidade                      |
| Módulo relé (simulado)                                    | Acionar dispositivos              |
| Mini bomba d'água (representada por relé + LED indicador) | Irrigação                         |
| Cooler 5V (representado por motor DC virtual)             | Ventilação                        |
| LED Grow / LED branco (simulado)                          | Iluminação                        |
| Display LCD/OLED (simulado)                               | Exibir informações                |
| Buzzer (simulado)                                         | Alertas                           |

## 🏗️ Arquitetura do sistema

```text
                Sensores (virtuais)
     ┌─────────────────────────┐
     │                         │
     │ DHT22                   │
     │ LDR                     │
     │ Umidade do Solo         │
     └──────────┬──────────────┘
                │
                ▼
          ESP32 (simulado)
                │
      ┌─────────┼───────────┐
      │         │           │
      ▼         ▼           ▼
   Ventilador  Bomba      LED Grow
      │         │           │
      └─────────┼───────────┘
                │
           Display OLED
                │
             Buzzer
```

## 🔁 Funcionamento

1. O sistema lê todos os sensores virtuais.
2. Analisa os valores.
3. Decide quais atuadores devem ser ligados.
4. Atualiza o display.
5. Aguarda alguns segundos.
6. Repete o processo continuamente.

## 📊 Regras de negócio

**Temperatura**

| Temperatura | Ação            |
| ----------- | --------------- |
| < 18°C      | Nenhuma ação    |
| 18°C–30°C   | Normal          |
| > 30°C      | Liga ventilador |

**Umidade do solo**

| Valor      | Ação          |
| ---------- | ------------- |
| Solo seco  | Liga bomba    |
| Solo úmido | Desliga bomba |

**Luminosidade**

| Valor | Ação        |
| ----- | ----------- |
| Baixa | Liga LED    |
| Alta  | Desliga LED |

## 📂 Estrutura do código

```text
src/
main.cpp

sensors/
    dht.cpp
    soil.cpp
    ldr.cpp

actuators/
    fan.cpp
    pump.cpp
    light.cpp

display/
    oled.cpp

wifi/
    wifi.cpp

utils/
    timer.cpp
```

## 🔧 Principais funções

```cpp
void readSensors();
void updateDisplay();
void controlFan();
void controlPump();
void controlLight();
void sendData();
```

## 💻 Exemplo de lógica

```cpp
if (temperature > 30) {
    ligarVentilador();
} else {
    desligarVentilador();
}

if (soilHumidity < 30) {
    ligarBomba();
}

if (light < 300) {
    ligarLed();
}
```

## 🚀 Como rodar (sem materiais físicos)

1. Acesse [wokwi.com](https://wokwi.com) e crie um novo projeto ESP32
2. Adicione os componentes virtuais listados acima pelo editor de diagrama (`diagram.json`)
3. Cole o código-fonte no editor
4. Clique em "Play" para iniciar a simulação
5. Arraste os sliders dos sensores (temperatura, luz, umidade do solo) para testar as regras de negócio
6. Acompanhe o display e os atuadores reagindo em tempo real

## 🌟 Possíveis melhorias

- Aplicativo para celular
- Dashboard Web
- Histórico dos sensores
- Controle remoto
- Notificações por WhatsApp
- Integração com MQTT
- Integração com Firebase
- Painel solar
- Controle por voz
- Inteligência Artificial para prever irrigação

## 🛠️ Tecnologias utilizadas

- C++
- Arduino Framework
- ESP32 (simulado)
- Sensores digitais e analógicos (simulados)
- I²C
- Wi-Fi (ESP32, simulado)
- Wokwi (simulador)
- MQTT (opcional)
- Firebase (opcional)

## 🧠 Competências desenvolvidas

Programação embarcada em C++ · Leitura de sensores · Controle de atuadores · Comunicação serial · Automação · Simulação de circuitos · Protocolos I²C e GPIO · Internet das Coisas (IoT)

## 🌟 Possíveis expansões

- 🌦️ Estação meteorológica inteligente
- 🏠 Sistema de automação residencial
- 🚗 Estacionamento inteligente
- 🐶 Alimentador automático para pets
- 🚰 Controle inteligente de caixa d'água
- 🏭 Monitoramento industrial
- ❄️ Controle automático de temperatura em ambientes

## 🎓 Diferencial para o portfólio

Esse projeto reúne conceitos de eletrônica, programação em C++, automação, IoT e sistemas embarcados — todo demonstrável via simulação gratuita no navegador, sem custo com hardware. Pode ser expandido com um painel web ou aplicativo móvel para monitoramento remoto, sendo um excelente projeto de nível intermediário/avançado para o portfólio.
