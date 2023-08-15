def get_unique_values(lst):
    answer = []
    for v in lst:
        if v not in answer:
            answer.append(v)
    return answer


n = int(input())
lst = []
for i in range(n):
    lst.append(int(input()))
print(get_unique_values(lst))