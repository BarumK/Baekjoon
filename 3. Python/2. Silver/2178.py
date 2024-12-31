# 입력 받고 변수 선언
N, M = map(int, input().split())
input_list = [str(input()) for _ in range(N)]
for i in range(len(input_list)):
    input_list[i] = [0] + list(map(int, list(str(input_list[i])))) + [0]
input_list = [[0] * (M + 2)] + input_list + [[0] * (M + 2)]
visited = [[False] * (M + 2) for _ in range(N + 2)]
visited[1][1] = True

def bfs(lst, vstd, N, M):                                                         # bfs 함수 선언
    count = 1
    queue = [[1, 1]]

    while (len(queue) != 0):                                                    # 빈 큐가 될때까지 반복
        temp = []
        
        # 한 레벨 탐색
        for i in range(len(queue)):
            x, y = queue[i][0], queue[i][1]
            if (lst[x][y - 1] == 1) and (vstd[x][y - 1] == False):              # 상
                if x == N and (y - 1) == M:                                     # 도착하면 리턴
                    return (count + 1)
                temp.append([x, y - 1])
                vstd[x][y - 1] = True
            if (lst[x + 1][y] == 1) and (vstd[x + 1][y] == False):              # 우
                if (x + 1) == N and y == M:                                     # 도착하면 리턴
                    return (count + 1)
                temp.append([x + 1, y])
                vstd[x + 1][y] = True
            if (lst[x][y + 1] == 1) and (vstd[x][y + 1] == False):              # 하
                if x == N and y + 1 == M:                                       # 도착하면 리턴
                    return (count + 1)
                temp.append([x, y + 1])
                vstd[x][y + 1] = True
            if (lst[x - 1][y] == 1) and (vstd[x - 1][y] == False):              # 좌
                if (x - 1) == N and y == M:                                     # 도착하면 리턴
                    return (count + 1)
                temp.append([x - 1, y])
                vstd[x - 1][y] = True
        
        # 다음 레벨 순회를 위한 갱신
        count += 1
        queue = temp

print(bfs(input_list, visited, N, M))