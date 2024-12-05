#pragma once
#include "Entree.h"
class EntreeProxy :
    public Entree
{
    public:
	EntreeProxy(std::shared_ptr<Entree> copy);
	~EntreeProxy();
	double getFrais() override;
    std::shared_ptr<Entree> getCopy();
    private:
    std::shared_ptr<Entree> copy;

};

