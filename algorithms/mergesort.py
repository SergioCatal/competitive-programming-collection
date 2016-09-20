def mergesort(a):
    if len(a) == 1:
        return a
    b = mergesort(a[:int(len(a)/2)])
    c = mergesort(a[int(len(a)/2):])
    d = []
    i = 0
    j = 0
    while i < len(b) and j < len(c):
        if b[i] < c[j]:
            d.append(b[i])
            i += 1
        else:
            d.append(c[j])
            j += 1
    while i < len(b):
        d.append(b[i])
        i += 1
    while j < len(c):
        d.append(c[j])
        j += 1
    return d


n = int(input())
a = list(map(int, input().split()))
a = mergesort(a)
print(" ".join(map(str,a)))
