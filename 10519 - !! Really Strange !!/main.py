while 1:
    try:
        n = int(input());
    except:
        break;
    if n == 0:
        print(1)
    else: 
        print(n**2 - n + 2)
