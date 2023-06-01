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

void Utente::update(const std::string& s) {
    std::cout << s << std::endl;
}

int Utente::add(std::shared_ptr<ListaSpesa> l, std::shared_ptr<Prodotto> p) {
    auto it = std::find_if(subjects.begin(), subjects.end(), [&l](Subject* subj) {
        return dynamic_cast<ListaSpesa*>(subj) == l.get();
    });

    if(it != subjects.end()){
        l->addProd(p, this->name);
        return 0;
    } else{
        std::cout << "La lista della spesa" << l->getName() << "non è presente nelle tue liste" << std::endl;
        return 1;
    }
}

int Utente::remove(std::shared_ptr<ListaSpesa> l, std::shared_ptr<Prodotto> p) {
     auto it = std::find_if(subjects.begin(), subjects.end(), [&l](Subject* subj) {
        return dynamic_cast<ListaSpesa*>(subj) == l.get();
    });

    if(it != subjects.end()){
        l->removeProd(p, this->name);
        return 0;
    } else{
        std::cout << "La lista della spesa" << l->getName() << "non è presente nelle tue liste" << std::endl;
        return 1;
    }
}

int Utente::modify(std::shared_ptr<ListaSpesa> l, std::shared_ptr<Prodotto> p, int q) {
     auto it = std::find_if(subjects.begin(), subjects.end(), [&l](Subject* subj) {
        return dynamic_cast<ListaSpesa*>(subj) == l.get();
    });
    if(it != subjects.end()) {
        l->modifyQuantity(p, q, this->name);
        return 0;
    }
    else{
        std::cout << "La lista della spesa" << l->getName() << "non è presente nelle tue liste" << std::endl;
        return 1;
    }
}

void Utente::displayList(std::shared_ptr<ListaSpesa>l) {
    l->display();
}

const std::string &Utente::getName() const {
    return name;
}

void Utente::setName(const std::string &name) {
    Utente::name = name;
}

const std::list<Subject *> &Utente::getSubjects() const {
    return subjects;
}

int Utente::buy(std::shared_ptr<ListaSpesa> l, std::shared_ptr<Prodotto> p) {
     auto it = std::find_if(subjects.begin(), subjects.end(), [&l](Subject* subj) {
        return dynamic_cast<ListaSpesa*>(subj) == l.get();
    });


    if(it != subjects.end()){
        l->buyProd(p, this->name);
        return 0;
    } else{
        std::cout << "La lista della spesa" << l->getName() << "non è presente nelle tue liste" << std::endl;
        return 1;
    }

}


