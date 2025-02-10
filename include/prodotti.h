#ifndef PRODOTTI_H
#define PRODOTTI_H
#include <string>

struct Prodotto {
    int ID;
    std::string prod;
    int num_prod;
    double prez_vendita;
    double prez_acquisto;
  };
  void print(const Prodotto &a);
  void buy(Prodotto &a);
  void sell(Prodotto &a);
  void insert(Prodotto &a,int &i);
#endif