#https://www.codechef.com/INOIPRAC/problems/INOI1402

if __name__ == "__main__":
    c,f = input().split()
    c = int(c)
    f = int(f)
    
    int_max = 10**6
    cost_mat = [[int_max for j in range(c)] for i in range(c)]
    
    #print(cost_mat)    
    
    for _ in range(f):
        src,des,cost = input().split()
        src = int(src)
        des = int(des)
        cost = int(cost)
        
        cost_mat[src-1][des-1] = cost
        cost_mat[des-1][src-1] = cost
        
    for i in range(c):
        for j in range(c):
            for k in range(c):
                if(cost_mat[j][k]>cost_mat[j][i]+cost_mat[i][k]):
                    cost_mat[j][k] = cost_mat[j][i] + cost_mat[i][k]
    
    for i in range(c):
        cost_mat[i][i] = 0
    m = -1
    for i in range(c):
        for j in range(i+1,c):
            m = max(cost_mat[i][j],m)
    print(m)
            
        
        
    
