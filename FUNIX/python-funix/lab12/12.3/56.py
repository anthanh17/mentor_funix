#Initial list
res = []

# Input lengths
lengths = int(input())

# Add element
for i in range(lengths):
    # Input elements
    n = int(input())
    res.append(n)

res = [str(i) for i in res]
ans = ""
for x in res:
    ans += x
print(int(ans))
