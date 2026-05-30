/* ---------------------
 * Problema: Minimum Spanning Tree (SPOJ MST / Beecrowd 1152)
 * Link: https://www.beecrowd.com.br/judge/en/problems/view/1152 
 * Tecnica: Algoritmo Guloso (Prim)
 *
 * Explicacao:
 *   Encontrar a arvore geradora minima de um grafo ponderado.
 *   O algoritmo de Prim e guloso: mantemos um conjunto de vertices ja incluidos
 *   na MST. A cada passo, escolhemos a aresta de menor peso que conecta um vertice
 *   dentro do conjunto a um fora. Isso e repetido ate incluir todos os vertices.
 *
 * Complexidade:
 *   Tempo:  O(V^2) com matriz de adjacencia (implementacao simples).
 *           O((V+E) log V) com heap de prioridade.
 *   Espaco: O(V^2) — matriz de adjacencia.
 */

#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAXV 505
#define INF  INT_MAX

int graph[MAXV][MAXV];
int key[MAXV];      /* menor aresta conectando vertice a MST */
int inMST[MAXV];    /* vertice ja esta na MST? */
int parent[MAXV];   /* arvore geradora */
int V, E;

int minKey(void) {
    int min = INF, idx = -1;
    for (int v = 0; v < V; v++)
        if (!inMST[v] && key[v] < min) {
            min = key[v];
            idx = v;
        }
    return idx;
}

long long prim(void) {
    for (int i = 0; i < V; i++) { key[i] = INF; inMST[i] = 0; parent[i] = -1; }
    key[0] = 0;

    long long totalCost = 0;
    for (int count = 0; count < V; count++) {
        int u = minKey();
        if (u == -1) break;
        inMST[u] = 1;
        totalCost += key[u];

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                key[v]    = graph[u][v];
                parent[v] = u;
            }
        }
    }
    return totalCost;
}

int main(void) {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &V, &E);
        memset(graph, 0, sizeof(graph));
        for (int i = 0; i < E; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            u--; v--;
            if (!graph[u][v] || graph[u][v] > w) {
                graph[u][v] = w;
                graph[v][u] = w;
            }
        }
        printf("%lld\n", prim());
    }
    return 0;
}