#ifndef PRODOTTI_H
#define PRODOTTI_H
#include <string>
#include <vector>

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
  void create_csv(const std::vector<Prodotto> &prodotti,std::string &filename);
  int input_validation(const std::string &message);
#endif