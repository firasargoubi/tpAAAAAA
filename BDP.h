#pragma once
#include "AbstractComponent.h"
class BDP
{
public :
    BDP();
	void ajouterReservation(std::shared_ptr<AbstractComponent> reservation);
	std::vector<std::shared_ptr<AbstractComponent>> getReservations() const;
private:
    std::vector<std::shared_ptr<AbstractComponent>> reservations;
};
