#include "prodotti.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
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
  std::cin.ignore();
  std::getline(std::cin,a.prod);
  std::cout<<"Inserisci Quantita: ";
  std::cin>>a.num_prod;
  std::cout<<"Inserisci Prezzo Di Vendita: ";
  std::cin>>a.prez_vendita;
  std::cout<<"Inserisci Prezzo Di Acquisto: ";
  std::cin>>a.prez_acquisto;
  std::cout<<"\n";
}

void create_csv(const std::vector<Prodotto>&prodotti,std::string &filename){
  std::ofstream db (filename);
  if(db.is_open()){
    for (const auto& prodotto :prodotti ){
      db<<prodotto.ID<<","<<prodotto.prod<<","<<prodotto.num_prod<<","<<prodotto.prez_acquisto<<","<<prodotto.prez_vendita<<"\n";
    }
    db.close();
  }
  else {
    std::cout<<"Impossibile aprire il file";
  }
}