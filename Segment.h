#pragma once
#include "AbstractComponent.h"
#include "BDOR.h"
#include "BDP.h"
#include "Voyage.h"
class Segment :
    public AbstractComponent
{
public :
    Segment(std::string nom, std::shared_ptr<BDOR> bdor, std::shared_ptr<BDP> bdp, std::string nomVoyage);
    void ajouterEnfant(std::shared_ptr<AbstractComponent> enfant);
    void retirerEnfant(std::string nom);
    void execute() override;
    double getFrais() override;
    std::string getNomVoyage() const;
    std::vector<std::shared_ptr<AbstractComponent>> getEnfants() const;

private:
    std::vector<std::shared_ptr<AbstractComponent>> enfants;
    std::shared_ptr<BDOR> bdor;
    std::shared_ptr<BDP> bdp;
    std::string nomVoyage;
};



class SegmentFactory {
public:
    static std::shared_ptr<Segment> create(const std::string& nom, std::shared_ptr<Voyage> voyage, std::shared_ptr<BDOR> bdor, std::shared_ptr<BDP> bdp) {
        return make_shared<Segment>(nom, bdor, bdp, voyage->getNom());
    }
};