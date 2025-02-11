#include <iostream>
#include <vector>
#include "prodotti.h"

std::vector<Prodotto> prodotti;

int main() {
  int pnum; //numero di prodotti
  std::cout<<"Quanti prodotti vuole inserire?: ";
  std::cin>>pnum;
  while (pnum<1) {
    std::cout<<"Errore:inserire almeno un prododotto \nRiprova:";
    std::cin>>pnum;

  }
  for (int i=0; i<pnum; i++) {
    Prodotto temp_prod;
    insert(temp_prod , i);
    prodotti.push_back(temp_prod);
  }

  while (true) {
    int input;
    int id;
    bool found = false;
    std::cout << "1) List\n2) Compra\n3) Vendi\n4) Cerca\n5) Esci\n\nInput:";
    std::cin >> input;
    switch (input) {
    case 1:
      for (int i = 0; i < pnum; i++) {
        print(prodotti[i]);
      }
      break;
    case 2:
      for (int i = 0; i < pnum; i++) {
        print(prodotti[i]);
      }
      std::cout << "inserire ID: ";
      std::cin >> id;
      for (int i = 0; i < pnum; i++) {
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
      
      for (int i = 0; i < pnum; i++) {
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
    case 5:
      return 0;
    case 4:
      std::cout<<"inserisci id: ";
      std::cin>>id;
      for (int i=0; i<pnum; i++) {
        if(prodotti[i].ID==id){
          print(prodotti[i]);
          found=true;
        }
      }
      if(!found){
        std::cout<<"ID non esistente\n";
      }
      break;
    default:
      std::cout << "Opzione non esistente";
    }
  }
}