
#include <iostream>
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include "Catalogue.h"

int main() {
  char* depart = "Lyon";
  char* arrivee = "Paris";
  char* modeTransport = "auto";
  Trajet trajetOne(depart, arrivee);
  TrajetSimple trajetSimpleTwo(depart, arrivee, modeTransport);
  trajetOne.Afficher();
  trajetSimpleTwo.Afficher();

  return 0;
}
