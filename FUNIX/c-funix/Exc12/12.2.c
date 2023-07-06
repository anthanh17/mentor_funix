#include <stdio.h>
#include <stdlib.h>

struct Item {
  char* itemName;
  int qty;
  float price;
  float amount;
};

// enter data
void readItem(struct Item* i) {
  printf("Enter product name: ");
  scanf("%s", i->itemName);

  printf("\nEnter price: ");
  scanf("%f", &i->price);

  printf("\nEnter quantity: ");
  scanf("%d", &i->qty);

  i->amount = (float)i->qty * i->price;
}

// display data
void printItem(struct Item* i) {
  printf("\nName: %s", i->itemName);
  printf("\nPrice: %.2f", i->price);
  printf("\nQuantity: %d", i->qty);
  printf("\nTotal Amount: %.2f", i->amount);
}

int main() {
  struct Item itm;
  struct Item* pItem;

  pItem = &itm;

  pItem->itemName = (char*) malloc(30 * sizeof(char));

  if (pItem == NULL) {
    exit(-1);
  }

  readItem(pItem);

  printItem(pItem);

  free(pItem->itemName);
  return 0;
}
