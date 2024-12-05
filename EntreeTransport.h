#pragma once
#include "Entree.h"
class EntreeTransport :
    public Entree
{
public :
    EntreeTransport(std::string nom, std::string details);
	~EntreeTransport();
	double getFrais() override;

private:
    std::string transporteur, noVol, lieuDepart, lieuArrivee;
    std::string jourPrevuDepart, heurePrevueDepart, jourPrevuArrivee, heurePrevueArrivee;
    std::string avion, classe, wifi, prixUnitaire, devise;
    double prix;
};
