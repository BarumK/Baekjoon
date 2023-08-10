N = int(input())

for _ in range(N):
    score = list(map(int, input().split()))
    ave = 0

    for i in range(1, score[0] + 1):
        ave += score[i]

    ave /= score[0]
    count = 0

    for i in range(1, score[0] + 1):
        if score[i] > ave:
            count += 1

    print("%.3f%%" %((count / score[0]) * 100))