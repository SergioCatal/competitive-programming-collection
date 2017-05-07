T = int(input())
for t in range(T):
    out = ""
    seq = input()
    s = []
    for i in seq:
        if i == ')':
            out += s.pop()
        elif i == '+' or i == '-' or i == '*' or i == '/' or i == '^':
            s.append(i)
        elif i != '(':
            out += i
    print(out)
