/* ------------------------
 * Problema: SHPATH - The Shortest Path (SPOJ)
 * Link: https://www.spoj.com/problems/SHPATH/
 * Tecnica: Grafos (Dijkstra com heap de prioridade)
 *
 * Explicacao:
 *   Encontrar o menor caminho entre duas cidades em um grafo ponderado
 *   sem arestas negativas.
 *
 *   Cada cidade possui:
 *      - um nome
 *      - uma lista de vizinhos com custos
 *
 *   O algoritmo de Dijkstra mantem:
 *      - dist[] = menor distancia conhecida
 *      - um min-heap para sempre escolher o vertice
 *        com menor distancia atual
 *
 *   Quando encontramos um caminho menor:
 *
 *        dist[v] = dist[u] + w
 *
 *   atualizamos a distancia e inserimos novamente no heap.
 *
 * Complexidade:
 *   Tempo:  O((V + E) log V)
 *   Espaco: O(V + E)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAXV 10005
#define MAXE 200005
#define MAXNAME 25
#define INF INT_MAX

typedef struct Edge {
    int to, w, next;
} Edge;

Edge edges[MAXE];
int head[MAXV];
int edgeCnt;

typedef struct {
    int dist, node;
} HeapNode;

HeapNode heap[MAXE];
int heapSize;

typedef struct {
    char name[MAXNAME];
} City;

City cities[MAXV];

int dist[MAXV];

void addEdge(int u, int v, int w) {

    edges[edgeCnt].to = v;
    edges[edgeCnt].w = w;
    edges[edgeCnt].next = head[u];

    head[u] = edgeCnt++;
}

void pushHeap(int dist, int node) {

    int i = heapSize++;

    heap[i].dist = dist;
    heap[i].node = node;

    while (i > 0) {

        int p = (i - 1) / 2;

        if (heap[p].dist <= heap[i].dist)
            break;

        HeapNode tmp = heap[p];
        heap[p] = heap[i];
        heap[i] = tmp;

        i = p;
    }
}

HeapNode popHeap() {

    HeapNode top = heap[0];

    heap[0] = heap[--heapSize];

    int i = 0;

    while (1) {

        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int m = i;

        if (l < heapSize && heap[l].dist < heap[m].dist)
            m = l;

        if (r < heapSize && heap[r].dist < heap[m].dist)
            m = r;

        if (m == i)
            break;

        HeapNode tmp = heap[m];
        heap[m] = heap[i];
        heap[i] = tmp;

        i = m;
    }

    return top;
}

int getCityIndex(char *name, int V) {

    for (int i = 1; i <= V; i++) {

        if (strcmp(cities[i].name, name) == 0)
            return i;
    }

    return -1;
}

void dijkstra(int src, int V) {

    for (int i = 1; i <= V; i++)
        dist[i] = INF;

    dist[src] = 0;

    heapSize = 0;

    pushHeap(0, src);

    while (heapSize > 0) {

        HeapNode cur = popHeap();

        int u = cur.node;
        int d = cur.dist;

        if (d > dist[u])
            continue;

        for (int e = head[u]; e != -1; e = edges[e].next) {

            int v = edges[e].to;
            int w = edges[e].w;

            if (dist[u] + w < dist[v]) {

                dist[v] = dist[u] + w;

                pushHeap(dist[v], v);
            }
        }
    }
}

int main() {

    int T;

    scanf("%d", &T);

    while (T--) {

        int V;

        scanf("%d", &V);

        edgeCnt = 0;

        for (int i = 1; i <= V; i++)
            head[i] = -1;

        for (int i = 1; i <= V; i++) {

            scanf("%s", cities[i].name);

            int p;

            scanf("%d", &p);

            while (p--) {

                int v, w;

                scanf("%d %d", &v, &w);

                addEdge(i, v, w);
            }
        }

        int Q;

        scanf("%d", &Q);

        while (Q--) {

            char s1[MAXNAME];
            char s2[MAXNAME];

            scanf("%s %s", s1, s2);

            int src = getCityIndex(s1, V);
            int dst = getCityIndex(s2, V);

            dijkstra(src, V);

            printf("%d\n", dist[dst]);
        }
    }

    return 0;
}