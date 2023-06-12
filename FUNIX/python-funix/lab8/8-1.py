students = []
for i in range(0, 10):
    students.append(float(input()))
a = set(students)
cnt = 0
for x in a:
    cnt += x
print(float("{:.2f}".format(cnt/len(a))))
