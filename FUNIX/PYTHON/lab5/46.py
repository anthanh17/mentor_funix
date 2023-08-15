def sum_of_list(lst):
    answer = 0
    for v in lst:
        answer += v
    return answer

lst = []
n = int(input())
for i in range(n):
    lst.append(int(input()))
print(sum_of_list(lst))