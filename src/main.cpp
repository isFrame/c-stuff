#include "prodotti.h"
#include <iostream>
#include <string>
#include <vector>

std::vector<Prodotto> prodotti;
std::string filename = "Magazzino.csv";

int main() {
  while (true) {
    int input;
    int id;
    bool found = false;
    std::cout << "1) Inserisci \n2) List\n3) Compra\n4) Vendi\n5) Cerca\n6) "
                 "Crea .csv \n7) Esci\n\n";
    input=input_validation("Input: ");
    switch (input) {
    case 1:
      int pnum;
      pnum=input_validation("Quanti prodotti vuoi inserire?: ");
      while (pnum < 1) {
        pnum=input_validation("Errore:inserire almeno un prododotto \nRiprova:");
      }
      for (int i = 0; i < pnum; i++) {
        Prodotto temp_prod;
        insert(temp_prod, i);
        prodotti.push_back(temp_prod);
      }
      break;
    case 2:
      if (prodotti.empty()){
        std::cout<<"Nessun prodotto registrato"<<std::endl;
        break;
      }
      for (const auto &prodotto : prodotti) {
        print(prodotto);
      }
      break;
    case 3:
      if (prodotti.empty()){
        std::cout<<"Nessun prodotto registrato"<<std::endl;
        break;
      }
      for (const auto &prodotto : prodotti) {
        print(prodotto);
      }
      id=input_validation("inserire ID: ");
      for (auto &prodotto : prodotti) {
        if (prodotto.ID == id) {
          buy(prodotto);
          found = true;
        }
      }
      if (!found) {
        std::cout << "ID non esistente!\n\n";
        break;
      }
      break;
    case 4:
      if (prodotti.empty()){
        std::cout<<"Nessun prodotto registrato"<<std::endl;
        break;
      }
      for (const auto &prodotto : prodotti) {
        print(prodotto);
      }
      id=input_validation("inserire ID: ");
      for (auto &prodotto : prodotti) {
        if (prodotto.ID == id) {
          sell(prodotto);
          found = true;
        }
      }
      if (!found) {
        std::cout << "ID non esistente!\n\n";
        break;
      }
      break;
    case 5:
      if (prodotti.empty()){
        std::cout<<"Nessun prodotto registrato"<<std::endl;
        break;
      }
      id=input_validation("inserire ID: ");
      for (const auto& prodotto:prodotti) {
        if (prodotto.ID == id) {
          print(prodotto);
          found = true;
        }
      }
      if (!found) {
        std::cout << "ID non esistente\n";
      }
      break;
    case 6:
      if (prodotti.empty()){
        std::cout<<"Nessun prodotto registrato"<<std::endl;
        break;
      }
      create_csv(prodotti, filename);
      break;
    default:
      std::cout << "Opzione non esistente";

    case 7:
      return 0;
    }
  }
}