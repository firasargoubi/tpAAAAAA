#include "EntreeProxy.h"
using namespace std;



EntreeProxy::EntreeProxy(shared_ptr<Entree> copy) : Entree(copy->getNom(), copy->getDetails(), copy->getType()), copy(copy) {

}

shared_ptr<Entree> EntreeProxy::getCopy() {
    return copy;
}

double EntreeProxy::getFrais() {
    return copy->getFrais();
}
