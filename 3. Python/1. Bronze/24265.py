n = int(input())
print(int((n - 1) * n / 2), "\n", 2, sep = "")

# 1     -> 2     ~ n  (n - 2 + 1 = n - 1)
# 2     -> 3     ~ n  (n - 3 + 1 = n - 2)
# 3     -> 4     ~ n  (n - 4 + 1 = n - 3)
# ...
# n - 3 -> n - 2 ~ n  (n - n + 2 + 1 = 3)
# n - 2 -> n - 1 ~ n  (n - n + 1 + 1 = 2)
# n - 1 -> n     ~ n  (n - n + 1 = 1)
# => 1 + 2 + ... + (n - 2) + (n - 1) = (n - 1) * n / 2
# 1부터 n까지의 합 = n * (n - 1) / 2임을 이용