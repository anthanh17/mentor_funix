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
        print("Luong cua nhan vien " + str(self.name) + " nhan duoc trong thang " + str(self.month) + " la: " + str(self.total) + " VND")

class QuanLy(NhanVien):
    performance = 0.0
    def __init__(self, name, month, salary_per_day, day_of_working, coefficient, performance):
        super().__init__(name, month, salary_per_day, day_of_working, coefficient)
        self.performance = performance
    
    def tinh_luong_thuong(self):
        self.tinh_luong()
        bonus = 0
        if self.performance < 1:
            bonus = self.total * self.performance
        else:
            bonus = self.total * (self.performance - 1) * 0.85
        self.total += bonus

name = str(input())
data = str(input()).split(" ")
# name = "hai dang"
# data = [4, 1000000, 15, 1.7, 1.5]

data = [float(i) for i in data]

ql = QuanLy(name, data[0], data[1], data[2], data[3], data[4])
ql.tinh_luong_thuong()
ql.hien_thi_luong()