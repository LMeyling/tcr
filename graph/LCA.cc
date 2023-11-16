/* LCA
 ** fast
 * input = parent of n-1 verticest (0 is root)
 */

//START
from sys import stdin
from collections import deque

class UnionFind():
    def __init__(self, p):
        N = len(p)
        timer = 0
        cnt = [0] * N
        que = deque()
        self.parent_or_size = [-1] * N
        self.parent = [0] * N
        self.edge = [0] * N
        self.order = [0] * N
        
        for i in range(N):
            cnt[p[i]] += 1
        
        for i in range(N):
            if cnt[i] == 0:
                que.append(i)
        
        for _ in range(N - 1):
            v = que.popleft()
            par = p[v]
            x, y = self.leader(v), self.leader(par)
            if self.parent_or_size[x] > self.parent_or_size[y]: x, y = y, x
            self.parent_or_size[x] += self.parent_or_size[y]
            self.parent_or_size[y] = x
            self.parent[y] = x
            self.edge[y] = par
            self.order[y] = timer
            timer += 1
            cnt[par] -= 1
            if cnt[par] == 0: que.append(par)
        
        self.order[self.leader(0)] = timer
    
    def leader(self, v):
        if self.parent_or_size[v] < 0: return v
        self.parent_or_size[v] = self.leader(self.parent_or_size[v])
        return self.parent_or_size[v]
    
    def lca(self, u, v):
        lcav = v
        while u != v:
            if self.order[u] < self.order[v]: u, v = v, u
            lcav = self.edge[v]
            v = self.parent[v]
        return lcav

N, Q = map(int, stdin.readline().split())
p = [0] + list(map(int, stdin.readline().split()))

uf = UnionFind(p)

for _ in range(Q):
    query = list(map(int, stdin.readline().split()))
    print(uf.lca(query[0], query[1]))
//END
