#include <stdio.h>

#define PAYRATE 12.00
#define TAXRATE_300 0.15
#define TAXRATE_450 0.20
#define TAXRATE_RESET 0.25
#define OVERTIME 40

int main() {
  unsigned int hours = 0;
  double grossPay = 0.0;
  double taxes = 0.0;
  double netPay = 0.0;

  scanf("%d", &hours);

  if (hours <= 40)
    grossPay = hours * PAYRATE;
  else {
    grossPay = 40 * PAYRATE;
    double overTimePay = (hours - 40) * (PAYRATE * 1.5);
    grossPay += overTimePay;
  }

  if (grossPay <= 300)
    taxes = grossPay * TAXRATE_300;
  else if (grossPay > 300 && grossPay <= 450) {
    taxes = 300 * TAXRATE_300;
    taxes += (grossPay - 300) * TAXRATE_450;
  } else if (grossPay > 450) {
    taxes = 300 * TAXRATE_300;
    taxes += 150 * TAXRATE_450;
    taxes += (grossPay - 450) * TAXRATE_RESET;
  }

  netPay = grossPay - taxes;

  printf("Your gross pay this week: %.2f\n", grossPay);
  printf("Your taxes this week: %.2f\n", taxes);
  printf("Your net pay this week: %.2f\n", netPay);

  return 0;
}
