#include "EntreeHebergement.h"
using namespace std;

EntreeHebergement::EntreeHebergement(string nom, string details)
    : Entree(nom, details, "Hebergement") {
    // Exemple pour hébergement : Nom Hôtel,Type,Adresse,Prix par nuit,Devise
    istringstream ss(details);
    getline(ss, ville, ',');
    getline(ss, secteur, ',');
    getline(ss, coteSur10, ',');
    getline(ss, prixUnitaire, ',');
    getline(ss, devise, ',');
    note = stod(coteSur10);
    prix = stod(prixUnitaire);
    if (devise == "EURO") {
        prix *= 1.5;
    }
}
double EntreeHebergement::getFrais() {
    return prix;
}