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

void Utente::update(Subject *list, std::string& s) {
    std::cout << s << std::endl;

}

void Utente::add(ListaSpesa *l, Prodotto* p) {
    auto it = std::find(subjects.begin(), subjects.end(), l);

    if(it != subjects.end()){
        l->addProd(p, this->name);
    } else{
        std::cout << "La lista della spesa" << l->getName() << "non è presente nelle tue liste" << std::endl;
    }
}

void Utente::remove(ListaSpesa *l, Prodotto* p) {
    auto it = std::find(subjects.begin(), subjects.end(), l);

    if(it != subjects.end()){
        l->removeProd(p, this->name);
    } else{
        std::cout << "La lista della spesa" << l->getName() << "non è presente nelle tue liste" << std::endl;
    }
}

void Utente::modify(ListaSpesa *l, Prodotto* p, int q) {
    auto it = std::find(subjects.begin(), subjects.end(), l);

    if(q>0){
        if(it != subjects.end())
            l->modifyQuantity(p, q, this->name);
        else
            std::cout << "La lista della spesa" << l->getName() << "non è presente nelle tue liste" << std::endl;

    }else{
        std::cerr << "È stato inserito un valore non valido di prodotti" << std::endl;
    }
}

void Utente::displayList(ListaSpesa *l) {
    l->display();
}

const std::string &Utente::getName() const {
    return name;
}

void Utente::setName(const std::string &name) {
    Utente::name = name;
}


