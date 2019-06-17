import sys
def star_bar(n,k):
    ans=1
    if n==k:
        return ans
    for i in range(k):
        ans=(ans*(n-i))/(i+1)
    return int(ans)

t = int(input())
while t>0:
    [N,K]=sys.stdin.readline().rstrip().split(' ')
    N = int(N)
    K = int(K)

    n=N-1
    k=K-1
    print(star_bar(n,k))
    t=t-1