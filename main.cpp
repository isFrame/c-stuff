#include <iostream>
#include <ostream>
#include <vector>
struct Libro {
  int cod_num;
  int num_pag;
  double costo;
};
void stampa_libro(const Libro &libro) {
  std::cout << "Id:" << libro.cod_num << "\t";
  std::cout << "Pagine: " << libro.num_pag << "\t";
  std::cout << "Costo: " << libro.costo << "$" << std::endl;
};
void media(const Libro &libro) {
  if (libro.num_pag == 0) {
    std::cout << "Errore: numero pagine non valido\n";
    return;
  }
  float media_libro = (libro.costo / libro.num_pag);
  std::cout << "Id: " << libro.cod_num;
  std::cout << "\t" << "Costo per pagina: " << media_libro << "$" << std::endl;
}

void inserisci_dati(Libro &libro) {
  std::cout << "Inserisci ID: ";
  std::cin >> libro.cod_num;
  std::cout << "Inserisci Numero di Pagine: ";
  std::cin >> libro.num_pag;
  std::cout << "Inserisci costo: ";
  std::cin >> libro.costo;
  std::cout << "\n";
}

int main() {
  int qnum;
  std::vector<Libro> libri;
  std::cout << "Quanti libri vuoi registrare?: ";
  std::cin >> qnum;

  for (int i = 0; i < qnum; i++) {
    Libro Temp_Libro;
    std::cout << "Inserisci i dati del libro " << i + 1 << ":" << std::endl;
    inserisci_dati(Temp_Libro);
    libri.push_back(Temp_Libro);
  }
  while (true) {
    int opzione;
    std::cout << "1) Calcola la media \n2) Visualizza dati\n3) Cancella e "
                 "rinserisci\n4) Esci\n";
    std::cout << "\nInput: ";
    std::cin >> opzione;
    std::cout<<"\n";
    while (opzione > 4) {
      std::cout << "Opzione non esiste riprova: ";
      std::cin >> opzione;
    }
    switch (opzione) {
    case 1:
      for (int i = 0; i < qnum; i++) {
        media(libri[i]);
      }
      std::cout << "\n";
      break;
    case 2:
      for (int i = 0; i < qnum; i++) {
        stampa_libro(libri[i]); 
      }
      std::cout<<"\n";
      break;
    case 3:
      libri.clear();
      for (int i = 0; i < qnum; i++) {
        Libro Temp_Libro;
        std::cout << "Inserisci i dati del libro " << i + 1 << ":" << std::endl;
        inserisci_dati(Temp_Libro);
        libri.push_back(Temp_Libro);
      }
      break;
    case 4:
      return 0;
    }
  }
}
