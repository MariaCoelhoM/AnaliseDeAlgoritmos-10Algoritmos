/*
 * Problema: Letter Combinations of a Phone Number (LeetCode 17)
 * Link: https://leetcode.com/problems/letter-combinations-of-a-phone-number/ 
 * Tecnica: Backtracking
 *
 * Explicacao:
 *   Dado uma string contendo digitos de 2 a 9,
 *   retornar todas as combinacoes possiveis
 *   de letras que o numero pode representar.
 *
 *   Cada digito possui um conjunto de letras:
 *
 *      2 -> abc
 *      3 -> def
 *      4 -> ghi
 *      5 -> jkl
 *      6 -> mno
 *      7 -> pqrs
 *      8 -> tuv
 *      9 -> wxyz
 *
 *   Utilizamos Backtracking para gerar
 *   todas as combinacoes possiveis.
 *
 *   Em cada posicao:
 *
 *      - escolhemos uma letra correspondente
 *        ao digito atual
 *
 *      - adicionamos essa letra na combinacao
 *
 *      - chamamos recursivamente para o proximo digito
 *
 *      - removemos a letra ao voltar da recursao
 *
 *   Quando atingimos o final da string,
 *   adicionamos a combinacao na resposta.
 *
 * Complexidade:
 *   Tempo:  O(4^n)
 *            cada digito pode gerar ate 4 letras
 *
 *   Espaco: O(n)
 *            profundidade da recursao
 */
#include <stdlib.h>
#include <string.h>

char* lettersMap[] = {
    "", "", "abc", "def",
    "ghi", "jkl", "mno",
    "pqrs", "tuv", "wxyz"
};

void backtrack(
    char* digits,
    int index,
    char* current,
    char** result,
    int* returnSize
) {

    if (digits[index] == '\0') {

        result[*returnSize] =
            (char*)malloc(strlen(current) + 1);

        strcpy(result[*returnSize], current);

        (*returnSize)++;

        return;
    }

    int digit = digits[index] - '0';

    char* letters = lettersMap[digit];

    for (int i = 0; letters[i] != '\0'; i++) {

        current[index] = letters[i];
        current[index + 1] = '\0';

        backtrack(
            digits,
            index + 1,
            current,
            result,
            returnSize
        );
    }
}

/* O LeetCode espera esta assinatura exata */
char** letterCombinations(char* digits, int* returnSize) {

    *returnSize = 0;

    if (digits == NULL || digits[0] == '\0')
        return NULL;

    char** result =
        (char**)malloc(10000 * sizeof(char*));

    char current[20];

    backtrack(
        digits,
        0,
        current,
        result,
        returnSize
    );

    return result;
}