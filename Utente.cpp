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
        std::cout << "La lista della spesa " << l->getName() << " non è presente nelle tue liste" << std::endl;
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
        std::cout << "La lista della spesa " << l->getName() << " non è presente nelle tue liste" << std::endl;
        return 1;
    }
}

int Utente::displayList(std::shared_ptr<ListaSpesa>l) {
    auto it = std::find_if(subjects.begin(), subjects.end(), [&l](Subject* subj) {
        return dynamic_cast<ListaSpesa*>(subj) == l.get();
    });
    if(it != subjects.end()) {
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "In questa lista sono presenti " << l->getSize() << " prodotti"<<std::endl;

        int i = 1;

        std::cout << std::endl;
        std::cout << l->getName() << std::endl;
        std::cout << std::endl;
        std::cout << "        Prodotto            Categoria          Quantità          " << std::endl;
        for(auto itr: l->getProducts()){
            if(itr->isBought1()){
                std::cout << std::endl;
                std::cout << "   ✓    "<< std::left << std::setw(20) << itr->getName()<<std::setw(20)
                          <<itr->getCategory()<<  itr->getQuantity() <<   std::endl;
                i++;}
            else{
                std::cout << std::endl;
                std::cout << "   -    "<< std::left << std::setw(20) << itr->getName()<<std::setw(20)
                          <<itr->getCategory()<<  itr->getQuantity() << std::endl;
                i++;
            }

        }

        std::cout << std::endl;
        return 0;
    }else{
        std::cout << "La lista della spesa " << l->getName() << " non è presente nelle tue liste" << std::endl;
        return 1;
    }
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
        std::cout << "La lista della spesa " << l->getName() << " non è presente nelle tue liste" << std::endl;
        return 1;
    }

}

const std::list<std::shared_ptr<Prodotto>>& Utente::getProducts(std::shared_ptr<ListaSpesa> l) const {
    auto it = std::find_if(subjects.begin(), subjects.end(), [&l](Subject* subj) {
        return dynamic_cast<ListaSpesa*>(subj) == l.get();
    });

    if(it != subjects.end()) {
        return l->getProducts();
    }else{
        static std::list<std::shared_ptr<Prodotto>> emptyList;
        return emptyList;
    }

}



