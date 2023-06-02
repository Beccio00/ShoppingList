//
// Created by Riccardo Becciolini on 19/02/23.
//

#include "ListaSpesa.h"

void ListaSpesa::addProd(std::shared_ptr<Prodotto> p, const std::string& u) {
    products.push_back(p);
    notify(1, u);
}

int ListaSpesa::removeProd(std::shared_ptr<Prodotto> p, const std::string& u) {
    auto it = std::find(products.begin(),products.end(),p);

    if(it != products.end()) {
        products.remove(p);
        notify(2, u);
        return 0;
    } else{
        std::cout << "Il prodotto selezionato non è presente nella lista " << this->name << std::endl;
        return 1;
    }
}

int ListaSpesa::modifyQuantity(std::shared_ptr<Prodotto> p, int q, const std::string& u) {
    auto it = std::find(products.begin(),products.end(),p);

    if(it != products.end()){
        if(q>0) {
            (*it)->setQuantity(q);
            notify(3, u);
            return 0;
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
        return 1;
    }
}

int ListaSpesa::buyProd(std::shared_ptr<Prodotto> p, const std::string& u) {
    auto it = std::find(products.begin(),products.end(),p);

    if(it != products.end()) {
        if(!(*it)->isBought1()) {
            (*it)->setIsBought(true);
            notify(4,u);
            return 0;
        } else{
            std::cout << "Il prodotto selezionato è già stato comprato" << std::endl;
            return 1;
        }

    } else{
        std::cout << "Il prodotto selezionato non è presente nella lista " << this->name << std::endl;
        return 2;
    }
}



void ListaSpesa::subscribe(Observer* o) {
    observers.push_back(o);
}

void ListaSpesa::unsubscribe(Observer* o) {
    observers.remove(o);
}

void ListaSpesa::notify(int num, const std::string& u) {
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
        it->update(s);
    }
}

const std::string &ListaSpesa::getName() const {
    return name;
}

void ListaSpesa::setName(const std::string &n) {
    name = n;
}


int ListaSpesa::getSize() {
    return products.size();
}

const std::list<std::shared_ptr<Prodotto>> &ListaSpesa::getProducts() const {
    return products;
}




