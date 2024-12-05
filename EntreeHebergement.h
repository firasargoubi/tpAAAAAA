#pragma once
#include "Entree.h"
class EntreeHebergement :
    public Entree
{
    public :
	EntreeHebergement(std::string nom, std::string details);
	~EntreeHebergement();
	double getFrais() override;

private :
    std::string ville, secteur, devise, coteSur10, prixUnitaire;
	double note, prix;
};