/* Min Plus
 ** n
 * Calculates the minimal addition for k of a_i + b_j such that i + j = k
 * b has to be convex!
 */

//START
def monotone_minima(n, m, f):
    min_col = [0] * n
    def dfs(x1: int, x2: int, y1: int, y2: int):
        if x1 == x2:
            return
        x = x1 + x2 >> 1
        best_y = y1
        for y in range(y1 + 1, y2):
            if f(x, best_y, y):
                best_y = y
        min_col[x] = best_y
        dfs(x1, x, y1, best_y + 1)
        dfs(x + 1, x2, best_y, y2)
    dfs(0, n, 0, m)
    return min_col

def minplus_convolution(a, b):
    n = len(a)
    m = len(b)
    def cmp(i, j, k):
        if i < k: return 0
        if i - j >= m: return 1
        return a[j] + b[i - j] >= a[k] + b[i - k]
    col = monotone_minima(n + m - 1, n, cmp)
    c = []
    for i, j in enumerate(col):
        c.append(a[j] + b[i - j])
    return c