def plusOne(self, A):
    # num = 0
    # n = len(A)
    # for i in range(len(A)):
    #     num += pow(10, i)*A[n-i-1]
    # return list(str(num+1))
    # A = ltrim(A)
    
    # i = 0
    # while A[i] == 0 and i<len(A):
    #     i += 1
    # A = A[i:]
    # n = len(A)
    
    A = list(''.join(list(map(str, A))).lstrip("0"))
    A = list(map(int, A))
    n = len(A)
    if n == 0:
        A = [0]
    A[n-1] += 1
    for i in range(n):
        if A[n-i-1] == 10:
            A[n-i-1] = 0
            if n-i-2 >= 0:
                A[n-i-2] += 1
            else:
                A.insert(0, 1)
    return A