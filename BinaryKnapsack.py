def knapsack(v,w,n,W):
    V=[[0]*(W+1) for _ in range(n+1)]
    keep=[[0]*(W+1) for _ in range(n+1)]
    for i in range (1,n+1):
        for wt in range(W+1):
            if w[i]<=wt and v[i]+V[i-1][wt-w[i]]>V[i-1][wt]:
                V[i][wt]=v[i]+V[i-1][wt-w[i]]
                keep[i][wt]=1
            else:
                V[i][wt]=V[i-1][wt]
    
    k=W
    print("Items chosen: ")
    for i in range(n,0,-1):
        if keep[i][k]==1:
            print(f'{i} ')
            k=k-w[i]
    
    return V[n][W]

v=[0,20,40,60]
w=[0,5,14,10]
n=3
W=20

cost=knapsack(v,w,n,W)
print("Cost: ", cost)
            