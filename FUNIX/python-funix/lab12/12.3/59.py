n = int(input())

def is_abundant(n):
    ans = []
    for i in range(1,n):
        if (n % i == 0):
            ans.append(i)
    cnt = 0
    for x in ans:
        cnt += x
    return cnt > n

print(is_abundant(n))
