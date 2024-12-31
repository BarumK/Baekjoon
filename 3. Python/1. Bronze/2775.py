# initialization
test_case = int(input())

# loop test_case times
for _ in range(test_case):
    #initialization
    k = int(input()) + 1; n = int(input()) + 1
    
    # memoization method; max k floors and max n rooms in each floors
    members = [[0 for _ in range(n)] for _ in range(k)] # initialization
    for i in range(k):
        if i == 0:
            for j in range(1, n):
                members[i][j] = j # 0th floor
        else:
            for j in range(1, n):
                members[i][j] = sum(members[i - 1][1:j + 1])
    
    # print phase
    print(members[k - 1][n - 1])