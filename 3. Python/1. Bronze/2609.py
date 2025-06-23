def gcd(a, b):
    while True:
        if (a % b == 0): return b
        else: a, b = b, a % b

a, b = map(int, input().split())
gcd_val = gcd(max(a, b), min(a, b))
print(gcd_val)
print(a * b // gcd_val)

"""
참고: https://imkh.dev/algorithm-gcd-lcm
유클리드 호제법:
두 수 a, b(a > b)의 최대공약수는 a를 b로 나눈 나머지 r에 대해, GCD(a, b) = GCD(b, r) 이라는 성질을 반복 적용하는 것.
a = bq + r (q는 몫, r은 나머지) 이라고 할 때, GCD(a, b) = GCD(b, r)이 성립함
어떠한 다른 수 x가 a와 b의 공약수라면
    a는 x로 나누어 떨어지고
    b도 x로 나누어 떨어지니까
    남아있는 r 또한 x로 나눠 떨어져야 함
이거를 반복했을때 남는 수가 결국 최대공약수인거임
이를 기반으로, a와 b가 x라는 최대공약수를 가질 때,
    a = qx, b = px가 성립함(p, q는 서로소)
    이로 인해 ab = pqx^2가 되는데, 이것을 x로 나누게 되면 그것이 최소공배수
"""