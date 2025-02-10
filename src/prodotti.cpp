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
void insert(Prodotto &a ,int &i){
  std::cout<<"Inserisci i dati del prodotto: "<< i+1<<"\n";
  std::cout<<"Inserisci ID: ";
  std::cin>>a.ID;
  std::cout<<"Inserisci nome del prodotto: ";
  std::cin>>a.prod;
  std::cout<<"Inserisci Quantita: ";
  std::cin>>a.num_prod;
  std::cout<<"Inserisci Prezzo Di Vendita: ";
  std::cin>>a.prez_vendita;
  std::cout<<"Inserisci Prezzo Di Acquisto: ";
  std::cin>>a.prez_acquisto;
  std::cout<<"\n";
}