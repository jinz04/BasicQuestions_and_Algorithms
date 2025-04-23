def lcs(X,Y):
    m= len(X)
    n=len(Y)
    dp=[[0]*(n+1) for _ in range (m+1)]
    
    for i in range (m):
        for j in range (n):
            if X[i]==Y[j]:
                dp[i+1][j+1]=dp[i][j]+1
            else:
                dp[i+1][j+1]= max(dp[i][j+1], dp[i+1][j])
                
    i,j=m,n
    lcs_str=""
    while i> 0 and j>0:
        if X[i-1]==Y[j-1]:
            lcs_str=X[i-1]+lcs_str
            i-=1
            j-=1
        elif dp[i-1][j]>=dp[i][j-1]:
            i-=1
        else:
            j-=1
            
    return dp[m][n],lcs_str
X=input("Enter a string: ")
Y=input("Enter a string: ")
length, sub= lcs(X,Y)
print("Length of subsequence: ", length)
print("Subsequence: ", sub)