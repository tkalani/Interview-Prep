def pow(self, x, n, d):
    x = x%d
    res = 1
    
    while n>0:
        if self.isOdd(n):
            res = (res*x)%d
    
        n = n//2
        x = (x*x)%d
        
    return res