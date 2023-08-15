str = str(input())

str = str.split(" ")
ans = []
for i in str:
    if len(i) > 3:
        ans.append(i)
print(ans)
