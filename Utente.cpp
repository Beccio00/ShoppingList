//
// Created by Riccardo Becciolini on 19/02/23.
//

#include "Utente.h"

void Utente::attach(Subject* list) {
    subjects.push_back(list);
    list->subscribe(this);
}

void Utente::detach(Subject* list) {
    subjects.remove(list);
    list->unsubscribe(this);
}

void Utente::update(Subject *list) {

}

void Utente::add(ListaSpesa *l, Prodotto& p) {
    auto it = std::find(subjects.begin(), subjects.end(), l);

    if(it != subjects.end()){
        l->addProd(p);
    } else{
        std::cout << "La lista dell spesa" << l->getName() << "non è presente nelle tue liste" << std::endl;
    }
}

void Utente::remove(ListaSpesa *l, Prodotto &p) {
    auto it = std::find(subjects.begin(), subjects.end(), l);

    if(it != subjects.end()){
        l->removeProd(p);
    } else{
        std::cout << "La lista dell spesa" << l->getName() << "non è presente nelle tue liste" << std::endl;
    }
}

void Utente::modify(ListaSpesa *l, Prodotto &p, int q) {
    auto it = std::find(subjects.begin(), subjects.end(), l);

    if(it != subjects.end()){
        l->modifyQuantity(p,q);
    } else{
        std::cout << "La lista dell spesa" << l->getName() << "non è presente nelle tue liste" << std::endl;
    }
}


