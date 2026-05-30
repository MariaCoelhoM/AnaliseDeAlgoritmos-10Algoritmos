/* --------------------------------------
 * Problema: Permutations (LeetCode 46)
 * Link: https://leetcode.com/problems/permutations/ 
 * Tecnica: Backtracking
 *
 * Explicacao:
 *   Dado um array de inteiros distintos, retorna todas as permutacoes possiveis.
 *   Usamos backtracking: em cada posicao, tentamos colocar cada numero ainda nao
 *   usado, recursivamente preenchemos o restante e, ao terminar, desfazemos a escolha
 *   (backtrack) para tentar a proxima opcao.
 *
 * Complexidade:
 *   Tempo:  O(n! * n) — ha n! permutacoes e cada uma custa O(n) para copiar.
 *   Espaco: O(n)      — pilha de recursao de profundidade n.
 *
 */

#include <stdlib.h>
#include <string.h>

/* O LeetCode espera esta assinatura exata */
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes);

/* ---------- implementacao ---------- */

static int  n_g;
static int* nums_g;
static int  used_g[8];
static int  current_g[8];
static int**result_g;
static int  count_g;

static void backtrack(int depth) {
    if (depth == n_g) {
        result_g[count_g] = (int*)malloc(n_g * sizeof(int));
        memcpy(result_g[count_g], current_g, n_g * sizeof(int));
        count_g++;
        return;
    }
    for (int i = 0; i < n_g; i++) {
        if (!used_g[i]) {
            used_g[i]       = 1;
            current_g[depth] = nums_g[i];
            backtrack(depth + 1);
            used_g[i]       = 0;   /* backtrack */
        }
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    n_g     = numsSize;
    nums_g  = nums;
    count_g = 0;

    /* numero maximo de permutacoes: n! (max 8! = 40320) */
    int maxPerms = 1;
    for (int i = 1; i <= numsSize; i++) maxPerms *= i;

    result_g          = (int**)malloc(maxPerms * sizeof(int*));
    *returnColumnSizes = (int*)malloc(maxPerms * sizeof(int));

    memset(used_g, 0, sizeof(used_g));
    backtrack(0);

    *returnSize = count_g;
    for (int i = 0; i < count_g; i++)
        (*returnColumnSizes)[i] = n_g;

    return result_g;
}