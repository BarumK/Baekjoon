n, k = map(int, input().split())
c = []
for i in range(n):
	c.append(int(input()))
dp = [1] + [0 for _ in range(k)]
for i in c:
	for j in range(1, k+1):
		if j - i >= 0:
			dp[j] += dp[j-i] print(dp[k])
