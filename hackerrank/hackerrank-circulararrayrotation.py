n, k, q = list(map(int, input().split(' ')))
a = list(map(int, input().split(' ')))
b = list(a)
for i in range(0, len(a)):
    pos = (i + k)%n
    b[pos] = a[i]
out = []
for i in range(0, q):
    tmp = int(input())
    out.append(b[tmp])
for x in out:
    print(x)
