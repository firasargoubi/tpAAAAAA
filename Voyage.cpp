#include "Voyage.h"
using namespace std;

Voyage::Voyage( string nom, shared_ptr<BDOR> bdor, shared_ptr<BDP> bdp)
    : AbstractComponent(nom), bdor(bdor), bdp(bdp) {
    hasChild = true;
    
}

void Voyage::ajouterEnfant(shared_ptr<AbstractComponent> segment) {
    enfants.push_back(segment);
}

void Voyage::retirerEnfant(string nom) {
    for (auto it = enfants.begin(); it != enfants.end(); ++it) {
        if ((*it)->getNom() == nom) {
            cout << "Segment " << nom << " efface!" << endl;
            enfants.erase(it);
            break;
        }
    }
}

void  Voyage::execute() {
    cout << "Voyage de " << nom << " cree!" << endl;
    for (const auto& enfant : enfants) {
        enfant->execute();
    }
}

vector<shared_ptr<AbstractComponent>> Voyage::getEnfants() const {
    return enfants;
}



double Voyage::getFrais() {
    double total = 0;
    for (const auto& segment : enfants) {
        total += segment->getFrais();
    }
    cout << "Total des frais pour le Voyage de " << nom << " ($ CA): " << total << endl;
    return total;
}