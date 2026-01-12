#include <iostream>           
#include <thread>             
#include "Semaphore.hpp"

int ressourcePartagee;
int nbrLecteur = 0;
Semaphore semLecteur(1); // Gérer les lecteurs
Semaphore accesRessource(1); // protège ressource

void lecteur(int numLecteur){
    semLecteur.P(0);
    nbrLecteur = nbrLecteur + 1;
    if(nbrLecteur == 1)
    {
      accesRessource.P(0);
    }
    semLecteur.V(0);
    for (int i = 0; i < 4; i++){
      // Lecture
      std::cout << "Lecteur n° " << numLecteur << " en cours " << endl;
      this_thread::sleep_for(chrono::milliseconds(rand() % 20000) );
      std::cout << "        Valeur lue = " << ressourcePartagee << "  " << endl;
    }
    semLecteur.P(0);
    nbrLecteur = nbrLecteur - 1;
    if(nbrLecteur == 0)
      accesRessource.V(0);
    semLecteur.V(0);
}

void ecrivain(int numEcrivain){
    accesRessource.P(0);
    // Ecriture
    int x;
    for (int i = 0; i < 4; i++){
      std::cout << "Ecrivain n° " << numEcrivain << " en cours " << endl;
      x = ressourcePartagee;
      this_thread::sleep_for(chrono::milliseconds(rand() % 20000) );
      std::cout << "valeur à incrémenter de la ressourcePartagee = " << x << "  " << endl;
      ressourcePartagee = x+1 ;
    }
    accesRessource.V(0);
}

int main() {
  const int nbr = 8;
  std::thread r[nbr];
  std::thread w[nbr];
  ressourcePartagee = 0;

  for (int i = 1; i < nbr; i++){
    r[i] = std::thread(lecteur, -i);
    w[i] = std::thread(ecrivain, i);
  }
// Join des threads 
  for (int i = 1; i < nbr; i++) {
  r[i].join(); 
  w[i].join();   
  }
  return 0;
}
