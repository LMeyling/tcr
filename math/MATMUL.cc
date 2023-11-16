/* MATMUL
 ** N^3

 */
 
//START
def mat_pro(A,B):
    N,M,K = len(A),len(A[0]),len(B[0])
    C = [[0]*K for _ in range(N)]
    for i in range(N):
        row_A = A[i]
        row_C = C[i]
        for j in range(M):
            a = row_A[j]
            row_B = B[j]
            for k in range(K):
                row_C[k] = (row_C[k]+a*row_B[k])%mod
    return C
mod = 998244353
//END
