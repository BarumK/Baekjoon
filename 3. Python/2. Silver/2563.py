# 도화지 최초설정
paper = [[0 for _ in range(100)] for _ in range(100)]

# 도화지 색칠
N = int(input())
for _ in range(N):
    x, y = map(int, input().split())
    for i in range(10):
        for j in range(10):
            paper[x + i][y + j] = 1
    
# 색칠된 넓이 구하기
result = 0
for i in range(len(paper)):
    for j in range(len(paper[i])):
        if paper[i][j] == 1: result += 1
print(result)

# 문제 풀이를 이렇게 하면 어떨까?
# 무조건 좌표가 자연수로 주어지고 길이 또한 10으로 고정된다
# 그러기에 1제곱센티미터단위로 모두 배열에 넣고 -> 더 작은 사각형으로 분할
# 왜 1단위인가? -> 주어지는 사각형 간의 최소 간격이 1단위라서임
# 0이면 색칠안됨, 1이면 색칠됨으로 설정하는 거임
# 그렇다면 그 네모 칸의 기준을 어떻게 할 것인가?
# 정사각형의 좌측 하단을 기준으로 잡는 것임
# ex) (1, 4)이면 -> (1, 4)와 (2, 5)를 꼭짓점으로 하는 정사각형 부분이 색칠됨