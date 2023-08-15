class NhanVien:
    name = ""
    month = 0
    salary_per_day = 0
    day_of_working = 0
    coefficient = 0
    total = 0

    def __init__(self, name, month, salary_per_day, day_of_working, coefficient) -> None:
        self.name = name
        self.month = int(month)
        self.salary_per_day = int(salary_per_day)
        self.day_of_working = int(day_of_working)
        self.coefficient = coefficient

    def tinh_luong(self):
        sum = self.salary_per_day * self.day_of_working * self.coefficient - 1000000
        if sum > 9000000:
            sum = 0.9 * sum
        self.total = int(sum)

    def hien_thi_luong(self):
        self.tinh_luong()
        print("Luong cua nhan vien " + str(self.name) + " nhan duoc trong thang " + str(self.month) + " la: " + str(self.total) + " VND")

name = str(input())
data = str(input()).split(" ")
data = [float(i) for i in data]
nv = NhanVien(name, data[0], data[1], data[2], data[3])
nv.hien_thi_luong()