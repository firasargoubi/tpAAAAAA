#include "Journee.h"
using namespace std;

Journee::Journee(string date, shared_ptr<BDOR> bdor, shared_ptr<BDP> bdp, string nomVoyage, string nomSegment)
    : AbstractComponent(date), bdor(bdor), bdp(bdp), nomVoyage(nomVoyage), nomSegment(nomSegment) {
    hasChild = true;
    cout << "\t\tJournee " << date << " creee dans le segment " << nomSegment << "!" << endl;
}


void Journee::ajouterEnfant(shared_ptr<AbstractComponent> reservation) {
    enfants.push_back(reservation);
    bdp->ajouterReservation(reservation);
}

string Journee::getNomSegment() const { return nomSegment; }
string Journee::getNomVoyage() const { return nomVoyage; }

vector<shared_ptr<AbstractComponent>> Journee::getEnfants() const {
    return enfants;
}

void Journee::execute() {
    cout << "\t\tJournee " << nom << " creee dans le segment " << nomSegment << "!" << endl;
    for (const auto& enfant : enfants) {
        enfant->execute();
    }
}

double Journee::getFrais() {
	double total = 0;
    for (const auto& reservation : enfants) {
		total += reservation->getFrais();
	}
	cout << "\t\tTotal des frais pour la journee " << nom << " ($ CA): " << total << endl;
	return total;
}
