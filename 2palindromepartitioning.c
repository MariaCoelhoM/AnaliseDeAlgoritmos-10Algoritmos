/* ---------------------------------
 * Problema: Palindrome Partitioning (LeetCode 131)
 * Link: https://leetcode.com/problems/palindrome-partitioning/ 
 * Tecnica: Backtracking
 *
 * Explicacao:
 *   Dado uma string s, particione-a de forma que cada substring seja um palindromo.
 *   Retorne todas as particoes possiveis. Usamos backtracking: a partir de cada posicao,
 *   tentamos todos os prefixos que sao palindromos e recursivamente particionamos o restante.
 *
 * Complexidade:
 *   Tempo:  O(n * 2^n) — ha 2^(n-1) formas de partir e checar palindromo custa O(n).
 *   Espaco: O(n)       — profundidade maxima da recursao.
 */

#include <stdlib.h>
#include <string.h>

/* O LeetCode espera esta assinatura exata */
char*** partition(char* s, int* returnSize, int** returnColumnSizes);

/* ---------- implementacao ---------- */

#define MAXN        20
#define MAX_PARTS   20
#define MAX_RESULT  8192

static int    len_g;
static char*  s_g;
static char*  current_g[MAX_PARTS];  /* ponteiros para substrings do resultado atual */
static int    partCount_g;
static char***result_g;
static int*   colSizes_g;
static int    totalResults_g;

static int isPalindrome(int l, int r) {
    while (l < r) {
        if (s_g[l] != s_g[r]) return 0;
        l++; r--;
    }
    return 1;
}

static void backtrack(int start) {
    if (start == len_g) {
        /* salva copia permanente da particao atual */
        result_g[totalResults_g] = (char**)malloc(partCount_g * sizeof(char*));
        for (int i = 0; i < partCount_g; i++) {
            /* duplica cada string para o resultado final */
            result_g[totalResults_g][i] = strdup(current_g[i]);
        }
        colSizes_g[totalResults_g] = partCount_g;
        totalResults_g++;
        return;
    }

    for (int end = start; end < len_g; end++) {
        if (isPalindrome(start, end)) {
            int subLen = end - start + 1;
            /* aloca substring temporaria para o nivel atual */
            char *sub = (char*)malloc((subLen + 1) * sizeof(char));
            strncpy(sub, s_g + start, subLen);
            sub[subLen] = '\0';

            current_g[partCount_g++] = sub;
            backtrack(end + 1);
            partCount_g--;
            free(sub);  /* seguro liberar aqui: ja foi duplicada via strdup acima */
        }
    }
}

char*** partition(char* s, int* returnSize, int** returnColumnSizes) {
    s_g            = s;
    len_g          = (int)strlen(s);
    partCount_g    = 0;
    totalResults_g = 0;

    result_g   = (char***)malloc(MAX_RESULT * sizeof(char**));
    colSizes_g = (int*)malloc(MAX_RESULT * sizeof(int));

    backtrack(0);

    *returnSize        = totalResults_g;
    *returnColumnSizes = colSizes_g;
    return result_g;
}