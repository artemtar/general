from difflib import SequenceMatcher


def  findMutationDistance(start, end, bank):

    if start == end:
        return 0
    if start != end and len(bank) == 0:
        return -1

    mutation_distance = lambda l1, l2: len(start) - len([1 for a, b in zip(l1, l2) if a == b])

    if mutation_distance(start, end) > len(bank):
        return -1

    values_all = bank
    values_all.append(end)
    v = len(values_all)
    values_all.insert(0, start)
    values_all = list(set(values_all))

    #distance = [[-1 for j in range(len(values_all))] for i in range(len(values_all))]

    size = len(values_all)
    distance = [[-1]*size for i in range(size)]

    for i in range(len(values_all)):
        distance[i][i] = 0


    for i in range(len(values_all)):
        for j in range(len(values_all)):
            if i != j:
                distance[i][j] = mutation_distance(values_all[i], values_all[j])

    g = graph(values_all, start, end, v)
    g.build(distance)
    return g.run()

class graph:
    def __init__(self, nodes, s, e, v):
        self.graph = [[i,[]] for i in nodes]
        self.nodes = nodes
        self.start = s
        self.end = e
        self.count = 0
        self.v = v

    def build(self, distanses):
        for i in range(len(distanses)):
            for j in range(len(distanses)):
                if distanses[i][j] == 1:
                    self.graph[i][1].append(self.nodes[j])
        for i in self.graph:
            if i[0] == self.start:
                self.start = i
            if i[0] == self.end:
                self.end = i

    def find(self, root, val, found, previous):
        if val == 0 and not found:
            l.append(-1)
            return
        for check_node in root[1]:
            if check_node == self.end[0]:
                l.append(val)
            else:
                for next in self.graph:
                    if next[0] == check_node and next[0] != previous:
                        self.find(next, val - 1, False, check_node)

    def run(self):
        val = self.find(self.start, self.v, False, None)
        m = set(l)
        n = sorted(m)
        print(n)
        if len(n) < 2:
            return -1
        else:
            return n[1]

l = []
s = 'AAAAAAAA'
e = 'AAAAAATT'
b = ['AAAAAAAA', 'AAAAAAAT', 'AAAAAATT', 'AAAAAATTT']
findMutationDistance(s, e, b)