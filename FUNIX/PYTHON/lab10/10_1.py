class Person:
    name = ""
    toan = 0
    ly = 0
    hoa = 0
    def __init__(self, name, toan, ly, hoa) -> None:
        self.name = name
        self.toan = toan
        self.ly = ly
        self.hoa = hoa

    def __str__(self) -> str:
        dtb = float("{:.2f}".format((self.toan + self.ly + self.hoa) / 3))    
        return "The average mark of " + str(self.name) + " is " + str(dtb)
    
name = str(input())
toan = float(input())
ly = float(input())
hoa = float(input())

print(Person(name, toan, ly, hoa))