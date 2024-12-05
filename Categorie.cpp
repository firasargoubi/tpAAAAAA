#include "Categorie.h"
#include "EntreeTransport.h"
#include "EntreeHebergement.h"
#include "EntreeExcursion.h"
using namespace std;

Categorie::Categorie(string nom) : AbstractComponent(nom) {
    hasChild = true;
    string fileName = this->nom + ".csv";
    ifstream file(fileName);
    int i = 0;
    if (!file.is_open()) {
        cerr << "Erreur : impossible d'ouvrir le fichier " << fileName << endl;
        return;
    }

    string text;
    while (getline(file, text)) {
        if (!i) {
            i++; continue;
        }
        string delimiter = ",", nom = text.substr(0, text.find(delimiter)), details = text.substr(text.find(delimiter) + 1, text.length());
        ajouterEnfant(nom, details);
    }
    file.close();
    
}

void Categorie::ajouterEnfant(string nom, string details) {
    shared_ptr<Entree> enfant;
    if (this->nom == "Transport") {
        enfant = make_shared<EntreeTransport>(nom, details);
    }
    else if (this->nom == "Hebergement") {
        enfant = make_shared<EntreeHebergement>(nom, details);
    }
    else if (this->nom == "Excursions") {
        enfant = make_shared<EntreeExcursion>(nom, details);
    }
    enfants.push_back(enfant);
}

vector<shared_ptr<AbstractComponent>> Categorie::getEnfants() const {
    return enfants;
}

void Categorie::execute() {
    cout << "\tCategorie " << nom << " creee!" << endl;
    for (auto enfant : enfants) {
		enfant->execute();
	}
}

double Categorie::getFrais() {
	double total = 0;
    for (const auto& enfant : enfants) {
		total += enfant->getFrais();
	}
	cout << "Total des frais pour la Categorie de " << nom << " ($ CA): " << total << endl;
	return total;
}