#include "EntreeExcursion.h"
using namespace std;

EntreeExcursion::EntreeExcursion(string nom, string details)
    : Entree(nom, details, "Excursion") {
    istringstream ss(details);
    getline(ss, ville, ',');
    getline(ss, etoiles, ',');
    getline(ss, prixUnitaire, ',');
    getline(ss, devise, ',');
    nbEtoile = stod(etoiles);
    prix = stod(prixUnitaire);
    if (devise == "EURO") {
        prix *= 1.5;
    }
}


double EntreeExcursion::getFrais() {
    return prix;
}