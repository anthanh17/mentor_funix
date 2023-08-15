#include <stdio.h>

struct Employee {
  char name[30];
  char date[15];
  float salary;
};

int main() {

  struct Employee emp = {"Tuan", "30/6/2023", 17682000};

  printf("\nEmployee information: \n");
  printf("Name: %s", emp.name);

  printf("\nHire date: %s", emp.date);

  printf("\nSalary: %f", emp.salary);

  return 0;

}
