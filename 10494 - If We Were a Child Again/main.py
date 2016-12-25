while 1:
    try:
        a,o,b = input().split()
    except:
        break
    a = int(a)
    b = int(b)
    if o == "/":
        print(a // b)
    else:
        print(a%b)

