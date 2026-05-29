/* -----------------------------
 * Problema: INVCNT - Inversion Count (SPOJ)
 * Link: https://www.spoj.com/problems/INVCNT/
 * Tecnica: Divisao e Conquista (Merge Sort modificado)
 *
 * Explicacao:
 *   Contar o numero de inversoes em um array: pares (i,j) onde i < j mas arr[i] > arr[j].
 *   Modificamos o Merge Sort: durante o merge, toda vez que um elemento do lado direito
 *   vem antes de um elemento do lado esquerdo, ele forma inversoes com todos os elementos
 *   restantes do lado esquerdo.
 *
 * Complexidade:
 *   Tempo:  O(n log n) — mesmo que o Merge Sort classico.
 *   Espaco: O(n)       — array auxiliar para o merge.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXN 200005

long long arr[MAXN];
long long temp[MAXN];

long long mergeCount(long long *a, int l, int mid, int r) {
    int i = l, j = mid + 1, k = l;
    long long count = 0;

    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) {
            temp[k++] = a[i++];
        } else {
            /* a[j] < a[i]: todos os mid-i+1 elementos restantes do lado esquerdo
               formam inversao com a[j] */
            count += (long long)(mid - i + 1);
            temp[k++] = a[j++];
        }
    }
    while (i <= mid) temp[k++] = a[i++];
    while (j <= r)   temp[k++] = a[j++];

    for (int x = l; x <= r; x++) a[x] = temp[x];
    return count;
}

long long sortAndCount(long long *a, int l, int r) {
    if (l >= r) return 0;
    int mid = (l + r) / 2;
    long long count = 0;
    count += sortAndCount(a, l, mid);
    count += sortAndCount(a, mid + 1, r);
    count += mergeCount(a, l, mid, r);
    return count;
}

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%lld", &arr[i]);
        printf("%lld\n", sortAndCount(arr, 0, n - 1));
    }
    return 0;
}