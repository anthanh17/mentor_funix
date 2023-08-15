a = int(input())
b = int(input())

def power(a, b):
    ans = 1
    for i in range(b):
        ans *= a
    return ans
print(power(a, b))