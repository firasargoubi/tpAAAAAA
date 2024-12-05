#include "BDP.h"
using namespace std;

BDP::BDP() {
    cout << "Objet BDP cree!" << endl;
}

void BDP::ajouterReservation(shared_ptr<AbstractComponent> reservation) {
    reservations.push_back(reservation);
    cout << "\t\t\tReservation inscrite dans BDP: " << reservation->getNom() << "!" << endl;
}

vector<shared_ptr<AbstractComponent>> BDP::getReservations() const {
    return reservations;
}