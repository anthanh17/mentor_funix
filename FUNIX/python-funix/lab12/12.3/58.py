n = int(input())

def sumOfAll(n):
    ans = []
    for i in range(1,n):
        if (n % i == 0):
            ans.append(i)
    cnt = 0
    for x in ans:
        cnt += x
    return cnt

print(sumOfAll(n))
