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

