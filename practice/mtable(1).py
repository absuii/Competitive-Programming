n=int(input())
print(next(x for x in range(n*n)if sum(min(x//i,n)for i in range(1,n+1))>=n*n//2+1))
