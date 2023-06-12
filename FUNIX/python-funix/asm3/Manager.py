from Employee import Employee

class Manager(Employee):
  def __init__(self, id, name, salary_base, working_days, department,
            working_performance, bonus, late_days) -> None:
    super().__init__(id, name, salary_base, working_days, department,
                        working_performance, bonus, late_days)

  def employee_salary_display(self, parts_list):
    Employee.web_data_extraction()

    # tổng thu nhập chưa thưởng = (salary_base * working_days) * working_performance
    income = (self.salary_base * self.working_days) * self.working_performance
    # tổng thu nhập  = tổng thu nhập chưa thưởng + bonus + thưởng bộ phận - phạt đi muộn
    # các quản lý sẽ được thưởng thêm 10% thưởng bộ phận.
    income = income + self.bonus + self.departmental_bonus(parts_list) * 1.1 - Employee.calculate_fine(self.late_days)
    tax = Employee.calculate_tax(income)
    # Nhân viên sẽ cần trích ra 10.5% thu nhập để đóng bảo hiểm:
    # tổng thu nhập chưa thuế = tổng thu nhập * 89.5 %

    income *= 0.895
    real_money_received = income - tax
    print("----")
    print("Ma so: ", self.id)
    # TODO
    print("Thu nhap thuc nhan: ", Employee.format_currency(real_money_received))
    print("----")
