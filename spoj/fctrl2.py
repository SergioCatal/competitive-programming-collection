dp = {}

def fact(n):
    if n in dp:
        return dp[n]
    else:
        dp[n] = n*fact(n-1)
        return dp[n]


dp[0] = 1
dp[1] = 1
dp[2] = 2
T = int(input())
for t in range(T):
    n = int(input())
    print(fact(n))
