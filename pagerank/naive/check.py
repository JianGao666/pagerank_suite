import numpy as np

N = 0

d = 0.85

def create_data(): 
    fin = open("input.data2", "r")
    N = int(fin.readline())
    print(N)
    G = np.zeros((N, N))
    for i in range(N):
        G[i] = fin.readline().split()

    # for i in range(N):
    #     for j in range(N):
    #         print(G[i][j])
    return G, N

def GtoM(G, N):
    M = np.zeros((N, N))
    D = []
    for i in range(N):
        D_i = sum(G[i])
        if D_i == 0:
            continue
        for j in range(N):
            M[j][i] = d * G[i][j] / D_i
    return M

def PageRank(M, N, T=100, eps=1e-6):
    R = np.ones(N) / N
    c = np.empty(N)
    c.fill((1 - d) / N)
    for time in range(T):
        R_new = np.dot(M, R) 
        R_new = np.add(R_new, c)
        if np.linalg.norm(R_new - R) < eps:
            break
        R = R_new.copy()
    return R_new

G, N = create_data()

M = GtoM(G, N)

values = PageRank(M, N, 10000, 0.0001)

fout = open("check.data", "w")

fout.write("%%\n")

for i in range(N):
    fout.write(str(values[i]))
    fout.write("\n")
