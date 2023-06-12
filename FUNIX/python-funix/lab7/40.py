lst = []
n = int(input())

for i in range(n):
    lst.append(int(input()))

answer = []
for v in lst:
    if v % 2 != 0:
        answer.append(v)

print(answer)