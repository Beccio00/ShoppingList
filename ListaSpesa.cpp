//
// Created by Riccardo Becciolini on 19/02/23.
//

#include "ListaSpesa.h"

void ListaSpesa::addProd(Prodotto* p, std::string u) {
    products.push_back(p);
    notify(1, u);
}

void ListaSpesa::removeProd(Prodotto* p, std::string u) {
    auto it = std::find(products.begin(),products.end(),p);

    if(it != products.end()) {
        products.remove(p);
        notify(2, u);
    } else{
        std::cout << "Il prodotto selezionato non è presente nella lista " << this->name << std::endl;
    }
}

void ListaSpesa::modifyQuantity(Prodotto* p, int q, std::string u) {
    auto it = std::find(products.begin(),products.end(),p);

    if(it != products.end()){
        if(q>0) {
            (*it)->setQuantity(q);
            notify(3, u);
        }
        else if(q==0){
            removeProd(p,u);
        } else{
            std::cout << "La quantità da modificare del prodotto non è valida, riprovare con una nuova quantità: " << std::endl;
            std::cin >> q;
            modifyQuantity(p, q, u);
        }


    }
    else{
        std::cout << "Il prodotto selezionato non è presente nella lista " << this->name << std::endl;
    }
}


void ListaSpesa::subscribe(Observer* o) {
    observers.push_back(o);
}

void ListaSpesa::unsubscribe(Observer* o) {
    observers.remove(o);
}

void ListaSpesa::notify(int num, std::string u) {
    std::string s;

    switch(num) {
        case 1:
            s = "Nella lista della spesa " + this->name + " è stato aggiunto un prodotto da " + u;
            break;
        case 2:
            s = "Nella lista della spesa " + this->name + " è stato rimosso un prodotto da " + u;
            break;
        case 3:
            s = "Nella lista della spesa " + this->name + " è stata cambiata la quantità da comprare di un prodotto da " + u;
            break;
        case 4:
            s = "Nella lista della spesa " + this->name + " è stato comprato un prodotto da " + u;
    }

    for(auto it: observers) {
        it->update(this, s);
    }
}

const std::string &ListaSpesa::getName() const {
    return name;
}

void ListaSpesa::setName(const std::string &n) {
    name = n;
}

void ListaSpesa::display() {
    int i = 1;

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << this->name << std::endl;
    std::cout << std::endl;
    std::cout << "        Prodotto            Categoria          Quantità          " << std::endl;
    for(auto it:products){
        if((*it).isBought1()){
            std::cout << std::endl;
            std::cout << "   ✓    "<< std::left << std::setw(20) << it->getName()<<std::setw(20)
                      <<it->getCategory()<<  it->getQuantity() <<   std::endl;
            i++;}
        else{
            std::cout << std::endl;
            std::cout << "   -    "<< std::left << std::setw(20) << it->getName()<<std::setw(20)
                      <<it->getCategory()<<  it->getQuantity() << std::endl;
            i++;
        }

    }

    std::cout << std::endl;
}

int ListaSpesa::getSize() {
    return products.size();
}

const std::list<Prodotto *> &ListaSpesa::getProducts() const {
    return products;
}

void ListaSpesa::buyProd(Prodotto* p, std::string u) {
    auto it = std::find(products.begin(),products.end(),p);

    if(it != products.end()) {
        if(!(*it)->isBought1()) {
            (*it)->setIsBought(true);
            notify(4,u);
        } else{
            std::cout << "Il prodotto selezionato è già stato comprato" << std::endl;
        }

    } else{
        std::cout << "Il prodotto selezionato non è presente nella lista " << this->name << std::endl;
    }
}



