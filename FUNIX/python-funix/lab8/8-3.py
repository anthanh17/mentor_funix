n_lists = int(input())
num_lists = []
for _ in range(n_lists):
    num_lists.append(int(input()))
    
n_remove = int(input())
numbers_remove = []
for _ in range(n_remove):
    numbers_remove.append(int(input()))
    
cnt = 0
s = set(num_lists)

for num in numbers_remove:
    if num in s:
        s.remove(num)

for x in s: 
    cnt += x
print(cnt)
