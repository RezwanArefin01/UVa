while 1:
    try:
        f = [int (i) for i in input().split()]
        while (not f[len(f)-1] == -999999):
            t = [int (i) for i in input().split()]
            f.extend(t)
    except:
        break 
    Max = f[0]
    for i in range(0, len(f)-1):
        tmp = 1
        for j in range(i, len(f)-1):
            tmp *= f[j]
            if tmp > Max:
                Max = tmp
    print (Max)
