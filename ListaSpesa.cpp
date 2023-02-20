//
// Created by Riccardo Becciolini on 19/02/23.
//

#include "ListaSpesa.h"

void ListaSpesa::addProd(Prodotto& p) {
    products.push_back(p);
    notify();
}

void ListaSpesa::removeProd(Prodotto& p) {
    products.remove(p);
    notify();
}

void ListaSpesa::subscribe(Observer* o) {
    observers.push_back(o);
}

void ListaSpesa::unsubscribe(Observer* o) {
    observers.remove(o);
}

void ListaSpesa::notify() {
    for(auto it: observers) {
        it->update(this);
    }
}

const std::string &ListaSpesa::getName() const {
    return name;
}

void ListaSpesa::setName(const std::string &n) {
    name = n;
}

void ListaSpesa::modifyQuantity(Prodotto &p, int q) {
    auto it = std::find(products.begin(),products.end(),p);

    if(it != products.end()){
        it->setQuantity(q);
    }
    else{
        std::cout << "Il prodotto selezionato non è presente nella lista " << this->name << std::endl;
    }

}

