
#include <iostream>
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include "Catalogue.h"
#include "Cell.h"
#include "ListeChainee.h"

int main() {
  char* depart = "Lyon";
  char* arrivee = "Paris";
  char* modeTransport = "auto";
  Trajet trajetOne(depart, arrivee);
  TrajetSimple trajetSimpleTwo(depart, arrivee, modeTransport);
  trajetOne.Afficher();
  trajetSimpleTwo.Afficher();

/* 
  Cell cell1(&trajetOne);
  ListeChainee lsch;
  lsch.addElem(&cell1);
  lsch.Afficher();
  return 0; */

  Catalogue c1;
  c1.Init();

}
