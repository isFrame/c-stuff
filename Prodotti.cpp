#include <iostream>
#include <string>
#include <vector>

struct Prodotto {
  int ID;
  std::string prod;
  int num_prod;
  double prez_vendita;
  double prez_acquisto;
};
std::vector<Prodotto> prodotti{
    {1, "boh", 20, 2.50, 3.00},
    {2, "Ciao", 20, 2.50, 3.00},
    {3, "Hey", 20, 2.50, 3.00},
};

void print(const Prodotto &a) {
  std::cout << "ID: " << a.ID << "\tProdotto: " << a.prod
            << "\tProdotti disponibili: " << a.num_prod
            << "\tPrezzo vendita: " << a.prez_vendita
            << "\tPrezzo acquisto: " << a.prez_acquisto << "\n";
}
void buy(Prodotto &a) {
  int buyq;
  std::cout << "Quanto vuole comprare: ";
  std::cin >> buyq;
  while (a.num_prod - buyq < 0) {
    std::cout << "Non ci sono abbastanza prodotti \tProdotti disponibili:"
              << a.num_prod << "\nRiprova:";
    std::cin >> buyq;
  }
  a.num_prod = a.num_prod - buyq;
  std::cout << "Acquisto avvenuto con successo!\n";
}
void sell(Prodotto &a) {
  int sellq;
  std::cout << "Quanto vuole vendere: ";
  std::cin >> sellq;
  a.num_prod = a.num_prod + sellq;
  std::cout << "Vendita avvenuta con sucesso!\n";
}

int main() {
  while (true) {
    int input;
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
      int id;
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