/* ----------------------------
 * Problema: LASTDIG - The Last Digit (SPOJ)
 * Link: https://www.spoj.com/problems/LASTDIG/ 
 * Tecnica: Divisao e Conquista (Exponenciacao Rapida)
 *
 * Explicacao:
 *   Dado a e b, encontrar o ultimo digito de a^b.
 *   O ultimo digito de qualquer numero tem periodicidade 4 (exceto 0,1,5,6
 *   que sempre terminam em si mesmos). Usamos exponenciacao rapida mod 10.
 *   IMPORTANTE: a entrada comeca com T (numero de casos de teste).
 *
 * Complexidade:
 *   Tempo:  O(log b) por caso
 *   Espaco: O(log b) pilha de recursao
 */

#include <stdio.h>

long long fastPow(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp / 2;
        base = (base * base) % mod;
    }
    return result;
}

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        long long a, b;
        scanf("%lld %lld", &a, &b);
        if (b == 0) {
            printf("1\n");
        } else {
            printf("%lld\n", fastPow(a, b, 10));
        }
    }
    return 0;
}