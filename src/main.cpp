#include <iostream>
#include <vector>
#include "prodotti.h"

std::vector<Prodotto> prodotti{
    {1, "boh", 20, 2.50, 3.00},
    {2, "Ciao", 20, 2.50, 3.00},
    {3, "Hey", 20, 2.50, 3.00},
};

int main() {
  while (true) {
    int input;
    int id;
    bool found = false;
    std::cout << "1) List\n2) Compra\n3) Vendi\n4) Esci\n\nInput:";
    std::cin >> input;
    switch (input) {
    case 1:
      for (int i = 0; i < 3; i++) {
        print(prodotti[i]);
      }
      break;
    case 2:
      for (int i = 0; i < 3; i++) {
        print(prodotti[i]);
      }
      std::cout << "inserire ID: ";
      std::cin >> id;
      for (int i = 0; i < 3; i++) {
        if (prodotti[i].ID == id) {
          buy(prodotti[i]);
          found = true;
        }
      }
      if (!found) {
        std::cout << "ID non esistente!\n\n";
        break;
      }
      break;
    case 3:
      
      for (int i = 0; i < 3; i++) {
        print(prodotti[i]);
      }
      std::cout << "inserire ID: ";
      std::cin >> id;
      for (int i = 0; i < 3; i++) {
        if (prodotti[i].ID == id) {
          sell(prodotti[i]);
          found = true;
        }
      }
      if (!found) {
        std::cout << "ID non esistente!\n\n";
        break;
      }
      break;
    case 4:
      return 0;
    default:
      std::cout << "Opzione non esistente";
    }
  }
}