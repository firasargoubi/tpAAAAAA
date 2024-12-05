#include "Reservation.h"
using namespace std;

Reservation::Reservation(string nom, shared_ptr<BDOR> bdor, shared_ptr<BDP> bdp, string nomVoyage, string nomSegment, string nomJournee)
    : AbstractComponent(nom), bdor(bdor), bdp(bdp), nomVoyage(nomVoyage), nomSegment(nomSegment), nomJournee(nomJournee) {
    this->entree = bdor->trouverEntree(nom);
}

void Reservation::execute() {
    if (entree) {
        cout << "\t\t\tReservation creee : " << nomVoyage << "/" << nomJournee << "/" << nom << "!" << endl;
    }
}

vector<shared_ptr<AbstractComponent>> Reservation::getEnfants() const {
	return;
}

double Reservation::getFrais() {
    return entree->getCopy()->getFrais();
}