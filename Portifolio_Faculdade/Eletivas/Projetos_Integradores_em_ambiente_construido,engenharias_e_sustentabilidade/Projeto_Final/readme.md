# 🌱 EcoItamambuca — Projeto Integrador

Sistema de **monitoramento territorial, participação comunitária e simulação de impacto ambiental** no território de Itamambuca, Ubatuba/SP.

> Projeto final da disciplina **IRN021 — Projetos Integradores em Ambiente Construído, Engenharias e Sustentabilidade — UNIFEI**

<p align="left">
  <img src="https://img.shields.io/badge/Projeto%20Final-IRN021-0B3D91" alt="Projeto Final IRN021">
  <img src="https://img.shields.io/badge/Next.js-000000?logo=next.js&logoColor=white" alt="Next.js">
  <img src="https://img.shields.io/badge/Node.js-339933?logo=node.js&logoColor=white" alt="Node.js">
  <img src="https://img.shields.io/badge/PostgreSQL%2FPostGIS-4479A1?logo=postgresql&logoColor=white" alt="PostgreSQL/PostGIS">
  <img src="https://img.shields.io/badge/QGIS-589632?logo=qgis&logoColor=white" alt="QGIS">
  <img src="https://img.shields.io/badge/UNIFEI-Instituto%20de%20Recursos%20Naturais-0B3D91" alt="UNIFEI">

</p>

## 📖 Sobre o projeto

O **EcoItamambuca** é uma plataforma digital voltada ao **monitoramento socioambiental do território de Itamambuca**, em Ubatuba/SP.

O que diferencia o projeto de um sistema comum de denúncias é o seu núcleo: cada ocorrência de poluição registrada não é apenas um ponto no mapa — o sistema **simula seu impacto rio abaixo**, estimando até onde aquele poluente se dispersa, em quanto tempo e quantas pessoas e áreas sensíveis (captação de água, praia, zonas turísticas) são potencialmente afetadas.

Essa abordagem se apoia em estudos reais já publicados sobre o Rio Itamambuca, que analisaram a dispersão de efluentes na bacia via modelagem matemática e computacional — o projeto adapta essa lógica de forma simplificada e interativa para uso comunitário.

---

## 🎯 Objetivo

Desenvolver um sistema digital capaz de transformar denúncias ambientais isoladas em **evidência visual e quantitativa de impacto**, apoiando tanto a comunidade quanto o poder público na priorização de intervenções em Itamambuca.

### Objetivos específicos

- 📍 Permitir que moradores e turistas registrem ocorrências de poluição georreferenciadas;
- 🌊 Simular a dispersão do poluente a partir do ponto denunciado, ao longo do curso d'água;
- 🗺️ Sobrepor a área de influência estimada a dados territoriais (captação de água, zonas de banho, densidade populacional);
- 📊 Organizar as ocorrências e seus impactos estimados em um dashboard;
- 🏛️ Formalizar automaticamente denúncias que atingem um limiar de gravidade, encaminhando-as aos órgãos responsáveis (prefeitura, CETESB);
- 🌱 Sugerir Soluções Baseadas na Natureza (SbN) compatíveis com cada tipo de problema identificado.

---

## 🌍 Território de estudo

Itamambuca, distrito de Ubatuba/SP, cortado pelo Rio Itamambuca — corpo d'água responsável por parte do abastecimento local e por sustentar o turismo e o surfe da região. É um território com organização comunitária ativa (associações como a SAI — Sociedade Amigos de Itamambuca) e desafios documentados de poluição hídrica ligados a saneamento precário e ocupação irregular das margens, inclusive por loteamentos privados.

---

## 🚨 Problema

Denúncias de poluição hoje dependem de mobilização manual e contínua da comunidade (como a SAI já faz há anos) para pressionar o poder público — sem dados estruturados que demonstrem a real extensão do impacto de cada ocorrência. Isso enfraquece o argumento de urgência e dificulta a priorização de qual ponto resolver primeiro.

---

## 💡 Solução proposta

```text
                🌱 ECOITAMAMBUCA
                       │
      ┌────────────────┼────────────────┐
      │                │                │
     📍               🌊               📊
 OCORRÊNCIA      SIMULAÇÃO DE      DASHBOARD +
 (mapa + foto)   DISPERSÃO         PROTOCOLO
      │                │                │
      └────────────────┼────────────────┘
                       │
                       ▼
              🔎 ÁREA DE IMPACTO ESTIMADA
              (pessoas, captações, praia)
                       │
                       ▼
              🌱 SOLUÇÕES BASEADAS
                 NA NATUREZA
```

### Como funciona, passo a passo

1. O morador registra uma ocorrência: tipo de problema, localização, foto e descrição.
2. O sistema estima a dispersão do poluente rio abaixo, usando um modelo simplificado baseado em vazão do trecho, distância e tempo decorrido.
3. A área de influência estimada é sobreposta a dados do território (pontos de captação, praia, densidade de moradores) para calcular um **índice de impacto**.
4. Ocorrências com índice de impacto alto — ou que atingem um número mínimo de denúncias próximas — geram automaticamente um protocolo formal, enviado à prefeitura e à CETESB.
5. Todo o histórico alimenta um dashboard territorial, usado para identificar áreas prioritárias e propor Soluções Baseadas na Natureza.

---

## 🗺️ Funcionalidades

