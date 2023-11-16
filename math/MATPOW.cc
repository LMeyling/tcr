/* MATPOW
 ** N^3

 */
 
//START
from typing import Callable, Optional

class MatrixMod:
    _mod = 998244353
    def __init__(self, n: int, m: int, from_array: Optional[list[list[int]]] = None) -> None:
        self._n = n
        self._m = m
        if from_array is None:
            self._matrix = [[0] * m for _ in range(n)]
        else:
            self._matrix = [row[:] for row in from_array]

    @classmethod
    def set_mod(cls, mod: int) -> None:
        cls._mod = mod

    @classmethod
    def ie(cls, n: int) -> "MatrixMod":
        ret = cls(n, n)
        for i in range(n):
            ret[i, i] = 1
        return ret

    def is_square(self) -> bool:
        return self._n == self._m

    def __str__(self) -> str:
        return "\n".join(" ".join(map(str, row)) for row in self._matrix)

    def __getitem__(self, idxs: tuple[int, int]) -> int:
        return self._matrix[idxs[0]][idxs[1]]

    def __setitem__(self, idxs: tuple[int, int], value: int) -> None:
        self._matrix[idxs[0]][idxs[1]] = value

    def __add__(self, other: 'MatrixMod') -> 'MatrixMod':
        assert self._n == other._n and self._m == other._m
        ret = MatrixMod(self._n, self._m)
        for i in range(self._n):
            res_i = ret._matrix[i]
            self_i = self._matrix[i]
            other_i = other._matrix[i]
            for j in range(self._m):
                res_i[j] = (self_i[j] + other_i[j]) % self._mod
        return ret

    def __pos__(self) -> 'MatrixMod':
        return self

    def __neg__(self) -> 'MatrixMod':
        ret = MatrixMod(self._n, self._m)
        for i in range(self._n):
            res_i = ret._matrix[i]
            self_i = self._matrix[i]
            for j in range(self._m):
                res_i[j] = -self_i[j] % self._mod
        return ret

    def __sub__(self, other: 'MatrixMod') -> 'MatrixMod':
        assert self._n == other._n and self._m == other._m
        ret = MatrixMod(self._n, self._m)
        for i in range(self._n):
            res_i = ret._matrix[i]
            self_i = self._matrix[i]
            other_i = other._matrix[i]
            for j in range(self._m):
                res_i[j] = (self_i[j] - other_i[j]) % self._mod
        return ret

    def __mul__(self, other: 'MatrixMod') -> 'MatrixMod':
        assert self._m == other._n
        ret = MatrixMod(self._n, other._m)
        for i in range(self._n):
            res_i = ret._matrix[i]
            self_i = self._matrix[i]
            for k in range(self._m):
                self_ik = self_i[k]
                other_k = other._matrix[k]
                for j in range(other._m):
                    res_i[j] += self_ik * other_k[j]
                    res_i[j] %= self._mod
        return ret

    def times(self, k: int) -> 'MarixMod':
        ret = MatrixMod(self._n, self._m)
        for i in range(self._n):
            res_i = ret._matrix[i]
            self_i = self._matrix[i]
            for j in range(self._m):
                res_i[j] = self_i[j] * k % self._mod
        return ret

    def __pow__(self, k: int) -> 'MatrixMod':
        assert self._n == self._m
        ret = MatrixMod.ie(self._n)
        tmp = self
        while k:
            if k & 1:
                ret = ret * tmp
            tmp = tmp * tmp
            k >>= 1
        return ret

N, K = map(int, input().split())
A = MatrixMod(N, N, from_array = [list(map(int, input().split())) for _ in range(N)])

B = A ** K

print(B)
//END
