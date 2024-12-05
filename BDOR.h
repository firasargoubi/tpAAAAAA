#pragma once
#include "EntreeProxy.h"
#include "Categorie.h"

class BDOR
{
    public:
	    BDOR();
	    ~BDOR();
	    void remplirBDOR();
	    std::shared_ptr<EntreeProxy> trouverEntree(const std::string& nom);
    private:
        std::vector<std::shared_ptr<AbstractComponent>> categories;
};
