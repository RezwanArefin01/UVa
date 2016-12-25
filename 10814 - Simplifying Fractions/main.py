def gcd(a,b):
    if b == 0:
        return a
    else:
        return gcd(b, a%b)
t = int(input())
for i in range (0,t):
    a,tmp,b = input().split()
    a = int(a)
    b = int(b)
    d = gcd(a,b)
    print(a//d , '/', b//d)
