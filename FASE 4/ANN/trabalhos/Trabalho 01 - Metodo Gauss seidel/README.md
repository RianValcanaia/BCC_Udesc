
# 🧮 Trabalho 01 – Análise Numérica (Gauss-Seidel em Python)

Este repositório contém a implementação do **método de Gauss-Seidel** para resolução de sistemas lineares, desenvolvida como parte do Trabalho 01 da disciplina de **Análise Numérica**.

## 📌 Objetivos

- Implementar o **método de Gauss-Seidel** em Python
- Realizar o **teste de convergência** baseado no critério de linhas (diagonal dominante)
- Aplicar **troca de linhas** quando necessário para satisfazer o critério
- Avaliar a **qualidade do ajuste** utilizando o **vetor resíduo** r = Ax - b

## 📥 Entradas do sistema

Sistema linear resolvido:

  7x₁ +  x₂ -  x₃ + 4x₄ = -10  
  x₁  - 5x₂ +  x₃ - 2x₄ =   2  
  x₁  +     3x₃ -  x₄ =  11  
  3x₁ +  x₂ - 3x₃ + 8x₄ = -24

- **Chute inicial**: `[-0.3, 1.3, 2.8, -2.3]`
- **Critério de parada**: ε ≤ 0.0005

## 🛠️ Funcionalidades

- `casas_precisao()` — informa o número de casas necessárias para atingir o critério de convergência
- `ajusta_convergencia()` — verifica e ajusta a matriz para satisfazer o critério de linhas
- `arredondamento()` — arredonda o número conforme norma
- `gauss_seidel()` — resolve o sistema linear iterativamente
- `qualidadeAjusteVetorResiduo()` — calcula o vetor resíduo r = Ax - b 
- `print_matriz()` — exibe a matriz formatada em forma matricial

## 📊 Resultados esperados

- Vetor solução aproximada x̄:
  ```
  [0.00004, 1.00002, 2.99993, -2.00004]
  ```

- Vetor resíduo:
  ```
  [0.00021, -0.00005, -0.00013, 0.00003]
  ```

## 📂 Como executar

1. Copie o código do arquivo "trabalho.py" no [Google Colab](https://colab.research.google.com)
2. Rodar as células passo a passo
3. Os resultados serão exibidos no console

## 👨‍🏫 Envolvidos

- Professor: Jarbas Ferrari
- Estudantes: [Lucas Macedo](https://github.com/lucasomac0) e [Rian Valcanaia](https://github.com/RianValcanaia)

## 📅 Curso

- Universidade: Universidade do Estado de Santa Catarina (UDESC)
- Disciplina: Análise Numérica
- Semestre: 4º 
