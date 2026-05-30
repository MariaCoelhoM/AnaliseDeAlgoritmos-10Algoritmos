/* --------------------
 * Problema: Max Area of Island (LeetCode 695)
 * Link: https://leetcode.com/problems/max-area-of-island/ 
 * Tecnica: Grafos (DFS em grade)
 *
 * Explicacao:
 *   Dado uma grade binaria (0 = agua, 1 = terra),
 *   encontrar a maior area de ilha.
 *
 *   Uma ilha e formada por celulas conectadas
 *   horizontalmente ou verticalmente.
 *
 *   Para cada celula com valor 1:
 *
 *      - executamos DFS
 *      - contamos quantas celulas pertencem
 *        a mesma ilha
 *      - marcamos as celulas visitadas
 *
 *   O maior valor encontrado e a resposta.
 *
 * Complexidade:
 *   Tempo:  O(m * n)
 *            cada celula e visitada no maximo uma vez
 *
 *   Espaco: O(m * n)
 *            devido a pilha de recursao do DFS
 */

int rows, cols;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int dfs(int** grid, int r, int c) {

    if (r < 0 || r >= rows || c < 0 || c >= cols)
        return 0;

    if (grid[r][c] == 0)
        return 0;

    /* marca como visitado */
    grid[r][c] = 0;

    int area = 1;

    for (int d = 0; d < 4; d++) {
        area += dfs(grid, r + dr[d], c + dc[d]);
    }

    return area;
}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize) {

    rows = gridSize;
    cols = gridColSize[0];

    int maxArea = 0;

    for (int r = 0; r < rows; r++) {

        for (int c = 0; c < cols; c++) {

            if (grid[r][c] == 1) {

                int area = dfs(grid, r, c);

                if (area > maxArea)
                    maxArea = area;
            }
        }
    }

    return maxArea;
}