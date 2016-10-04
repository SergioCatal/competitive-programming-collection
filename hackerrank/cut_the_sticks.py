n = int(input())
a = list(map(int, input().split()))
print(n)
cont = 2
while cont > 1:
    m = 1001
    for i in range(0,len(a)):
        if a[i] > 0 and a[i] < m:
            m = a[i]
    cont = 0
    for i in range(0,len(a)):
        a[i] = a[i] - m
        if a[i] > 0:
            cont += 1
    if cont > 0:
        print(cont)



