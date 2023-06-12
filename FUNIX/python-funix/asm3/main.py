from Employee import Employee
from Manager import Manager
from Department import Department
import json

if __name__ == '__main__':
  while(1):
    print(" * * * * * * * * * * * * * * * * * *")
    print("* 1. Hien thi danh sach nhan vien   *")
    print("* 2. Hien thi danh sach bo phan     *")
    print("* 3. Hien thi bang luong            *")
    print("* 4. Xoa nhan vien theo ID          *")
    print("* 5. Xoa bo phan theo ID            *")
    print("* 6. Them nhan vien moi             *")
    print("* 7. Chinh sua nhan vien            *")
    print("* 8. Thoat                          *")
    print(" * * * * * * * * * * * * * * * * * * ")
    print("Moi ban nhap chuc nang mong muon: ...")

    try:
      option = int(input())
    except:
      print("Lua chon khong phu hop")
      print("Ban se chon cac chuc nang (1 -> 8)\n")
      continue
    if option == 1:
      Employee.show_staff_list()
    elif option == 2:
      Department.show_parts_list()
    elif option == 3:
      f = open('data.json')
      try:
        data = json.load(f)
      except:
        data = {}
      f.close()

      parts_list = []
      for i in data["BoPhan"]:
        parts_list.append(Department(i["id"], i["bonus"]))

      list_employee = []
      for i in data["NhanVien"]:
        if i["position"] == "nv":
          list_employee.append(
            Employee(
              i["id"],
              i["name"],
              i["salary_base"],
              i["working_days"],
              i["department_code"],
              i["working_performance"],
              i["bonus"],
              i["late_comming_days"]))

        elif i["position"] == "ql":
          list_employee.append(
            Manager(
              i["id"],
              i["name"],
              i["salary_base"],
              i["working_days"],
              i["department_code"],
              i["working_performance"],
              i["bonus"],
              i["late_comming_days"]))
      #print(bo_parts_listphan)
      for emp in list_employee:
        emp.employee_salary_display(parts_list)
    elif option == 4:
      Employee.delete_staff_according_to_ID()
    elif option == 5:
      Department.delete_parts_by_ID()
    elif option == 6:
      Employee.add_new_employees()
    elif option == 7:
      Employee.Employee_edit()
    elif option == 8:
      break
    else:
      print("Lua chon khong phu hop")
      print("Ban se chon cac chuc nang (1 -> 7)\n")
