#include "AbstractComponent.h"
using namespace std;

AbstractComponent::AbstractComponent(string nom) : nom(nom), hasChild(false) {}

bool AbstractComponent::hasChildren() const {
	return hasChild;
}

string AbstractComponent::getNom() const {
	return nom;
}