T = int(input())
for t in range(T):
    a, b = list(input().split())
    a = int("".join(list(reversed(a))))
    b = int("".join(list(reversed(b))))
    print("".join(list(str(int("".join(list(reversed(str(a+b)))))))))
