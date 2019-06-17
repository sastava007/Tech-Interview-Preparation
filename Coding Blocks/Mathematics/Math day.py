import sys
import math

t=int(input())
while t>0:
    [a,n,p]=sys.stdin.readline().rstrip().split(' ')
    a=int(a)
    n=int(n)
    p=int(p)
    n=math.factorial(n)
    ans=pow(a,n,p)
    print(ans)
    t=t-1