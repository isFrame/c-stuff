#include "prodotti.h"
#include <iostream>

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