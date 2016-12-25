while 1:
    try:
        n,a = input().split();
    except:
        break
    a = int(a)
    n = int(n)
    sum = 0
    for i in range (1, n+1):
        sum += (i * (a**i))
    print(sum)
