# 🌐 NetVision

**Plataforma inteligente de monitoramento de redes**, desenvolvida em Python para a disciplina de Redes de Computadores. Combina monitoramento em tempo real, descoberta automática de dispositivos e análise inteligente da infraestrutura de rede — inspirada em soluções profissionais como Zabbix, PRTG, Grafana e Nagios.

<p align="left">
  <img src="https://img.shields.io/badge/Python-3.12-blue?logo=python&logoColor=white" alt="Python">
  <img src="https://img.shields.io/badge/FastAPI-009688?logo=fastapi&logoColor=white" alt="FastAPI">
  <img src="https://img.shields.io/badge/Docker-2496ED?logo=docker&logoColor=white" alt="Docker">
  <img src="https://img.shields.io/badge/SQLite-lightgrey?logo=sqlite&logoColor=blue" alt="SQLite">
  <img src="https://img.shields.io/badge/WebSockets-black" alt="WebSockets">
  <img src="https://img.shields.io/badge/License-MIT-success" alt="License">
</p>

<!-- Sugestão: coloque aqui um screenshot ou GIF do dashboard em ação -->
<!-- ![Dashboard](docs/screenshots/dashboard.png) -->

---

## 📖 Sobre

O **NetVision** monitora uma rede local em tempo real: descobre dispositivos automaticamente, registra eventos, mede disponibilidade e latência, e fornece uma visão completa da infraestrutura através de um dashboard interativo. O projeto foi desenvolvido para aplicar na prática os principais conceitos estudados em Redes de Computadores — protocolos TCP/IP, monitoramento contínuo, comunicação entre dispositivos e segurança.

## 🎯 Objetivos

- Descobrir automaticamente dispositivos da rede
- Monitorar disponibilidade e medir latência continuamente
- Identificar portas abertas em cada host
- Registrar histórico de eventos e gerar dashboards e relatórios
- Emitir alertas quando algo muda na rede

## 🚀 Funcionalidades

### 🌐 Descoberta automática

Scan da rede local combinando **ARP** e **Ping** para identificar dispositivos automaticamente, coletando:

| Nome | IP  | MAC Address | Fabricante | Sistema Operacional | Tempo online |
| ---- | --- | ----------- | ---------- | ------------------- | ------------ |

### 📡 Monitoramento contínuo

Verifica continuamente ping, latência, disponibilidade, perda de pacotes, tempo de resposta e mantém histórico de tudo.

### 🔍 Scanner de portas

Varredura via sockets nas portas mais comuns (HTTP, HTTPS, SSH, FTP, SMTP, DNS, banco de dados), retornando o estado de cada uma:

```
Porta 22   → Aberta
Porta 80   → Aberta
Porta 3306 → Fechada
```

### 📊 Dashboard

Visão consolidada com hosts online/offline, latência média, dispositivos descobertos, uso da rede, alertas ativos e logs — tudo em tempo real via WebSockets.

### 📈 Gráficos

Latência ao longo do tempo, disponibilidade, histórico de uso da rede, dispositivos por fabricante e hosts ativos.

### 🔔 Sistema de alertas

Dispara notificação e registra no histórico sempre que: um host fica offline ou volta a ficar online, a latência sobe demais, uma porta muda de estado, ou um novo dispositivo é detectado na rede.

### 📄 Relatórios automáticos

Exportação em **PDF** e **CSV** com estatísticas de disponibilidade, latência e eventos registrados.

### 🤖 Análise inteligente (opcional)

Um módulo de IA interpreta os eventos coletados e gera observações em linguagem natural, por exemplo:

> "Servidor apresentou aumento de latência nos últimos 20 minutos."
> "Foi detectado um novo dispositivo na rede."
> "A disponibilidade caiu para 92%."

Além disso, gera automaticamente um relatório técnico resumido.

## 📂 Estrutura do projeto

```
netvision/
├── backend/
│   ├── api/
│   ├── database/
│   ├── scanner/
│   ├── monitor/
│   ├── alerts/
│   ├── reports/
│   ├── websocket/
│   ├── ai/
│   └── main.py
│
├── frontend/
│   ├── dashboard/
│   ├── components/
│   ├── pages/
│   ├── charts/
│   └── assets/
│
├── database/
├── logs/
├── docs/
├── docker/
├── tests/
│
├── requirements.txt
├── docker-compose.yml
└── README.md
```

## 🛠️ Tecnologias

| Camada         | Tecnologias                  |
| -------------- | ---------------------------- |
| Backend        | Python, FastAPI, SQLAlchemy  |
| Banco de dados | SQLite                       |
| Rede           | Scapy, Ping3, Socket, psutil |
| Frontend       | HTML, CSS, JavaScript        |
| Dashboard      | Chart.js                     |
| Comunicação    | WebSockets                   |
| Infraestrutura | Docker                       |

## 🌐 Protocolos cobertos

| Camada     | Protocolos       |
| ---------- | ---------------- |
| Aplicação  | HTTP, HTTPS, DNS |
| Transporte | TCP, UDP         |
| Rede       | IPv4, ICMP, ARP  |
| Física     | Ethernet         |

## 📚 Conteúdos de redes aplicados

✔ Camada Física · ✔ Camada de Enlace · ✔ Camada de Rede · ✔ Camada de Transporte · ✔ Camada de Aplicação · ✔ Protocolos TCP/IP · ✔ Segurança · ✔ Redes sem fio

## 🔒 Segurança

- Autenticação via login e **JWT**
- Comunicação via **HTTPS**
- Senhas armazenadas com hash/criptografia
- Logs de acesso e controle de permissões

## ▶️ Como executar

**Com Docker (recomendado):**

```bash
git clone https://github.com/JonnyMarcus/netvision
cd netvision
docker-compose up --build
```

**Localmente, sem Docker:**

```bash
git clone https://github.com/JonnyMarcus/netvision
cd netvision
pip install -r requirements.txt
python backend/main.py
```

A API sobe via FastAPI e o dashboard fica disponível no endereço configurado em `docker-compose.yml` (por padrão, `http://localhost:8000`).

> ⚠️ Algumas funcionalidades de descoberta de rede (ARP scan, sockets brutos) podem exigir permissões elevadas dependendo do sistema operacional.

## 🗺️ Roadmap

- [x] **v1** — Scanner de rede, ping e dashboard básico
- [ ] **v2** — Scanner de portas, persistência em banco e histórico
- [ ] **v3** — Login, containerização com Docker e API REST completa
- [ ] **v4** — WebSocket em tempo real, sistema de alertas e relatórios
- [ ] **v5** — IA para análise de eventos, suporte a IPv6 e SNMP, integração com Grafana/Prometheus e exportação em PDF

## 🎯 Aprendizados

Este projeto aplica na prática conhecimentos de Redes de Computadores, protocolos TCP/IP, Python, APIs REST, banco de dados, desenvolvimento web, Docker, monitoramento, segurança e visualização de dados.

## 📄 Licença

Este projeto está sob a licença MIT — veja o arquivo [LICENSE](LICENSE) para mais detalhes.

## 👨‍💻 Autor

**Jonny Marcus**
Graduando em Ciência da Computação pela UNIFEI.

Projeto desenvolvido como trabalho final da disciplina de Redes de Computadores, aplicando conceitos de monitoramento de redes, protocolos TCP/IP, comunicação entre dispositivos e desenvolvimento de sistemas distribuídos.
