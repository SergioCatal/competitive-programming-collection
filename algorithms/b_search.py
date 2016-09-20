def b_search(a,s,start,end):
    target = int((start+(end-start)/2))
    if start > end:
        return -1
    if s == a[target]:
        return target
    if s > a[target]:
        return b_search(a,s, target+1, end)
    if s < a[target]:
        return b_search(a,s, start, target-1)

#input: s = target, d = array size, a = array 
s = int(input())
d = int(input())
a = list(map(int, input().split()))
print(b_search(a,s,0,d))
