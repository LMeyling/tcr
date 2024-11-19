/* Linear Systems
 ** n
 * Ax = B or something like that
 */
 
//START
MOD = 998244353

def linear_equations(mat, vec):
    n = len(mat)
    m = len(mat[0])
    assert n == len(vec)
    aug = [mat[i] + [vec[i]] for i in range(n)]
    rank = 0
    p = []
    q = []
    for j in range(m + 1):
        for i in range(rank, n):
            if aug[i][j] != 0:
                break
        else:
            q.append(j)
            continue
        if j == m: return -1, [], []
        p.append(j)
        aug[rank], aug[i] = aug[i], aug[rank]
        inv = pow(aug[rank][j], MOD - 2, MOD)
        for k in range(m + 1):
            aug[rank][k] *= inv
            aug[rank][k] %= MOD
        for i in range(n):
            if i == rank: continue
            c = -aug[i][j]
            for k in range(m + 1):
                aug[i][k] += c * aug[rank][k]
                aug[i][k] %= MOD
        rank += 1
    dim = m - rank
    sol = [0] * m
    for i in range(rank):
        sol[p[i]] = aug[i][-1]
    vecs = [[0] * m for _ in range(dim)]
    for i in range(dim):
        vecs[i][q[i]] = 1
    for i in range(dim):
        for j in range(rank):
            vecs[i][p[j]] = -aug[j][q[i]] % MOD
    return dim, sol, vecs
//END
