#include "EntreeTransport.h"
using namespace std;

EntreeTransport::EntreeTransport(string nom, string details)
    : Entree(nom, details, "Transport") {
    // Découper la chaîne details
    istringstream ss(details);
    getline(ss, transporteur, ',');
    getline(ss, noVol, ',');
    getline(ss, lieuDepart, ',');
    getline(ss, lieuArrivee, ',');
    getline(ss, jourPrevuDepart, ',');
    getline(ss, heurePrevueDepart, ',');
    getline(ss, jourPrevuArrivee, ',');
    getline(ss, heurePrevueArrivee, ',');
    getline(ss, avion, ',');
    getline(ss, classe, ',');
    getline(ss, wifi, ',');
    getline(ss, prixUnitaire, ',');
    getline(ss, devise, ',');
    prix = stod(prixUnitaire);
    if (devise == "EURO") {
		prix *= 1.5;
	}
}

double EntreeTransport::getFrais() {
    return prix;
}