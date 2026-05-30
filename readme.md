# Projeto de Implementação de Algoritmos

## Descrição

Este projeto reúne a implementação de diferentes problemas clássicos de programação competitiva utilizando diversas técnicas de projeto de algoritmos. Os exercícios foram resolvidos utilizando a linguagem **C** e testados nas plataformas **LeetCode** e **SPOJ**.

O objetivo do trabalho é demonstrar a aplicação prática de técnicas fundamentais estudadas na disciplina, analisando suas estratégias de resolução e complexidades computacionais.

---

## Linguagem Utilizada

* C 

---

## Plataformas Utilizadas

* LeetCode
* SPOJ (Sphere Online Judge)

---

## Algoritmos Implementados

### 1. Permutations (LeetCode 46)

**Técnica:** Backtracking

**Descrição:**
Gera todas as permutações possíveis de um conjunto de números distintos.

**Complexidade:**

* Tempo: O(n! × n)
* Espaço: O(n)

---

### 2. Palindrome Partitioning (LeetCode 131)

**Técnica:** Backtracking

**Descrição:**
Gera todas as possíveis partições de uma string em que cada substring seja um palíndromo.

**Complexidade:**

* Tempo: O(n × 2ⁿ)
* Espaço: O(n)

---

### 3. INVCNT - Inversion Count (SPOJ)

**Técnica:** Divisão e Conquista

**Descrição:**
Conta o número de inversões em um vetor utilizando Merge Sort modificado.

**Complexidade:**

* Tempo: O(n log n)
* Espaço: O(n)

---
### 4. LASTDIG - The Last Digit (SPOJ)

**Técnica:** Divisão e Conquista

**Descrição:**
Calcula o último dígito de uma potência utilizando exponenciação rápida.

**Complexidade:**

* Tempo: O(log b)
* Espaço: O(log b)

---
### 5. Letter Combinations of a Phone Number (LeetCode 17)

**Técnica:** Backtracking

**Descrição:**
Gera todas as combinações de letras possíveis para uma sequência de dígitos telefônicos.

**Complexidade:**

* Tempo: O(4ⁿ)
* Espaço: O(n)

---

### 6. Minimum Spanning Tree (MST)

**Técnica:** Algoritmo Guloso (Prim)

**Descrição:**
Encontra a Árvore Geradora Mínima de um grafo ponderado.

**Complexidade:**

* Tempo: O(V²)
* Espaço: O(V²)

---


### 7. 0/1 Knapsack (SPOJ)

**Técnica:** Programação Dinâmica

**Descrição:**
Determina o maior valor que pode ser transportado em uma mochila com capacidade limitada.

**Complexidade:**

* Tempo: O(n × W)
* Espaço: O(W)

---

### 7. Assign Cookies (LeetCode 455)

**Técnica:** Algoritmo Guloso (Greedy)

**Descrição:**
Maximiza a quantidade de crianças satisfeitas distribuindo cookies de forma eficiente.

**Complexidade:**

* Tempo: O(n log n + m log m)
* Espaço: O(1)

---


### 9. SHPATH - The Shortest Path (SPOJ)

**Técnica:** Grafos (Dijkstra)

**Descrição:**
Determina o menor caminho entre duas cidades utilizando Dijkstra com fila de prioridade.

**Complexidade:**

* Tempo: O((V + E) log V)
* Espaço: O(V + E)

---

### 10. Max Area of Island (LeetCode 695)

**Técnica:** Grafos (DFS)

**Descrição:**
Determina a maior área de uma ilha em uma matriz binária utilizando busca em profundidade.

**Complexidade:**

* Tempo: O(m × n)
* Espaço: O(m × n)

---

## Técnicas Estudadas

Durante o desenvolvimento deste projeto foram aplicadas as seguintes técnicas:

* Backtracking
* Divisão e Conquista
* Programação Dinâmica
* Algoritmos Gulosos (Greedy)
* Grafos

---

## Estrutura do Projeto

```text
/
├── permutations.c
├── palindromepartitioning.c
├── invcntmergesort.c
├── lastdigfastpower.c
├── phonenumber.c
├── minimumspanning.c
├── knapsack.c
├── assigncookies.c
├── dijkstra.c
├── maxareaisland.c
└── README.md
```

---

## Compilação

Exemplo utilizando GCC:

```bash
gcc arquivo.c -o programa
```

Execução:

```bash
./programa
```

---

## Resultados

Todos os algoritmos foram testados utilizando os casos de teste disponibilizados pelas plataformas LeetCode e SPOJ, obtendo resultados compatíveis com as saídas esperadas.

---

## Conclusão

A implementação desses problemas permitiu aplicar conceitos fundamentais de projeto e análise de algoritmos, além de comparar diferentes estratégias para resolução de problemas computacionais. Cada técnica apresentou características próprias em termos de eficiência, consumo de memória e facilidade de implementação, contribuindo para uma compreensão mais ampla da área de algoritmos.
