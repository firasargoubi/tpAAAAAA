#include "PolyVoyage.h"
using namespace std;

PolyVoyage::PolyVoyage() {
    bdor = make_shared<BDOR>();
    bdp = make_shared<BDP>();
    bdor->remplirBDOR();
}

shared_ptr<Voyage> PolyVoyage::createVoyage(const string& nom) {
    voyage = VoyageFactory::create(nom, bdor, bdp);
    voyage->execute();
    return voyage;
}

shared_ptr<Voyage> PolyVoyage::copyVoyage(shared_ptr<Voyage> copy, const string& nom) {
    voyage = VoyageFactory::create(nom, bdor, bdp);
    for (auto segment : copy->getEnfants()) {
        shared_ptr<Segment> newSegment = createSegment(segment->getNom());
        for (auto journee : segment->getEnfants()) {
            shared_ptr<Journee> newJournee = createJournee(journee->getNom());
            for (auto reservation : journee->getEnfants()) {
                shared_ptr<Reservation> newReservation = createReservation(reservation->getNom());
                newJournee->ajouterEnfant(newReservation);
            }
            newSegment->ajouterEnfant(newJournee);
        }
        voyage->ajouterEnfant(newSegment);

    }
    cout << "Voyage " << nom << " copie a partir de Voyage de " << copy->getNom() << "!" << endl;
    return voyage;
}
// Méthode pour créer un segment via la Factory
shared_ptr<Segment> PolyVoyage::createSegment(const string& nom) {
    if (voyage == nullptr) {
        cout << "Faire un voyage avant !" << endl;
        return nullptr;
    }
    segment = SegmentFactory::create(nom, voyage, bdor, bdp);
    return segment;
}

// Méthode pour créer une journée via la Factory
shared_ptr<Journee> PolyVoyage::createJournee(const string& date) {
    if (segment == nullptr) {
        cout << "Faire un segment avant !" << endl;
        return nullptr;
    }
    journee = JourneeFactory::create(date, segment, bdor, bdp);
    return journee;
}

// Méthode pour créer une réservation via la Factory
shared_ptr<Reservation> PolyVoyage::createReservation(const string& nom) {
    if (journee == nullptr) {
        cout << "Faire une journee avant !" << endl;
        return nullptr;
    }
    reservation = ReservationFactory::create(nom, journee, bdor, bdp);
    return reservation;
}

void PolyVoyage::afficherVoyage() {
    voyage->execute();
}

shared_ptr<BDOR> PolyVoyage::getBDOR() {
    return bdor;
}
shared_ptr<BDP> PolyVoyage::getBDP() {
    return bdp;
}
