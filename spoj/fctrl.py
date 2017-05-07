T = int(input())
for t in range(T):
    n = int(input())
    i = 5
    res = 0
    while i <= n:
        res = res + int((n/i))
        i = i*5
    print(res)
