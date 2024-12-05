#pragma once
#include "AbstractComponent.h"
class Categorie :
    public AbstractComponent
{
public :
    Categorie(std::string nom);
	~Categorie();
	void ajouterEnfant(std::string nom, std::string details);
	std::vector<std::shared_ptr<AbstractComponent>> getEnfants() const override;
	void execute() override;
	double getFrais() override;
private :
	std::vector<std::shared_ptr<AbstractComponent>> enfants;

};

