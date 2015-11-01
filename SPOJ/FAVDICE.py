import sys,math
t=int(sys.stdin.readline())
while t>0:
    n=int(sys.stdin.readline())
    y=0
    i=n
    while i>0:
        y+=float(n*1/i)
        i-=1 
    print('%.2f\n'%y)
    t-=1
