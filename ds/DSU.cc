/* DSU
 */
//START
class DisjointSetUnion():
    def __init__(self, n):
        self.n = n
        self.par_size = [-1] * n

    def merge(self, a, b):
        x = self.leader(a)
        y = self.leader(b)
        if x == y: return x
        if -self.par_size[x] < -self.par_size[y]: x, y = y, x
        self.par_size[x] += self.par_size[y]
        self.par_size[y] = x
        return x

    def same(self, a, b):
        return self.leader(a) == self.leader(b)

    def leader(self, a):
        x = a
        while self.par_size[x] >= 0:
            x = self.par_size[x]
        while self.par_size[a] >= 0:
            self.par_size[a] = x
            a = self.par_size[a]
        return x

    def size(self, a):
        return -self.par_size[self.leader(a)]

    def groups(self):
        leader_buf = [0] * self.n
        group_size = [0] * self.n
        res = [[] for _ in range(self.n)]
        for i in range(self.n):
            leader_buf[i] = self.leader(i)
            group_size[leader_buf[i]] += 1
        for i in range(self.n):
            res[leader_buf[i]].append(i)
        res = [res[i] for i in range(self.n) if res[i]]
        return res
//END
