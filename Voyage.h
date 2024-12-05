#pragma once
#include "AbstractComponent.h"
#include "BDOR.h"
#include "BDP.h"
class Voyage :
    public AbstractComponent
{
public :
    Voyage (std::string nom, std::shared_ptr<BDOR> bdor, std::shared_ptr<BDP> bdp);
    void ajouterEnfant(std::shared_ptr<AbstractComponent> enfant);
    void retirerEnfant(std::string nom);
    void execute() override;
    std::vector<std::shared_ptr<AbstractComponent>> getEnfants() const override;
    double getFrais() override;
private:
    std::vector<std::shared_ptr<AbstractComponent>> enfants;
    std::shared_ptr<BDOR> bdor;
    std::shared_ptr<BDP> bdp;
};


class VoyageFactory {
public:
    static std::shared_ptr<Voyage> create(const std::string& nom, std::shared_ptr<BDOR> bdor, std::shared_ptr<BDP> bdp) {
        return std::make_shared<Voyage>(nom, bdor, bdp);
    }
};