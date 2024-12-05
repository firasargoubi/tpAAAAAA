#pragma once
#include "AbstractComponent.h"
#include "BDOR.h"
#include "BDP.h"
#include "EntreeProxy.h"
#include "Journee.h"
class Reservation :
    public AbstractComponent
{

public :
    Reservation(std::string nom, std::shared_ptr<BDOR> bdor, std::shared_ptr<BDP> bdp, std::string nomVoyage, std::string nomSegment, std::string nomJournee);
    void execute() override;
    double getFrais() override;
    std::vector<std::shared_ptr<AbstractComponent>> getEnfants() const override;
private:
    std::shared_ptr<EntreeProxy> entree;
    std::shared_ptr<BDOR> bdor;
    std::shared_ptr<BDP> bdp;
    std::string nomVoyage, nomSegment, nomJournee;
};


class ReservationFactory {
public:
    static std::shared_ptr<Reservation> create(const std::string& nom, std::shared_ptr<Journee> journee, std::shared_ptr<BDOR> bdor, std::shared_ptr<BDP> bdp) {
        return std::make_shared<Reservation>(nom, bdor, bdp, journee->getNomVoyage(), journee->getNomSegment(), journee->getNom());
    }
};

