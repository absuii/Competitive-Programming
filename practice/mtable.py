n=int(input())
a=[i*(n+1-i)for i in range(1,n+1)]
a.sort()
m=a[n//2]
print(m)
