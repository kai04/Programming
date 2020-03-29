    for _ in range(int(input())):
        n=int(input())
        a=list(map(int,input().split()))
        a.sort()
        ma=0
        for i in range(int(n/2)):
            ma+=abs(a[n-i-1]-a[i])
        mi=0
        for i in range(0,n,2):
            mi+=abs(a[i+1]-a[i])
        print(mi,ma)
