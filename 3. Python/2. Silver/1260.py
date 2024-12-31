# 입력 및 변수 선언
N, M, V = map(int, input().split())
lst = [[0] * N for _ in range(N)]
for _ in range(M):
    a, b = map(int, input().split())
    lst[a - 1][b - 1], lst[b - 1][a - 1] = 1, 1
visited1 = [False] * N
visited2 = [False] * N

# DFS
def dfs(v):
    visited1[v] = True
    print(v + 1, end=' ')
    for i in range(N):
        if (lst[v][i] == 1) and (visited1[i] == False):
            dfs(i)

# BFS
def bfs(v):
    queue = [v]
    while (len(queue) != 0):
        temp = len(queue)
        for i in range(temp):
            print(queue[i] + 1, end=' ')
            visited2[queue[i]] = True
            for j in range(N):
                if (lst[queue[i]][j] == 1) and (visited2[j] == False) and (j not in queue):
                    queue.append(j)
        for i in range(temp):
            del queue[0]



dfs(V - 1)
print("")
bfs(V - 1)