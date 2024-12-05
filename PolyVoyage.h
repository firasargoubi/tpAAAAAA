#pragma once
#include "Reservation.h"
#include "BDOR.h"
#include "BDP.h"

class PolyVoyage
{
public :
    PolyVoyage();
    std::shared_ptr<Voyage> createVoyage(const std::string& nom);
    std::shared_ptr<Voyage> copyVoyage(std::shared_ptr<Voyage> copy, const std::string& nom);
    std::shared_ptr<Segment> createSegment(const std::string& nom);
    std::shared_ptr<Journee> createJournee(const std::string& date);
    std::shared_ptr<Reservation> createReservation(const std::string& nom);
    void afficherVoyage();
    std::shared_ptr<BDOR> getBDOR();
    std::shared_ptr<BDP> getBDP();


private :
    std::shared_ptr<BDOR> bdor;
    std::shared_ptr<BDP> bdp;
    std::shared_ptr<Voyage> voyage;
    std::shared_ptr<Segment> segment;
    std::shared_ptr<Journee> journee;
    std::shared_ptr<Reservation> reservation;

};