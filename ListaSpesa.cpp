//
// Created by Riccardo Becciolini on 19/02/23.
//

#include "ListaSpesa.h"

void ListaSpesa::addProd(Prodotto& p, std::string u) {
    products.push_back(p);
    notify(1, u);
}

void ListaSpesa::removeProd(Prodotto& p, std::string u) {
    auto it = std::find(products.begin(),products.end(),p);

    if(it != products.end()) {
        products.remove(p);
        notify(2, u);
    } else{
        std::cout << "Il prodotto selezionato non è presente nella lista " << this->name << std::endl;
    }
}

void ListaSpesa::modifyQuantity(Prodotto &p, int q, std::string u) {
    auto it = std::find(products.begin(),products.end(),p);

    if(it != products.end()){
        it->setQuantity(q);
        notify(3, u);
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

    switch (num) {
        case 1:
            s = "Nella lista della spesa " + this->name + " è stato aggiunto un prodotto da " + u;
            break;
        case 2:
            s = "Nella lista della spesa " + this->name + " è stato rimosso un prodotto da " + u;
            break;
        case 3:
            s = "Nella lista della spesa " + this->name + " è stata cambiata la quantità da comprare di un prodotto da " + u;
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
    std::cout << this->name << std::endl;
    std::cout << std::endl;
    std::cout << "        Prodotto            Categoria          Quantità" << std::endl;
    for(auto it:products){
        std::cout << std::endl;
        std::cout << "  "<< i  << "     "<< std::left << std::setw(20) << it.getName()<<std::setw(20)
            <<it.getCategory()<<  it.getQuantity() << std::endl;
        i++;
    }
}

int ListaSpesa::getSize() {
    return products.size();
}


