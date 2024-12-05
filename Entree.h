#pragma once
#include "AbstractComponent.h"
class Entree :
    public AbstractComponent
{
public :
    Entree(std::string nom, std::string details, std::string type);
    ~Entree();
    std::string getDetails() const;
    std::string getType() const;
    double getFrais() override;
    void execute() override;
    double getFrais() override;
    std::vector<std::shared_ptr<AbstractComponent>> getEnfants() const override;
protected :
    std::string details, type;
};

