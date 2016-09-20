x, y, n = list(map(int,input().split()))

def fib(n):
    if n == 1:
        return x
    if n == 2:
        return y
    return fib(n-1)**2+fib(n-2)

print(fib(n))

