/*
 * Problema: Assign Cookies (LeetCode 455)
 * Link: https://leetcode.com/problems/assign-cookies/ 
 * Tecnica: Algoritmo Guloso (Greedy)
 *
 * Explicacao:
 *   Cada crianca possui um nivel minimo de satisfacao g[i]
 *   e cada cookie possui um tamanho s[i].
 *
 *   Uma crianca fica satisfeita se:
 *
 *        s[j] >= g[i]
 *
 *   O objetivo e maximizar o numero de criancas satisfeitas.
 *
 *   Estrategia Gulosa:
 *
 *      1) Ordenamos:
 *            - criancas
 *            - cookies
 *
 *      2) Tentamos entregar o menor cookie possivel
 *         para a menor crianca possivel.
 *
 *      3) Se o cookie satisfaz a crianca:
 *            contamos a crianca
 *            avancamos ambos ponteiros
 *
 *         Senao:
 *            tentamos um cookie maior
 *
 *   Essa estrategia funciona porque:
 *      usar o menor cookie valido preserva
 *      cookies maiores para criancas maiores.
 *
 * Complexidade:
 *   Tempo:  O(n log n + m log m)
 *            devido a ordenacao
 *
 *   Espaco: O(1)
 */

#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

/* O LeetCode espera esta assinatura exata */
int findContentChildren(int* g, int gSize, int* s, int sSize) {

    qsort(g, gSize, sizeof(int), compare);
    qsort(s, sSize, sizeof(int), compare);

    int i = 0;
    int j = 0;
    int satisfied = 0;

    while (i < gSize && j < sSize) {

        if (s[j] >= g[i]) {

            satisfied++;

            i++;
            j++;
        }
        else {

            j++;
        }
    }

    return satisfied;
}