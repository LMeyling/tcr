/* 2 Sat
 ** V+E
 * Solves 2 sat in form of Connected or Expressions
 */

//START
class TwoSAT:
    def __init__(self, n):
        self.n = n
        self.scc = StronglyConnectedComponents(2 * n)
        self.ans = [False] * self.n
    # i = first variable, f = first variable sign, j = second variable, g = second variable sign
    def add_clause(self, i, f, j, g):
        self.scc.add_edge(2 * i + (not f), 2 * j + g)
        self.scc.add_edge(2 * j + (not g), 2 * i + f)

    def satisfiable(self):
        self.scc.build()
        for i in range(self.n):
            if self.scc.labels[2 * i] == self.scc.labels[2 * i + 1]:
                return False
            self.ans[i] = self.scc.labels[2 * i] < self.scc.labels[2 * i + 1]
        return True

    def answer(self):
        return self.ans
//END
