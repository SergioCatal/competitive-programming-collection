f = {}
f[0]=1
f[1]=1

def fib(n):
    if n in f:
        return f[n]
    else:
        f[n]=fib(n-1)+fib(n-2)
        return f[n]

print(fib(int(input())))
