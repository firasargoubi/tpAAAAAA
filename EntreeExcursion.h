#pragma once
#include "Entree.h"
class EntreeExcursion :
    public Entree
{
public :
    EntreeExcursion(std::string nom, std::string details);
	~EntreeExcursion();
	double getFrais() override;

private :
    std::string ville, etoiles, prixUnitaire, devise;
	double nbEtoile, prix;
};
