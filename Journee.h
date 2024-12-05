#pragma once
#include "AbstractComponent.h"
#include "BDOR.h"
#include "BDP.h"
#include "Segment.h"
class Journee :
    public AbstractComponent
{
public :
    Journee(std::string date, std::shared_ptr<BDOR> bdor, std::shared_ptr<BDP> bdp, std::string nomVoyage, std::string nomSegment);
    void ajouterEnfant(std::shared_ptr<AbstractComponent> enfant);
    void retirerEnfant(std::string nom);
    void execute() override;
    std::vector<std::shared_ptr<AbstractComponent>> getEnfants() const override;
    double getFrais() override;
    std::string getNomVoyage() const;
    std::string getNomSegment() const;
private:
    std::vector<std::shared_ptr<AbstractComponent>> enfants;
    std::shared_ptr<BDOR> bdor;
    std::shared_ptr<BDP> bdp;
    std::string nomVoyage, nomSegment;
};



class JourneeFactory {
public:
    static std::shared_ptr<Journee> create(const std::string& date, std::shared_ptr<Segment> segment, std::shared_ptr<BDOR> bdor, std::shared_ptr<BDP> bdp) {
        return std::make_shared<Journee>(date, bdor, bdp, segment->getNomVoyage(), segment->getNom());
    }
};