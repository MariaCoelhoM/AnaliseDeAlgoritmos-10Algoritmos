/* ------------------------
 * Problema: 0/1 Knapsack (SPOJ KNAPSACK)
 * Link: https://www.spoj.com/problems/KNAPSACK/
 * Tecnica: Programacao Dinamica
 *
 * Explicacao:
 *   Dado itens com peso e valor, e uma mochila de capacidade W, maximizar o valor
 *   total sem fracionamento. Diferente do knapsack fracionario, aqui cada item ou
 *   entra inteiro ou nao entra.
 *   dp[i][w] = maior valor usando os primeiros i itens com capacidade w.
 *   Transicao: dp[i][w] = max(dp[i-1][w], dp[i-1][w-peso[i]] + valor[i])
 *
 * Complexidade:
 *   Tempo:  O(n * W) — preenche a tabela dp de dimensao n x W.
 *   Espaco: O(W)     — otimizacao de espaco usando apenas uma linha.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXW 10001
#define MAXN 1001

int dp[MAXW];   /* dp[w] = melhor valor com capacidade w */

int max(int a, int b) { return a > b ? a : b; }

int main(void) {
    int W, n;
    scanf("%d %d", &W, &n);

    int weight[MAXN], value[MAXN];
    for (int i = 0; i < n; i++)
        scanf("%d %d", &weight[i], &value[i]);

    /* inicializa dp */
    for (int w = 0; w <= W; w++) dp[w] = 0;

    /* para cada item, atualiza dp de tras para frente (evita usar item duas vezes) */
    for (int i = 0; i < n; i++) {
        for (int w = W; w >= weight[i]; w--) {
            dp[w] = max(dp[w], dp[w - weight[i]] + value[i]);
        }
    }

    printf("%d\n", dp[W]);
    return 0;
}