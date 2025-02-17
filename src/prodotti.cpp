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
  int BuyQuantity=input_validation("Quanto vuole comprare: ");
  while (a.num_prod - BuyQuantity < 0) {
    std::cout << "Non ci sono abbastanza prodotti \tProdotti disponibili:"
              << a.num_prod;
    BuyQuantity=input_validation("\nRiprova: ");
  }
  a.num_prod -=BuyQuantity;
  std::cout << "Acquisto avvenuto con successo!\n";
}
void sell(Prodotto &a) {
  int SellQuantity=input_validation("Quanto vuole vendere: ");
  a.num_prod-=SellQuantity;
  std::cout << "Vendita avvenuta con sucesso!\n";
}
void insert(Prodotto &a ,int &i){
  std::cout<<"Inserisci i dati del prodotto: "<< i+1<<"\n";
  //Id del prodotto
  a.ID=input_validation("Inserisci ID: ");
  //Nome del prodotto
  std::cout<<"Inserisci nome del prodotto: ";
  std::cin.ignore();
  std::getline(std::cin,a.prod);
  //Quantita di prodotto
  a.num_prod=input_validation("Inserisci Quantita: ");
  //Prezzo di vendita
  a.prez_vendita=input_validation("Inserisci Prezzo Di Vendita: ");
  //Prezzo di acquisto
  a.prez_acquisto=input_validation("Inserisci Prezzo Di Acquisto: ");
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
int input_validation(const std::string &message){
  int input;
  std::cout<<message;
  while (!(std::cin>>input)){
    std::cout<<"Inserire un numero:";
    std::cin.clear();
    std::cin.ignore(10000,'\n');
  }
  return input;
}