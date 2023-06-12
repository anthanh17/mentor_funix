import json
import requests
from typing import Optional
from bs4 import BeautifulSoup
import xml.etree.ElementTree as ET

class Employee:
  tax_data = {}
  fine_level = []
  def __init__(self, id, name, salary_base, working_days, department,
              working_performance, bonus, late_days) -> None:
    self.id = id
    self.name = name
    self.salary_base = salary_base
    self.working_days = working_days
    self.department = department
    self.working_performance = working_performance
    self.bonus = bonus
    self.late_days = late_days

  @staticmethod
  def format_currency(currency):
    currency = str(currency)
    count = 0
    ans = []
    for x in currency[::-1]:
      if count != 3:
        count += 1
      ans.append(x)
      if count == 3:
        ans.append(",")
        count = 0
    ans = ans[::-1]
    if (ans[0] == ","):
      ans.pop(0)
    return "".join(ans) + " VND"

  @staticmethod
  def download_page(url: str) -> Optional[str]: # url can None => Optional
    res = requests.get(url)
    if res.status_code != requests.codes.ok:
      print(f'Cannot get page, eror: {res.status_code}')
      return
    return res

  # trich xuat du lieu web
  @classmethod
  def web_data_extraction(cls):
    tax_url = "https://firebasestorage.googleapis.com/v0/b/funix-way.appspot.com/o/xSeries%2FChung%20chi%20dieu%20kien%2FPYB101x_1.1%2FASM_Resources%2Ftax.xml?alt=media&token=f7a6f73d-9e6d-4807-bb14-efc6875442c7"
    htmlXML = Employee.download_page(tax_url)
    if htmlXML is None:
      print(f"Cannot get page.")

    root = ET.fromstring(htmlXML.content)

    min = []
    max = []
    value = []
    for x in root.findall('tax'):
      if x.find('min') is not None:
        min.append(float(x.find('min').text))
      if x.find('max') is not None:
        max.append(float(x.find('max').text))
      if x.find('value') is not None:
        value.append(float(x.find('value').text))

    cls.tax_data["min"] = min
    cls.tax_data["max"] = max
    cls.tax_data["value"] = value

    fine_level_url = "https://firebasestorage.googleapis.com/v0/b/funix-way.appspot.com/o/xSeries%2FChung%20chi%20dieu%20kien%2FPYB101x_1.1%2FASM_Resources%2Flate_coming.json?alt=media&token=55246ee9-44fa-4642-aca2-dde101d705de"
    htmlJSON = Employee.download_page(fine_level_url)
    if htmlJSON is None:
        print(f"Cannot get page.")

    cls.fine_level = htmlJSON.json()

  # Hien thi danh sach nhan vien
  @staticmethod
  def show_staff_list():
    f = open('data.json')
    try:
      data = json.load(f)
    except:
      data = {}
    f.close()

    print("========== Danh sach nhan vien ==========")
    if (len(data) == 0):
      print("data empty")
    else:
      for i in data["NhanVien"]:
        print("---------")
        print("Ma so:", i['id'])
        print("Ma bo phan:", i['department_code'])
        print("Chuc vu:", i['position'])
        print("Ho va ten:", i['name'])
        print("He so luong:", Employee.format_currency(i['salary_base']))
        print("So ngay lam viec:", i['working_days'])
        print("He so hieu qua:", i['working_performance'])
        print("Thuong:", Employee.format_currency(i['bonus']))
        print("So ngay di muon:", i['late_comming_days'])
        print("---------")

  # kiem tra nhap thong tin data
  @staticmethod
  def check_input_emp(input_str, key, item, parts_list = None):
    # Nhap string
    if key == "id" or key == "department_code" or key == "position" or key == "name":
      while(1):
        data_value = str(input(input_str))
        if data_value:
          # position
          if key == "position":
            if data_value == "ql" or data_value == "nv":
              item[key] = data_value
              break
            else:
              print("Ban chon 1 trong 2 (nv/ql)!")
          # department_code
          elif key == "department_code":
            isList = False
            for i in parts_list:
              if (i["id"] == data_value):
                isList = True
            if isList:
              item[key] = data_value
              break
            else:
              print("Nhan vien thuoc 1 trong cac bo phan sau: ")
              for v in parts_list:
                print("-",v["id"])
          else:
            item[key] = data_value
            break
        else:
          print(" --------------------------------------- ")
          print("* Ban khong duoc bo trong thong tin nay *")
          print(" --------------------------------------- ")
    # Nhap so
    else:
      while(1):
        try:
          data_value = float(input(input_str))
          if data_value:
            if data_value > 0:
              item[key] = data_value
              break
            else:
              print("Ban phai nhap 1 so duong!")
          else:
            print(" --------------------------------------- ")
            print("* Ban khong duoc bo trong thong tin nay *")
            print(" --------------------------------------- ")
        except:
          print(" --- ")
          print("* Ban nhap khong dung format (kieu so) *")
          print(" --- ")


  # them nhan vien moi
  @staticmethod
  def add_new_employees():
    f = open('data.json')
    try:
      data = json.load(f)
    except:
      data = {}
    f.close()

    print("----")
    print("Them nhan vien moi ...")
    item = {}

    while(1):
      id = str(input("Nhap ma so: "))
      check = False
      for i in data["NhanVien"]:
        if i['id'] == id:
          check = True
      if id:
        if check == True:
          print("Ma nhan vien da ton tai!")
        else:
          item['id'] = id
          break
      else:
        print("*****************************************")
        print("* Ban khong duoc bo trong thong tin nay *")
        print("*****************************************")

    Employee.check_input_emp("Nhap ma bo phan: ", "department_code", item, data["BoPhan"])
    Employee.check_input_emp("Nhap chuc vu (nv / ql): ", "position", item)
    Employee.check_input_emp("Nhap ho va ten: ", "name", item)
    Employee.check_input_emp("Nhap he so luong: ", "salary_base", item)
    Employee.check_input_emp("Nhap so ngay lam viec: ", "working_days", item)
    Employee.check_input_emp("Nhap he so hieu qua: ", "working_performance", item)
    Employee.check_input_emp("Nhap thuong: ", "bonus", item)
    Employee.check_input_emp("Nhap so ngay đi muon: ", "late_comming_days", item)

    data["NhanVien"].append(item)
    ans = {
        "BoPhan": data["BoPhan"],
        "NhanVien": data["NhanVien"]
    }
    # Serializing json
    json_object = json.dumps(ans, indent=4)

    # Writing to sample.json
    with open("data.json", "w") as outfile:
      outfile.write(json_object)

    print("Đa them nhan vien moi ...")
    print("----")

  # xoa nhan vien theo ID
  @staticmethod
  def delete_staff_according_to_ID():
    f = open('data.json')
    try:
      data = json.load(f)
    except:
      data = {}
    f.close()

    print("----")
    while(1):
      id = input("Nhap ma nhan vien muon xoa: ")
      if id:
        not_found = True
        for i in data["NhanVien"]:
          if i['id'] == id:
            data["NhanVien"].remove(i)
            ans = {
              "BoPhan": data["BoPhan"],
              "NhanVien": data["NhanVien"]
            }
            json_object = json.dumps(ans, indent=4)
            with open("data.json", "w") as outfile:
              outfile.write(json_object)
            print("Đa xoa thanh cong")
            print("----")
            not_found = False
            break
        if not_found:
          print("Ma nhan vien khong ton tai!")
        break
      else:
        print("*****************************************")
        print("* Ban khong duoc bo trong thong tin nay *")
        print("*****************************************")

  # tinh so tien di muon
  @staticmethod
  def calculate_fine(late_days):
    # [0 -> ) = late_comming_days *20000
    if Employee.fine_level[0]["min"] <= late_days < Employee.fine_level[0]["max"]:
      return late_days * Employee.fine_level[0]["value"]
    # [3 -> 6) = late_comming_days *30000
    elif Employee.fine_level[1]["min"] <= late_days < Employee.fine_level[1]["max"]:
      return late_days * Employee.fine_level[1]["value"]
    # [6 -> ... = late_comming_days *50000
    elif Employee.fine_level[2]["min"] <= late_days:
      return late_days * Employee.fine_level[2]["value"]

  @staticmethod
  def calculate_tax(income):
    m_income = float(income / 1000000)
    if Employee.tax_data["min"][0] <= m_income < Employee.tax_data["max"][0]:
      return float(income * Employee.tax_data["value"][0] / 100)
    elif Employee.tax_data["min"][1] <= m_income < Employee.tax_data["max"][1]:
      return float(income * Employee.tax_data["value"][1] / 100)
    elif Employee.tax_data["min"][2] <= m_income:
      return float(income * Employee.tax_data["value"][2] / 100)

  def departmental_bonus(self, parts_list):
    for i in parts_list:
      if self.department == i.id:
        return float(i.bonus_salary)

  def employee_salary_display(self, parts_list):
    Employee.web_data_extraction()
    # tổng thu nhập chưa thưởng = (salary_base * working_days) * working_performance
    income = (float(self.salary_base) * float(self.working_days)) * float(self.working_performance)
    # tổng thu nhập  = tổng thu nhập chưa thưởng + bonus + thưởng bộ phận - phạt đi muộn
    income = income + float(self.bonus) + self.departmental_bonus(parts_list) - Employee.calculate_fine(float(self.late_days))
    tax = Employee.calculate_tax(income)
    # Nhân viên sẽ cần trích ra 10.5% thu nhập để đóng bảo hiểm:
    # tổng thu nhập chưa thuế = tổng thu nhập * 89.5 %
    income *= 0.895
    real_money_received = income - tax
    print("Ma so: ", self.id)
    # TODO
    print("Thu nhap thuc nhan: ", Employee.format_currency(real_money_received))
    print("----")

  @staticmethod
  def check_change_emp(input_str, key, item):
    # Nhap string
    if key == "department_code" or key == "position" or key == "name":
      while(1):
        data_value = str(input(input_str))
        if data_value:
          # position
          if key == "position":
            if data_value == "ql" or data_value == "nv":
              item[key] = data_value
              return item[key]
            else:
              print("Ban chon 1 trong 2 (nv/ql)!")
          else:
            item[key] = data_value
            return item[key]
        else:
          return item[key]
    # Nhap so
    else:
      while(1):
        data_value = input(input_str)
        # Neu co data
        if data_value:
          try:
            data_value = float(data_value)
            if data_value > 0:
              item[key] = data_value
              return item[key]
            else:
              print("Ban phai nhap 1 so duong!")
          except:
            print(" --- ")
            print("* Ban nhap khong dung format (kieu so) *")
            print(" --- ")
        # Neu trong thi ko lam gi ca
        else:
          return item[key]

  # chinh sua nhan vien
  def Employee_edit():
    f = open('data.json')
    try:
      data = json.load(f)
    except:
      data = {}
    f.close()

    print("========== Chinh sua nhan vien ==========")
    id_input = input("Nhap ma nhan vien: ")

    name_input = ""
    position_input = ""
    salary_input = 0
    working_days_input = 0
    performance_input = 0
    bonus_input = 0
    late_days_input = 0
    # Kiem tra xem id nhap vao co trong hay ko
    if id_input:
      not_found = True
      for i in data["NhanVien"]:
        # Neu tim duoc id trung
        if id_input == i['id']:
          not_found = False
          name_input = Employee.check_change_emp("Nhap ho va ten: ", "name", i)
          position_input = Employee.check_change_emp("Nhap chuc vu (nv/ql): ", "position", i)
          salary_input = Employee.check_change_emp("Nhap he so luong: ", "salary_base", i)
          working_days_input = Employee.check_change_emp("Nhap so ngay lam viec: ", "working_days", i)
          performance_input = Employee.check_change_emp("Nhap he so hieu qua: ", "working_performance", i)
          bonus_input = Employee.check_change_emp("Nhap thuong: ", "bonus", i)
          late_days_input = Employee.check_change_emp("Nhap so ngay di muon: ", "late_comming_days", i)
          ans = {
            "BoPhan": data["BoPhan"],
            "NhanVien": data["NhanVien"]
          }
          # Serializing json
          json_object = json.dumps(ans, indent=4)

          # Writing to sample.json
          with open("data.json", "w") as outfile:
            outfile.write(json_object)

          print("--- Da hoan tat chinh sua  ---")
          print("---------")
          print("Ma so:", id_input)
          print("Ma bo phan:", i['department_code'])
          print("Chuc vu:", position_input)
          print("Ho va ten:", name_input)
          print("He so luong:", Employee.format_currency(salary_input))
          print("So ngay lam viec:", working_days_input)
          print("He so hieu qua:", performance_input)
          print("Thuong:", Employee.format_currency(bonus_input))
          print("So ngay di muon:", late_days_input)
          print("---------")
          break
      if not_found:
        print("Ma nhan vien khong ton tai!")
    else:
      print("Ban khong thay doi gi!")
      return
