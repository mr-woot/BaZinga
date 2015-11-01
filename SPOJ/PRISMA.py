import sys,math
t=int(sys.stdin.readline())
while t>0:
    v=int(sys.stdin.readline())
    p = 0.66666666666666666
    s=(math.sqrt(27)/2)*((4*v)**p)
    print('%.10f\n'%s)
    t-=1
