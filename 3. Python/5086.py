n, m = map(int, input().split())
while True:
    if n == 0 and m == 0:
        break
    if n >= m:
        if n % m == 0: print("multiple")
        else: print("neither")
    else:
        if m % n == 0: print("factor")
        else: print("neither")
    n, m = map(int, input().split())