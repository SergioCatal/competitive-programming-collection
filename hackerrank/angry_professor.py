T = int(input())
sol = []
for i in range(0,T):
    n, k = list(map(int, input().split()))
    cont = 0
    a = list(map(int,input().split()))
    for j in a:
        if j <= 0:
            cont += 1
    if cont >= k:
        sol.append("NO")
    else:
        sol.append("YES")

print("\n".join(sol))
