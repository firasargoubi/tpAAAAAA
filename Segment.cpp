#include "Segment.h"
using namespace std;


Segment::Segment(string nom, shared_ptr<BDOR> bdor, shared_ptr<BDP> bdp, string nomVoyage)
    : AbstractComponent(nom), bdor(bdor), bdp(bdp), nomVoyage(nomVoyage) {
    hasChild = true;
    
}

void Segment::ajouterEnfant(shared_ptr<AbstractComponent> child) {
    enfants.push_back(child);
}

string Segment::getNomVoyage() const { return nomVoyage; }

vector<shared_ptr<AbstractComponent>> Segment::getEnfants() const {
    return enfants;
}
void Segment::execute() {
    cout << "\tSegment " << nom << " cree dans le Voyage de " << nomVoyage << "!" << endl;
    for (const auto& enfant : enfants) {
        enfant->execute();
    }
}

double Segment::getFrais() {
	double total = 0;
    for (const auto& segment : enfants) {
		total += segment->getFrais();
	}
	cout << "\tTotal des frais pour le Segment " << nom << " ($ CA): " << total << endl;
	return total;
}