- 📍 Cadastro de ocorrências;
- 🗺️ Mapa interativo;
- 📊 Dashboard de indicadores;
- 🔎 Filtros por categoria e severidade;
- ⚠️ Classificação de prioridade;
- 🌱 Sugestão de Soluções Baseadas na Natureza;
- 🛰️ Integração com dados do QGIS.

### Mapa interativo

Visualização por camadas: cursos d'água, vegetação, áreas urbanizadas, pontos de captação, ocorrências ativas e áreas de impacto simuladas.

### 📍 Registro de ocorrências

Tipo do problema, localização, descrição, data, fotografia e prioridade — atribuída automaticamente conforme o índice de impacto calculado.

### 🌊 Simulação de dispersão (diferencial do projeto)

Modelo simplificado que estima o alcance e o tempo de propagação de um poluente a partir do ponto denunciado, exibido como uma área dinâmica no mapa.

### 🏛️ Protocolo automático

Ao atingir um limiar de gravidade (ex.: múltiplas ocorrências próximas em 30 dias, ou impacto sobre ponto de captação), o sistema gera e envia um documento estruturado aos órgãos responsáveis, com status de acompanhamento (aberto / em análise / resolvido).

### 📊 Dashboard territorial

| Indicador                 | Descrição                                     |
| ------------------------- | --------------------------------------------- |
| Ocorrências               | Total de registros                            |
| Área de impacto acumulada | Extensão estimada afetada no período          |
| Pontos críticos           | Locais com maior índice de impacto recorrente |
| Protocolos abertos        | Denúncias formalizadas aguardando resposta    |
| Resolvidas                | Ocorrências solucionadas                      |

### 🌱 Soluções Baseadas na Natureza

Sugestões de intervenção conforme o tipo de problema: jardins de chuva, biovaletas, pavimentos permeáveis, recuperação de mata ciliar, áreas de infiltração.

---

## 🔬 Metodologia

Abordagem baseada em **Aprendizagem Baseada em Projetos (ABP)** e **Soluções Baseadas na Natureza (SbN)**.

1. **Diagnóstico** — levantamento das características ambientais, sociais e territoriais de Itamambuca.
2. **Coleta de dados** — levantamentos de campo, dados geográficos, entrevistas, oficinas participativas, dados públicos (CETESB, prefeitura).
3. **Geoprocessamento** — organização e análise espacial dos dados via SIG/QGIS.
4. **Modelagem simplificada de dispersão** — adaptação de estudos existentes sobre o Rio Itamambuca a um modelo computacional leve.
5. **Desenvolvimento** — implementação do protótipo da plataforma.
6. **Análise** — identificação de áreas com maior concentração de impacto.
7. **Participação social** — apresentação dos resultados e coleta de contribuições da comunidade.

---

## 🛠️ Tecnologias e ferramentas

| Categoria        | Tecnologia           |
| ---------------- | -------------------- |
| Front-end        | React / Next.js      |
| Back-end         | Node.js              |
| Banco de dados   | PostgreSQL / PostGIS |
| Geoprocessamento | QGIS                 |
| Mapas            | Leaflet              |
| Dashboard        | Power BI             |
| Design           | Figma                |
| Versionamento    | Git / GitHub         |

---

## 📂 Estrutura do projeto

```text
EcoItamambuca/
│
├── README.md
│
├── docs/
│   ├── diagnostico/
│   ├── metodologia/
│   ├── resultados/
│   └── referencias/
│
├── frontend/
│   ├── components/
│   ├── pages/
│   └── assets/
│
├── backend/
│   ├── routes/
│   ├── controllers/
│   ├── services/
│   └── simulacao/          # modelo de dispersão de poluentes
│
├── database/
│   └── schema.sql
│
├── qgis/
│   ├── mapas/
│   └── dados/
│
├── dashboard/
│
└── assets/
    ├── imagens/
    └── diagramas/
```

## 📈 Resultados esperados

- Transformar denúncias isoladas em evidência quantitativa de impacto ambiental;
- Identificar áreas prioritárias com base em dados, não apenas em volume de reclamações;
- Reduzir o tempo entre a identificação de um problema e a formalização da denúncia ao poder público;
- Fortalecer a mobilização comunitária já existente em Itamambuca com dados estruturados;
- Apoiar a proposição de Soluções Baseadas na Natureza direcionadas a cada ponto crítico.

---

## 🎓 Relação com a disciplina

O projeto integra os principais conteúdos da disciplina **IRN021**: ambiente construído, planejamento territorial, recursos hídricos, geotecnologias, diagnóstico territorial, participação social, monitoramento ambiental, ecologia, sustentabilidade e Soluções Baseadas na Natureza.

---

## 📚 Projeto Integrador

**Disciplina:** IRN021 — Projetos Integradores em Ambiente Construído, Engenharias e Sustentabilidade
**Instituição:** Universidade Federal de Itajubá — UNIFEI
**Área:** Instituto de Recursos Naturais — IRN
**Território de estudo:** Itamambuca — Ubatuba/SP
**Metodologia:** Aprendizagem Baseada em Projetos e Soluções Baseadas na Natureza

---

## 👨‍💻 Autor

**Jonny Marcus**

Graduando em Ciência da Computação — UNIFEI
Projeto desenvolvido como atividade final da disciplina IRN021.

## 📌 Status

🟡 **Projeto acadêmico em desenvolvimento**

> **Tecnologia para compreender o território. Simulação para dimensionar o impacto. Sustentabilidade para transformar o futuro. 🌱**
