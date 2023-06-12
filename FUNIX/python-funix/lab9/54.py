a = int(input())
b = int(input())
c = int(input())

if a == b and a == c and b == c:
    print("Equilateral triangle")
elif a != b and a != c and b != c:
    print("Scalene triangle")
else:
    print("Isosceles triangle")