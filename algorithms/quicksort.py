def quicksort(a):
    left = []
    right = []
    equal = []
    pivot = a[0]
    for i in a:
        if i > pivot:
            right.append(i)
        elif i < pivot:
            left.append(i)
        else:
            equal.append(i)
    if len(left) > 1:
        left = quicksort(left)
    if len(right) > 1:
        right = quicksort(right)
    a = left + equal + right
    return a

n = int(input())
a = list(map(int, input().split()))
a = quicksort(a)
print(" ".join(map(str, a)))
