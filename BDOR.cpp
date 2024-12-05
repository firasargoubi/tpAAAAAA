#include "BDOR.h"
using namespace std;

void BDOR::remplirBDOR() {

    auto transport = make_shared<Categorie>("Transport");
    auto hebergement = make_shared<Categorie>("Hebergement");
    auto excursion = make_shared<Categorie>("Excursions");

    categories.push_back(transport);
    categories.push_back(hebergement);
    categories.push_back(excursion);
    for (const auto& categorie : categories) {
        categorie->execute();
    }

}

shared_ptr<EntreeProxy> BDOR::trouverEntree(const string& nom) {
    if (categories.size() == 0) {
		cerr << "Erreur : Aucune entrée trouvée!" << endl;
		return nullptr;
	}
    for (const auto& categorie : categories) {
        if (categorie->hasChildren()) {
            auto enfants = dynamic_pointer_cast<Categorie>(categorie)->getEnfants();
            for (const auto& enfant : enfants) {
                auto entree = dynamic_pointer_cast<Entree>(enfant);
                if (entree && entree->getNom() == nom) {
                    return make_shared<EntreeProxy>(entree);
                }
            }
        }
    }
    cerr << "Erreur : Aucune entrée avec le nom " << nom << " trouvée!" << endl;
    return nullptr;
}