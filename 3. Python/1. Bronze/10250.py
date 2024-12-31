import sys

n = int(input())
for _ in range(n):
    H, W, N = map(int, sys.stdin.readline().split())
    floor = H if (N % H == 0) else N % H
    room = (N // H) if (N % H == 0) else (N // H) + 1

    print("%d%02d" %(floor, room))