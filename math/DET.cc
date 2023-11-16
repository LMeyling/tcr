/* DET
 ** N
 */
 
//START
mod = 998244353
def determinant(A, replace=False):
    if not replace:
        A = [a.copy() for a in A]
    n = len(A)
    res = 1
    for i, a_i in enumerate(A):
        if a_i[i] == 0:
            for j in range(i+1, n):
                if A[j][i]:
                    break
            else:
                return 0
            A[i], A[j] = A[j], A[i]
            a_i = A[i]
            res = -res
        inv = pow(a_i[i], mod-2, mod)
        for j in range(i+1, n):
            a_j = A[j]
            t = a_j[i] * inv % mod
            for k in range(i+1, n):
                a_j[k] -= t * a_i[k]
                a_j[k] %= mod
    for i in range(n):
        res *= A[i][i]
        res %= mod
    return res
//END
