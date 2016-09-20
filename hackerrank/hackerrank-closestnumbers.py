n = int(input())
a = list(map(int, input().split()))
a = sorted(a)
sol = []
i = 2
minDiff = a[1]-a[0]
sol.append(1)

while i < n:
    diff = a[i]-a[i-1]
    if diff == minDiff:
        sol.append(i)
    if diff<minDiff:
        minDiff = diff
        sol.clear()
        sol.append(i)
    i += 1
strSol = ""

for i in sol:
    strSol = strSol + str(a[i-1]) + " " + str(a[i]) + " "
print(strSol)


