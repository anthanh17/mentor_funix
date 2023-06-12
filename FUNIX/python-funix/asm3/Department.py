import json
from Employee import Employee

class Department:
  def __init__(self, id , bonus_salary) -> None:
    self.id = id
    self.bonus_salary = bonus_salary

  # Hien thi danh sach bo phan
  @staticmethod
  def show_parts_list():
    f = open('data.json')
    try:
      data = json.load(f)
    except:
      data = {}
    f.close()

    print("========== Danh sach bo phan ==========")
    if (len(data) == 0):
      print("data empty")
    else:
      for i in data["BoPhan"]:
        print("----")
        print("Ma so: ", i['id'])
        print("Thuong bo phan: ", Employee.format_currency(i['bonus']))
        print("----")

  # xoa bo phan theo ID
  @staticmethod
  def delete_parts_by_ID():
    f = open('data.json')
    try:
      data = json.load(f)
    except:
      data = {}
    f.close()

    print("----")
    while(1):
      id = input("Nhap ma bo phan muon xoa: ")
      if id:
        break
      else:
        print("*****************************************")
        print("* Ban khong duoc bo trong thong tin nay *")
        print("*****************************************")

    inDepartment = False
    for x in data['NhanVien']:
      if x['department_code'] == id:
        inDepartment = True
        break

    inStaff = False
    index = -1
    for idx, x in enumerate(data['BoPhan']):
      if x['id'] == id:
        inStaff = True
        index = idx

    # print("inDepartment:", inDepartment , "inStaff:", inStaff, "index:", index)
    if inStaff:
      if inDepartment:
        print("Ban khong the xoa bo phan co nhan vien!")
      else:
        data["BoPhan"].pop(index)
        ans = {
          "BoPhan": data["BoPhan"],
          "NhanVien": data["NhanVien"]
        }
        # Serializing json
        json_object = json.dumps(ans, indent=4)

        # Writing to sample.json
        with open("data.json", "w") as outfile:
          outfile.write(json_object)

        print("Đa xoa thanh cong")
        print("----")

    else:
      print("Ma bo phan khong ton tai!")
