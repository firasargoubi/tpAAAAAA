#include "Entree.h"
using namespace std;


Entree::Entree(string nom, string details, string type) : AbstractComponent(nom), details(details), type(type) {

}
string Entree::getDetails() const { return details; }
string Entree::getType() const { return type; }

void Entree::execute() {
	cout << "\t\tEntree " << nom << " rattachee a la categorie " << type << " creee!" << endl;
}

double Entree::getFrais() {
	cout << "NE DEVRAIT PAS ETRE APPELLE" << endl;
	return 0;
}

vector<shared_ptr<AbstractComponent>> Entree::getEnfants() const {
	return;
}