#include "prodotti.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
void print(const Prodotto &a) {
  std::cout << "ID: " << a.ID << "\tProdotto: " << a.prod
            << "\tProdotti disponibili: " << a.num_prod
            << "\tPrezzo vendita: " << a.prez_vendita
            << "\tPrezzo acquisto: " << a.prez_acquisto << "\n";
}
void buy(Prodotto &a) {
  int BuyQuantity = input_validation("Quanto vuole comprare: ");
  a.num_prod += BuyQuantity;
  std::cout << "Acquisto avvenuto con successo!\n";
}
void sell(Prodotto &a) {
  int SellQuantity = input_validation("Quanto vuole vendere: ");
  while (a.num_prod - SellQuantity < 0) {
    std::cout << "Non ci sono abbastanza prodotti \tProdotti disponibili:"
              << a.num_prod;
    SellQuantity = input_validation("\nRiprova: ");
  }
  a.num_prod -= SellQuantity;
  std::cout << "Vendita avvenuta con sucesso!\n";
}
void insert(Prodotto &a, int &i, std::vector<Prodotto> &prodotti) {
  std::cout << "Inserisci i dati del prodotto: " << i + 1 << "\n";
  a.ID = input_validation("Inserisci ID: ");
  for (auto &p : prodotti) {
    while (p.ID == a.ID) {
      a.ID = input_validation("ID già esistente, Riprova: ");
    }
  }
  std::cout << "Inserisci nome del prodotto: ";
  std::cin.ignore();
  std::getline(std::cin, a.prod);
  a.num_prod = input_validation("Inserisci Quantita: ");
  a.prez_vendita = double_validation("Inserisci Prezzo Di Vendita: ");
  a.prez_acquisto = double_validation("Inserisci Prezzo Di Acquisto: ");
  std::cout << "\n";
}

void create_csv(const std::vector<Prodotto> &prodotti, std::string &filename) {
  std::ofstream db(filename);
  if (db.is_open()) {
    for (const auto &prodotto : prodotti) {
      db << prodotto.ID << "," << prodotto.prod << "," << prodotto.num_prod
         << "," << prodotto.prez_acquisto << "," << prodotto.prez_vendita
         << "\n";
    }
    db.close();
  } else {
    std::cout << "Impossibile aprire il file";
  }
}
int input_validation(const std::string &message) {
  int input;
  std::cout << message;
  while (!(std::cin >> input)) {
    std::cout << "Inserire un numero:";
    std::cin.clear();
    std::cin.ignore(10000, '\n');
  }
  return input;
}
double double_validation(const std::string &message) {
  double input;
  std::cout << message;
  while (!(std::cin >> input)) {
    std::cout << "Inserire un numero:";
    std::cin.clear();
    std::cin.ignore(10000, '\n');
  }
  return input;
}
bool check_password(const std::string PASSWORD) {
  const int TENTATIVI = 3;
  int num_tentativi = 0;
  std::string tentativo;
  std::cout << "Inserisci Password: ";
  std::cin >> tentativo;
  while (num_tentativi < TENTATIVI) {
    if (tentativo == PASSWORD) {
      return true;
    }
    num_tentativi++;
    if (num_tentativi < TENTATIVI) {
      std::cout << "Password errata \tTentativi rimanenti:"
                << TENTATIVI - num_tentativi << "\nInserisci Password: ";
      std::cin >> tentativo;
    }
  }
  std::cout << "Tentativi esauriti!" << std::endl;
  return false;
}